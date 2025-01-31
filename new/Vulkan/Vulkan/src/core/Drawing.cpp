#include "Drawing.h"

namespace WMC {

    /* 寻找合适的队列 */
    extern QueueFamilyIndices findQueueFamilies(VkPhysicalDevice& device);

    /**
       * 现在，我们将开始处理 recordCommandBuffer 函数，该函数将我们想要执行的命令写入命令缓冲区。
       * 使用的 VkCommandBuffer 将作为参数传入，以及我们想要写入的当前交换链映像的索引。
       */
    void Drawing::recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex)
    {
        /* 如果命令缓冲区已经记录过一次，则调用 vkBeginCommandBuffer 将隐式重置它。以后无法将命令追加到缓冲区。 */
        VkCommandBufferBeginInfo beginInfo{};
        beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
        
        /**
        * flags 参数指定我们将如何使用命令缓冲区。以下值可用：
        *  VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT：命令缓冲区将在执行一次后立即重新录制。
        *  VK_COMMAND_BUFFER_USAGE_RENDER_PASS_CONTINUE_BIT：这是一个辅助命令缓冲区，将完全位于单个渲染通道中。
        *  VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT：命令缓冲区可以在等待执行时重新提交。
        */
        beginInfo.flags = 0; // Optional

        /* pInheritanceInfo 参数仅与辅助命令缓冲区相关。它指定要从调用主命令缓冲区继承的状态。*/
        beginInfo.pInheritanceInfo = nullptr; // Optional

        if (vkBeginCommandBuffer(commandBuffer, &beginInfo) != VK_SUCCESS)
        {
            throw std::runtime_error("failed to begin recording command buffer!");
        }

        // 绘制首先使用 vkCmdBeginRenderPass 开始渲染通道。渲染通道使用 VkRenderPassBeginInfo 结构中的一些参数进行配置。
        VkRenderPassBeginInfo renderPassInfo{};
        renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;

        /**
        * 第一个参数是渲染通道本身和要绑定的附件。我们为每个交换链图像创建了一个帧缓冲区，其中它被指定为颜色附件。
        * 因此，我们需要为要绘制的交换链图像绑定帧缓冲区。使用传入的 imageIndex 参数，我们可以为当前交换链图像选择正确的帧缓冲区。
        */
        renderPassInfo.renderPass = v_RenderPass;
        renderPassInfo.framebuffer = v_SwapChainFramebuffers[imageIndex];

        /**
        * 接下来的两个参数定义渲染区域的大小。渲染区域定义着色器加载和存储的位置。
        * 此区域之外的像素将具有未定义的值。它应与附件的大小匹配，以获得最佳性能。
        */
        renderPassInfo.renderArea.offset = { 0, 0 };
        renderPassInfo.renderArea.extent = v_SwapChainExtent;

        /**
        * 最后两个参数定义用于 VK_ATTACHMENT_LOAD_OP_CLEAR 的 clear 值，我们将其用作颜色附件的加载操作。
        * 已将透明颜色定义为具有 100% 不透明度的黑色。
        */
        std::array<VkClearValue, 2> clearValues{};
        clearValues[0].color = { {0.0f, 0.0f, 0.0f, 1.0f} };
        clearValues[1].depthStencil = { 1.0f, 0 };

        renderPassInfo.clearValueCount = static_cast<uint32_t>(clearValues.size());
        renderPassInfo.pClearValues = clearValues.data();

        /**
        * 每个命令的第一个参数始终是将命令录制到的命令缓冲区。 
        *  第二个参数指定我们刚刚提供的渲染通道的详细信息。 final 参数控制如何提供渲染通道中的绘制命令。 它可以具有以下两个值之一：
        *  VK_SUBPASS_CONTENTS_INLINE：渲染通道命令将嵌入到主命令缓冲区本身中，并且不会执行辅助命令缓冲区。
        *  VK_SUBPASS_CONTENTS_SECONDARY_COMMAND_BUFFERS：渲染通道命令将从辅助命令缓冲区执行。
        */
        vkCmdBeginRenderPass(commandBuffer, &renderPassInfo, VK_SUBPASS_CONTENTS_INLINE);

        vkCmdBindPipeline(commandBuffer, VK_PIPELINE_BIND_POINT_GRAPHICS, v_PipeLine);

        VkViewport viewport{};
        viewport.x = 0.0f;
        viewport.y = 0.0f;
        viewport.width = (float)(v_SwapChainExtent.width);
        viewport.height = (float) (v_SwapChainExtent.height);
        viewport.minDepth = 0.0f;
        viewport.maxDepth = 1.0f;
        vkCmdSetViewport(commandBuffer, 0, 1, &viewport);

        VkRect2D scissor{};
        scissor.offset = { 0, 0 };
        scissor.extent = v_SwapChainExtent;
        vkCmdSetScissor(commandBuffer, 0, 1, &scissor);

        /**
        * vkCmdBindVertexBuffers 函数用于将顶点缓冲区绑定到绑定，就像我们在上一章中设置的那样。除了命令缓冲区之外，
        * 前两个参数还指定了我们将为其指定顶点缓冲区的偏移量和绑定数。最后两个参数指定要绑定的顶点缓冲区数组，
        * 以及要从中开始读取顶点数据的字节偏移量。您还应更改对 vkCmdDraw 的调用，以传递缓冲区中的顶点数，而不是硬编码的数字 3。
        */
        VkBuffer vertexBuffers[] = { v_VertexBuffer };
        VkDeviceSize offsets[] = { 0 };
        vkCmdBindVertexBuffers(commandBuffer, 0, 1, vertexBuffers, offsets);

        vkCmdBindIndexBuffer(commandBuffer, v_IndexBuffer, 0, VK_INDEX_TYPE_UINT32);
        
        vkCmdBindDescriptorSets(commandBuffer, VK_PIPELINE_BIND_POINT_GRAPHICS, v_PipelineLayout, 0, 1, &v_DescriptorSets[currentFrame], 0, nullptr);
        vkCmdDrawIndexed(commandBuffer, static_cast<uint32_t>(indices.size()), 1, 0, 0, 0);

        /**
        * 实际的 vkCmdDraw 函数有点反常，但由于我们提前指定了所有信息，因此它非常简单。除了命令缓冲区之外，它还具有以下参数：
        *  vertexCount：即使我们没有顶点缓冲区，从技术上讲，我们仍然有 3 个顶点需要绘制。
        *  instanceCount：用于实例化渲染，如果您不这样做，请使用。1
        *  firstVertex：用作顶点缓冲区的偏移量，定义 的最小值。gl_VertexIndex
        *  firstInstance：用作实例化渲染的偏移量，定义 的最小值。gl_InstanceIndex
        */
        //vkCmdDraw(commandBuffer, static_cast<uint32_t>(indices.size()), 1, 0, 0, 0);

        vkCmdEndRenderPass(commandBuffer);

        if (vkEndCommandBuffer(commandBuffer) != VK_SUCCESS) {
            throw std::runtime_error("failed to record command buffer!");
        }
    }

	Drawing::Drawing(GraphicsPipeline& graphicsPipeline)
		: v_LDevice(graphicsPipeline.GetLogicalDevice())
	{
		v_SwapChainImageViews = graphicsPipeline.GetSwapChainImageViews();
        v_SwapChainExtent = graphicsPipeline.GetSwapChainExtent();
        v_PDevice = graphicsPipeline.GetPhysicalDevice();
        v_SwapChain = graphicsPipeline.GetSwapChain();
        v_GraphicsQueue = graphicsPipeline.GetGraphicsQueue();
        v_PresentQueue = graphicsPipeline.GetPresentQueue();
        v_RenderPass = graphicsPipeline.GetRenderPass();
        v_PipeLine = graphicsPipeline.GetPipeline();
        v_PipelineLayout = graphicsPipeline.GetPipelineLayout();
	}
	
	void Drawing::createFramebuffers()
	{
		v_SwapChainFramebuffers.resize(v_SwapChainImageViews.size());

        // 遍历图像视图并从中创建帧缓冲区
        for (size_t i = 0; i < v_SwapChainImageViews.size(); i++) {
            std::array<VkImageView, 3> attachments = {
               v_ColorImageView,
               v_DepthImageView,
               v_SwapChainImageViews[i]
            };

            VkFramebufferCreateInfo framebufferInfo{};
            framebufferInfo.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
            framebufferInfo.renderPass = v_RenderPass;

            /**
            * attachmentCount 和 pAttachments 参数指定应绑定到渲染通道 pAttachment 数组中相应附件描述的 VkImageView 对象。
            */
            framebufferInfo.attachmentCount = static_cast<uint32_t>(attachments.size());
            framebufferInfo.pAttachments = attachments.data();

            /**
            * width 和 height 参数一目了然，layers 是指图像数组中的层数。我们的交换链镜像是单张镜像，所以层数是 1。
            */
            framebufferInfo.width = v_SwapChainExtent.width;
            framebufferInfo.height = v_SwapChainExtent.height;
            framebufferInfo.layers = 1;

            if (vkCreateFramebuffer(v_LDevice, &framebufferInfo, nullptr, &v_SwapChainFramebuffers[i]) != VK_SUCCESS) 
            {
                throw std::runtime_error("failed to create framebuffer!");
            }
        }
	}

    void Drawing::createCommandPool()
    {
        QueueFamilyIndices queueFamilyIndices = findQueueFamilies(v_PDevice);

        VkCommandPoolCreateInfo poolInfo{};
        /**
        * 命令池有两个可能的标志：
        *  VK_COMMAND_POOL_CREATE_TRANSIENT_BIT：提示命令缓冲区经常使用新命令重新录制（可能会更改内存分配行为）
        *  VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT：允许单独重新录制命令缓冲区，如果没有此标志，它们都必须一起重置
        */
        poolInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
        poolInfo.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
        poolInfo.queueFamilyIndex = queueFamilyIndices.graphicsFamily.value();

        if (vkCreateCommandPool(v_LDevice, &poolInfo, nullptr, &v_CommandPool) != VK_SUCCESS)
        {
            throw std::runtime_error("failed to create command pool!");
        }
    }

    /**
    * 命令缓冲区通过 vkAllocateCommandBuffers 函数分配，该函数将 VkCommandBufferAllocateInfo 结构作为参数，
    * 用于指定要分配的命令池和缓冲区数量：
    */
    void Drawing::createCommandBuffers()
    {
        v_CommandBuffers.resize(MAX_FRAMES_IN_FLIGHT);

        VkCommandBufferAllocateInfo allocInfo{};
        allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
        allocInfo.commandPool = v_CommandPool;

        /**
        * level 参数指定分配的命令缓冲区是主命令缓冲区还是辅助命令缓冲区。
        *  VK_COMMAND_BUFFER_LEVEL_PRIMARY：可以提交到队列执行，但不能从其他命令缓冲区调用。
        *  VK_COMMAND_BUFFER_LEVEL_SECONDARY：不能直接提交，但可以从主命令缓冲区调用。
        */
        allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
        allocInfo.commandBufferCount = (uint32_t)v_CommandBuffers.size();

        if (vkAllocateCommandBuffers(v_LDevice, &allocInfo, v_CommandBuffers.data()) != VK_SUCCESS) 
        {
            throw std::runtime_error("failed to allocate command buffers!");
        }
    }

    void Drawing::createSyncObjects()
    {
        v_ImageAvailableSemaphores.resize(MAX_FRAMES_IN_FLIGHT);
        v_RenderFinishedSemaphores.resize(MAX_FRAMES_IN_FLIGHT);
        v_InFlightFences.resize(MAX_FRAMES_IN_FLIGHT);


        VkSemaphoreCreateInfo semaphoreInfo{};
        semaphoreInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;

        VkFenceCreateInfo fenceInfo{};
        fenceInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
        fenceInfo.flags = VK_FENCE_CREATE_SIGNALED_BIT;

        for (size_t i = 0; i < MAX_FRAMES_IN_FLIGHT; i++) {
            if (vkCreateSemaphore(v_LDevice, &semaphoreInfo, nullptr, &v_ImageAvailableSemaphores[i]) != VK_SUCCESS ||
                vkCreateSemaphore(v_LDevice, &semaphoreInfo, nullptr, &v_RenderFinishedSemaphores[i]) != VK_SUCCESS ||
                vkCreateFence(v_LDevice, &fenceInfo, nullptr, &v_InFlightFences[i]) != VK_SUCCESS)
            {
                throw std::runtime_error("failed to create semaphores!");
            }
        }
    }

    /////////////////////////////////////////////////////////////////////////////
    ///////// 在 Vulkan 中渲染帧常见的步骤 ///////////////////////////////////////
    ///////////// 等待上一帧完成 /////////////////////////////////////////////////
    ///////////// 从交换链获取图像 ///////////////////////////////////////////////
    ///////////// 录制一个命令缓冲区，用于将场景绘制到该图像上 ////////////////////
    ///////////// 提交录制的命令缓冲区 ///////////////////////////////////////////
    ///////////// 显示交换链图像 /////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////

    void Drawing::drawFrame(bool& framebufferResized)
    {
        /** 
        * 在帧的开头，我们希望等到前一帧完成，以便命令缓冲区和信号量可供使用。
        * 为此，我们调用 vkWaitForFences：
        */
        vkWaitForFences(v_LDevice, 1, &v_InFlightFences[currentFrame], VK_TRUE, UINT64_MAX);

        /**
        * vkAcquireNextImageKHR 的前两个参数是逻辑设备和我们希望从中获取图像的交换链。
        *  第三个参数指定图像可用的超时时间（以纳秒为单位）。使用 64 位无符号整数的最大值意味着我们实际上禁用了超时。
        *  接下来的两个参数指定在演示引擎使用完图像时要发出信号的同步对象。
        *  这就是我们可以开始绘制它的时间点。可以指定信号量、栅栏或两者。
        *  我们将在这里使用我们的 imageAvailableSemaphore 来实现这个目的。
        *  最后一个参数指定一个变量，用于输出已变为可用的交换链映像的索引。
        *  该索引引用 swapChainImages 数组中的 VkImage。我们将使用该索引来选择 VkFrameBuffer。
        */
        uint32_t imageIndex;
        VkResult result = vkAcquireNextImageKHR(v_LDevice, v_SwapChain, UINT64_MAX, v_ImageAvailableSemaphores[currentFrame],
            VK_NULL_HANDLE, &imageIndex);

        if (result == VK_ERROR_OUT_OF_DATE_KHR)
        {
            recreateSwapChain();
            return;
        }
        else if (result != VK_SUCCESS && result != VK_SUBOPTIMAL_KHR)
        {
            throw std::runtime_error("failed to acquire swap chain image!");
        }

        updateUniformBuffer(currentFrame);


        // 我们需要通过调用手动将栅栏重置为 unsignaled 状态：
        vkResetFences(v_LDevice, 1, &v_InFlightFences[currentFrame]);

        /**
        * 使用 imageIndex 指定要使用的交换链映像，我们现在可以记录命令缓冲区。
        * 首先，我们在命令缓冲区上调用 vkResetCommandBuffer，以确保它能够被记录。
        * vkResetCommandBuffer 的第二个参数是 VkCommandBufferResetFlagBits 标志。由于我们不想做任何特殊的事情，因此将其保留为 0。
        */
        vkResetCommandBuffer(v_CommandBuffers[currentFrame], 0);

        recordCommandBuffer(v_CommandBuffers[currentFrame], imageIndex);

        VkSubmitInfo submitInfo{};
        submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;

        /**
        * 前三个参数指定在执行开始之前要等待哪些信号量，以及在管道的哪个阶段等待。
        *  我们希望等待将颜色写入图像，直到它可用，因此我们指定了写入颜色附件的图形管道的阶段。
        *  这意味着从理论上讲，当图像尚不可用时，实现已经可以开始执行我们的顶点着色器等。
        *  waitStages 数组中的每个条目都对应于 pWaitSemaphores 中具有相同索引的信号量。
        */
        VkSemaphore waitSemaphores[] = { v_ImageAvailableSemaphores[currentFrame]};
        VkPipelineStageFlags waitStages[] = { VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT };
        submitInfo.waitSemaphoreCount = 1;
        submitInfo.pWaitSemaphores = waitSemaphores;
        submitInfo.pWaitDstStageMask = waitStages;

        // 指定要实际提交以供执行的命令缓冲区
        submitInfo.commandBufferCount = 1;
        submitInfo.pCommandBuffers = &v_CommandBuffers[currentFrame];

        /* signalSemaphoreCount 和 pSignalSemaphores 参数指定在命令缓冲区完成执行后要向哪些信号量发出信号 */
        VkSemaphore signalSemaphores[] = { v_RenderFinishedSemaphores[currentFrame]};
        submitInfo.signalSemaphoreCount = 1;
        submitInfo.pSignalSemaphores = signalSemaphores;

        if (vkQueueSubmit(v_GraphicsQueue, 1, &submitInfo, v_InFlightFences[currentFrame]) != VK_SUCCESS)
        {
            throw std::runtime_error("failed to submit draw command buffer!");
        }

        VkPresentInfoKHR presentInfo{};
        presentInfo.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;

        /**
        * 前两个参数指定在显示之前要等待哪些信号量，就像 VkSubmitInfo 一样。
        * 由于我们想等待命令缓冲区完成执行，因此绘制了我们的三角形，
        * 因此我们获取将要发出信号的信号量并等待它们，因此我们使用 signalSemaphores。
        */
        presentInfo.waitSemaphoreCount = 1;
        presentInfo.pWaitSemaphores = signalSemaphores;

        VkSwapchainKHR swapChains[] = { v_SwapChain };

        // 两个参数指定要向其显示图像的交换链以及每个交换链的图像索引
        presentInfo.swapchainCount = 1;
        presentInfo.pSwapchains = swapChains;

        presentInfo.pImageIndices = &imageIndex;
        presentInfo.pResults = nullptr; // Optional

        /**
        * 现在我们只需要弄清楚何时需要重新创建交换链，并调用我们新的 recreateSwapChain 函数。
        * 幸运的是，Vulkan 通常会告诉我们，在演示期间，交换链不再足够。
        * vkAcquireNextImageKHR 和 vkQueuePresentKHR 函数可以返回以下特殊值来表示这一点。
        * 
        *  VK_ERROR_OUT_OF_DATE_KHR：交换链已与表面不兼容，无法再用于渲染。 通常发生在调整窗口大小之后。
        *  VK_SUBOPTIMAL_KHR：交换链仍可用于成功呈现到表面，但表面属性不再完全匹配。
        */
        result = vkQueuePresentKHR(v_PresentQueue, &presentInfo);

        if (result == VK_ERROR_OUT_OF_DATE_KHR || result == VK_SUBOPTIMAL_KHR || framebufferResized) 
        {
            framebufferResized = false;
            recreateSwapChain();
        }
        else if (result != VK_SUCCESS) 
        {
            throw std::runtime_error("failed to present swap chain image!");
        }

        currentFrame = (currentFrame + 1) % MAX_FRAMES_IN_FLIGHT;
    }

    void Drawing::recreateSwapChain()
    {
        int width = 0, height = 0;
        glfwGetFramebufferSize(v_Window, &width, &height);
        while (width == 0 || height == 0)
        {
            glfwGetFramebufferSize(v_Window, &width, &height);
            glfwWaitEvents();
        }

        vkDeviceWaitIdle(v_LDevice);

        v_Device->cleanupSwapChain(v_SwapChainFramebuffers);

        v_Device->createSwapChain();
        v_Device->createImageViews();
        v_Texture->createColorResources();
        v_Texture->createDepthResources();
        createFramebuffers();
    }

    void Drawing::updateUniformBuffer(uint32_t currentImage)
    {
        static auto startTime = std::chrono::high_resolution_clock::now();

        auto currentTime = std::chrono::high_resolution_clock::now();
        float time = std::chrono::duration<float, std::chrono::seconds::period>(currentTime - startTime).count();

        UniformBufferObject ubo{};
        ubo.model = glm::rotate(glm::mat4(1.0f), time * glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        ubo.view = glm::lookAt(glm::vec3(2.0f, 2.0f, 2.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        ubo.proj = glm::perspective(glm::radians(45.0f), (float)v_SwapChainExtent.width / (float)v_SwapChainExtent.height, 0.1f, 10.0f);

        ubo.proj[1][1] *= -1;
        memcpy(v_UniformBuffersMapped[currentImage], &ubo, sizeof(ubo));
    }

}