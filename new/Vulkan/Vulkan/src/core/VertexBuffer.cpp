#include "VertexBuffer.h"

namespace WMC {

	/**
	* 显卡可以提供不同类型的内存来分配。每种类型的内存在允许的操作和性能特征方面都有所不同。
	* 我们需要将缓冲区的要求和我们自己的应用程序要求结合起来，以找到合适的内存类型来使用。
	*/
	uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties, VkPhysicalDevice physicalDevice)
	{
		/**
		* VkPhysicalDeviceMemoryProperties 结构有两个数组：memoryTypes 和 memoryHeaps。
		* 内存堆是不同的内存资源，例如专用 VRAM 和 RAM 中的交换空间，以便在 VRAM 耗尽时使用。
		* 这些堆中存在不同类型的内存。现在，我们只关注内存的类型，而不关心它来自的堆，但您可以想象这会影响性能。
		*/
		VkPhysicalDeviceMemoryProperties memProperties;
		vkGetPhysicalDeviceMemoryProperties(physicalDevice, &memProperties);

		/** 
		* 找到适合缓冲区本身的内存类型
		* typeFilter 参数将用于指定合适的内存类型的位字段。意味着可以通过简单地迭代并检查相应的位是否设置为 1 来找到合适内存类型的索引。
		* 但是，不应该仅对适合顶点缓冲区的内存类型感兴趣。还需要能够的顶点数据写入该内存。memoryTypes 数组由 VkMemoryType 结构组成，
		* 这些结构指定每种内存类型的堆和属性。这些属性定义了内存的特殊功能，例如能够映射它，以便我们可以从 CPU 写入它。此属性用
		*/
		for (uint32_t i = 0; i < memProperties.memoryTypeCount; i++)
		{
			/**
			* 我们可能有多个 desired property，因此我们应该检查按位 AND 的结果是否不仅仅是非零，而是等于 desired properties 位字段。
			* 如果存在适合缓冲区的内存类型，并且它还具有我们需要的所有属性，那么我们返回它的索引，否则我们将抛出异常。
			*/
			if ((typeFilter & (1 << i)) && (memProperties.memoryTypes[i].propertyFlags & properties) == properties)
			{
				return i;
			}
		}

		throw std::runtime_error("failed to find suitable memory type!");
	}

	void VertexBuffer::createVertexBuffer()
	{
		/* 指定缓冲区的大小（以字节为单位） */
		 VkDeviceSize bufferSize = sizeof(v_Vertices[0]) * v_Vertices.size();

		/**
		* 现在，我们将使用带有 stagingBufferMemory 的新 stagingBuffer 来映射和复制顶点数据。
		* 将使用两个新的缓冲区使用标志：
		*  VK_BUFFER_USAGE_TRANSFER_SRC_BIT：缓冲区可用作内存传输操作中的源。
		*  VK_BUFFER_USAGE_TRANSFER_DST_BIT：缓冲区可用作内存传输操作中的目标。
		*/
		VkBuffer stagingBuffer;
		VkDeviceMemory stagingBufferMemory;
		createBuffer(bufferSize, VK_BUFFER_USAGE_TRANSFER_SRC_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT |
					 VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, stagingBuffer, stagingBufferMemory);

		/**
		* 将顶点数据复制到缓冲区中
		* 此函数允许我们访问由偏移量和大小定义的指定内存资源的区域。这里的 offset 和 size 分别为 0 和 bufferInfo.size。
		* 也可以指定特殊值 VK_WHOLE_SIZE 来映射所有内存。倒数第二个参数可用于指定标志，但当前 API 中尚无任何可用的标志。
		* 它必须设置为值 0。最后一个参数指定指向 Map 内存的指针的输出。
		*/
		void* data;
		vkMapMemory(v_LDevice, stagingBufferMemory, 0, bufferSize, 0, &data);

		/**
		* 现在，您只需将顶点数据 memcpy 到映射的内存，然后使用 vkUnmapMemory 再次取消映射。
		* 遗憾的是，驱动程序可能不会立即将数据复制到缓冲区内存中，例如由于缓存。
		* 对缓冲区的写入也可能在 Map 内存中尚不可见。
		*  有两种方法可以处理该问题：
		*  使用主机一致的内存堆，用VK_MEMORY_PROPERTY_HOST_COHERENT_BIT
		*  vkFlushMappedMemoryRanges，并在从映射内存读取之前调用 vkInvalidateMappedMemoryRanges
		*/
		memcpy(data, v_Vertices.data(), (size_t)bufferSize);
		vkUnmapMemory(v_LDevice, stagingBufferMemory);

		/**
		* vertexBuffer 现在从设备本地的内存类型分配，这通常意味着我们无法使用 vkMapMemory。
		* 但是，我们可以将数据从 stagingBuffer 复制到 vertexBuffer。
		* 我们必须通过指定 stagingBuffer 的传输源标志和 vertexBuffer 的传输目标标志以及顶点缓冲区使用标志来表明我们打算这样做。
		*/
		createBuffer(bufferSize, VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_VERTEX_BUFFER_BIT,
					VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, v_VertexBuffer, v_VertexBufferMemory);
		copyBuffer(stagingBuffer, v_VertexBuffer, bufferSize);

		vkDestroyBuffer(v_LDevice, stagingBuffer, nullptr);
		vkFreeMemory(v_LDevice, stagingBufferMemory, nullptr);
	}

	void VertexBuffer::createIndexBuffer()
	{
		VkDeviceSize bufferSize = sizeof(v_Indices[0]) * v_Indices.size();

		VkBuffer stagingBuffer;
		VkDeviceMemory stagingBufferMemory;
		createBuffer(bufferSize, VK_BUFFER_USAGE_TRANSFER_SRC_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT |
					VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, stagingBuffer, stagingBufferMemory);

		void* data;
		vkMapMemory(v_LDevice, stagingBufferMemory, 0, bufferSize, 0, &data);
		memcpy(data, v_Indices.data(), (size_t)bufferSize);
		vkUnmapMemory(v_LDevice, stagingBufferMemory);

		createBuffer(bufferSize, VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_INDEX_BUFFER_BIT,
					VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, v_IndexBuffer, v_IndexBufferMemory);

		copyBuffer(stagingBuffer, v_IndexBuffer, bufferSize);

		vkDestroyBuffer(v_LDevice, stagingBuffer, nullptr);
		vkFreeMemory(v_LDevice, stagingBufferMemory, nullptr);
	}

	void VertexBuffer::createDescriptorSetLayout()
	{
		/**
		* 前两个字段指定着色器中使用的绑定和描述符的类型，即统一缓冲区对象。
		* 着色器变量可以表示统一缓冲区对象的数组，descriptorCount 指定数组中的值数。
		* 例如，这可用于为骨骼动画的骨架中的每个骨骼指定变换。
		* 我们的 MVP 转换位于单个统一缓冲区对象中，因此我们使用 descriptorCount 1。
		*/
		VkDescriptorSetLayoutBinding uboLayoutBinding{};
		uboLayoutBinding.binding = 0;
		uboLayoutBinding.descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
		uboLayoutBinding.descriptorCount = 1;

		/**
		* 我们还需要指定要在哪个着色器阶段引用描述符。
		* stageFlags 字段可以是 VkShaderStageFlagBits 值或值 VK_SHADER_STAGE_ALL_GRAPHICS 的组合。
		*/
		uboLayoutBinding.stageFlags = VK_SHADER_STAGE_VERTEX_BIT;
		/**
		* pImmutableSamplers 字段仅与图像采样相关的描述符相关，我们稍后将对此进行介绍。您可以将其保留为默认值。
		*/
		uboLayoutBinding.pImmutableSamplers = nullptr; // Optional

		/**
		* 确保设置 stageFlags 以指示我们打算在片段着色器中使用组合的图像采样器描述符。这就是确定片段颜色的地方。
		* 可以在顶点着色器中使用纹理采样，例如，通过高度贴图动态变形顶点网格。
		*/
		VkDescriptorSetLayoutBinding samplerLayoutBinding{};
		samplerLayoutBinding.binding = 1;
		samplerLayoutBinding.descriptorCount = 1;
		samplerLayoutBinding.descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
		samplerLayoutBinding.pImmutableSamplers = nullptr;
		samplerLayoutBinding.stageFlags = VK_SHADER_STAGE_FRAGMENT_BIT;

		std::array<VkDescriptorSetLayoutBinding, 2> bindings = { uboLayoutBinding, samplerLayoutBinding };

		/**
		* 然后，我们可以使用 vkCreateDescriptorSetLayout 创建它。
		* 函数接受带有绑定数组的简单 VkDescriptorSetLayoutCreateInfo：
		*/
		VkDescriptorSetLayoutCreateInfo layoutInfo{};
		layoutInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
		layoutInfo.bindingCount = static_cast<uint32_t>(bindings.size());
		layoutInfo.pBindings = bindings.data();

		if (vkCreateDescriptorSetLayout(v_LDevice, &layoutInfo, nullptr, &v_DescriptorSetLayout) != VK_SUCCESS) 
		{
			throw std::runtime_error("failed to create descriptor set layout!");
		}
	}

	void VertexBuffer::createUniformBuffers()
	{
		VkDeviceSize bufferSize = sizeof(UniformBufferObject);

		v_UniformBuffers.resize(MAX_FRAMES_IN_FLIGHT);
		v_UniformBuffersMemory.resize(MAX_FRAMES_IN_FLIGHT);
		v_UniformBuffersMapped.resize(MAX_FRAMES_IN_FLIGHT);

		for (size_t i = 0; i < MAX_FRAMES_IN_FLIGHT; i++) 
		{
			createBuffer(bufferSize, VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, v_UniformBuffers[i], v_UniformBuffersMemory[i]);

			vkMapMemory(v_LDevice, v_UniformBuffersMemory[i], 0, bufferSize, 0, &v_UniformBuffersMapped[i]);
		}
	}

	void VertexBuffer::createDescriptorPool()
	{
		/**
		* 我们还必须创建一个更大的描述符池，通过向 VkDescriptorPoolCreateInfo 添加另一个 VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER 类型的
		* VkPoolSize 来为组合图像采样器的分配腾出空间。转到 createDescriptorPool 函数并对其进行修改，
		* 以包含此描述符的 VkDescriptorPoolSize：
		* 
		* 描述符池不足是验证层无法捕获的问题的一个很好的示例：从 Vulkan 1.1 开始，如果池不够大，
		* vkAllocateDescriptorSets 可能会失败并显示错误代码 VK_ERROR_POOL_OUT_OF_MEMORY，但驱动程序也可能尝试在内部解决问题。
		* 这意味着有时 （取决于硬件、池大小和分配大小） 驱动程序会让我们摆脱超出描述符池限制的分配。
		* 其他时候，vkAllocateDescriptorSets 将失败并返回 VK_ERROR_POOL_OUT_OF_MEMORY。
		* 如果分配在某些计算机上成功，但在其他计算机上失败，则这可能特别令人沮丧。
		*/
		std::array<VkDescriptorPoolSize, 2> poolSizes{};
		poolSizes[0].type = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
		poolSizes[0].descriptorCount = static_cast<uint32_t>(MAX_FRAMES_IN_FLIGHT);
		poolSizes[1].type = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
		poolSizes[1].descriptorCount = static_cast<uint32_t>(MAX_FRAMES_IN_FLIGHT);

		// 将为每个帧分配其中一个描述符
		VkDescriptorPoolCreateInfo poolInfo{};
		poolInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
		// 可用的单个描述符的最大数量之外
		poolInfo.poolSizeCount = static_cast<uint32_t>(poolSizes.size());
		poolInfo.pPoolSizes = poolSizes.data();

		// 指定可以分配的描述符集的最大数量
		poolInfo.maxSets = static_cast<uint32_t>(MAX_FRAMES_IN_FLIGHT);

		if (vkCreateDescriptorPool(v_LDevice, &poolInfo, nullptr, &v_DescriptorPool) != VK_SUCCESS) 
		{
			throw std::runtime_error("failed to create descriptor pool!");
		}
	}

	void VertexBuffer::createDescriptorSets()
	{
		// 指定要从中分配的描述符池、要分配的描述符集数量以及它们所基于的描述符集布局
		std::vector<VkDescriptorSetLayout> layouts(MAX_FRAMES_IN_FLIGHT, v_DescriptorSetLayout);
		VkDescriptorSetAllocateInfo allocInfo{};
		allocInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
		allocInfo.descriptorPool = v_DescriptorPool;
		allocInfo.descriptorSetCount = static_cast<uint32_t>(MAX_FRAMES_IN_FLIGHT);
		allocInfo.pSetLayouts = layouts.data();

		v_DescriptorSets.resize(MAX_FRAMES_IN_FLIGHT);
		if (vkAllocateDescriptorSets(v_LDevice, &allocInfo, v_DescriptorSets.data()) != VK_SUCCESS) 
		{
			throw std::runtime_error("failed to allocate descriptor sets!");
		}

		for (size_t i = 0; i < MAX_FRAMES_IN_FLIGHT; i++) 
		{
			VkDescriptorBufferInfo bufferInfo{};
			bufferInfo.buffer = v_UniformBuffers[i];
			bufferInfo.offset = 0;
			bufferInfo.range = sizeof(UniformBufferObject);

			VkDescriptorImageInfo imageInfo{};
			imageInfo.imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
			imageInfo.imageView = v_TextureImageView;
			imageInfo.sampler = v_TextureSampler;

			std::array<VkWriteDescriptorSet, 2> descriptorWrites{};
			descriptorWrites[0].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
			descriptorWrites[0].dstSet = v_DescriptorSets[i];
			descriptorWrites[0].dstBinding = 0;
			descriptorWrites[0].dstArrayElement = 0;

			/**
			* 我们需要再次指定描述符的类型。可以一次更新数组中的多个描述符，从索引 dstArrayElement 开始。
			* descriptorCount 字段指定要更新的数组元素数。
			*/
			descriptorWrites[0].descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
			descriptorWrites[0].descriptorCount = 1;
			descriptorWrites[0].pBufferInfo = &bufferInfo;

			descriptorWrites[1].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
			descriptorWrites[1].dstSet = v_DescriptorSets[i];
			descriptorWrites[1].dstBinding = 1;
			descriptorWrites[1].dstArrayElement = 0;
			descriptorWrites[1].descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
			descriptorWrites[1].descriptorCount = 1;
			descriptorWrites[1].pImageInfo = &imageInfo;

			vkUpdateDescriptorSets(v_LDevice, static_cast<uint32_t>(descriptorWrites.size()), descriptorWrites.data(), 0, nullptr);
		}
	}

	void VertexBuffer::createBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory)
	{
		VkBufferCreateInfo bufferInfo{};
		bufferInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
		bufferInfo.size = size;
		bufferInfo.usage = usage;
		bufferInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;

		if (vkCreateBuffer(v_LDevice, &bufferInfo, nullptr, &buffer) != VK_SUCCESS) {
			throw std::runtime_error("failed to create buffer!");
		}

		VkMemoryRequirements memRequirements;
		vkGetBufferMemoryRequirements(v_LDevice, buffer, &memRequirements);

		VkMemoryAllocateInfo allocInfo{};
		allocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
		allocInfo.allocationSize = memRequirements.size;
		allocInfo.memoryTypeIndex = findMemoryType(memRequirements.memoryTypeBits, properties, v_PDevice);

		if (vkAllocateMemory(v_LDevice, &allocInfo, nullptr, &bufferMemory) != VK_SUCCESS) 
		{
			throw std::runtime_error("failed to allocate buffer memory!");
		}

		vkBindBufferMemory(v_LDevice, buffer, bufferMemory, 0);
	}

	void VertexBuffer::copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size) 
	{
		VkCommandBuffer commandBuffer = beginSingleTimeCommands();

		VkBufferCopy copyRegion{};
		copyRegion.size = size;
		vkCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, 1, &copyRegion);

		endSingleTimeCommands(commandBuffer);
	}

	/**
	* 执行布局过渡的最常见方法之一是使用图像内存屏障。像这样的管道屏障通常用于同步对资源的访问，
	* 例如确保在从缓冲区读取之前完成对缓冲区的写入，但它也可用于在使用 VK_SHARING_MODE_EXCLUSIVE时转换图像布局和转移队列系列所有权。
	* 有一个等效的缓冲区内存屏障可以为缓冲区执行此操作。
	*/
	void VertexBuffer::transitionImageLayout(VkImage* image, VkFormat format, VkImageLayout oldLayout, VkImageLayout newLayout, uint32_t mipLevels)
	{
		VkCommandBuffer commandBuffer = beginSingleTimeCommands();

		VkImageMemoryBarrier barrier{};
		barrier.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;

		// 前两个字段指定布局过渡。如果您不关心图像的现有内容，则可以将 VK_IMAGE_LAYOUT_UNDEFINED 用作 oldLayout。
		barrier.oldLayout = oldLayout;
		barrier.newLayout = newLayout;

		/**
		* 如果您使用屏障来转移队列系列所有权，那么这两个字段应该是队列系列的索引。
		* 如果您不想这样做，则必须将它们设置为 VK_QUEUE_FAMILY_IGNORED（不是默认值！
		*/
		barrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
		barrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;

		// image 和 subresourceRange 指定受影响的图像和图像的特定部分。我们的图像不是数组，也没有 mipmap 级别，因此只指定了一个级别和层。
		barrier.image = *image;
		barrier.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
		barrier.subresourceRange.baseMipLevel = 0;
		barrier.subresourceRange.levelCount = mipLevels;
		barrier.subresourceRange.baseArrayLayer = 0;
		barrier.subresourceRange.layerCount = 1;

		/**
		* 屏障主要用于同步目的，因此您必须指定涉及资源的哪些类型的操作必须在屏障之前发生，以及涉及资源的哪些操作必须在屏障上等待。
		* 尽管我们已经使用 vkQueueWaitIdle 进行了手动同步，但我们也需要这样做。
		* 正确的值取决于旧布局和新布局，因此，一旦我们确定了要使用的过渡，我们就会回到这个话题。
		*/
		barrier.srcAccessMask = 0; // TODO
		barrier.dstAccessMask = 0; // TODO

		/**
		* 如上表中所示，传输写入必须发生在管道传输阶段。由于写入不必等待任何内容，
		* 因此您可以为 pre-barrier 操作指定一个空的访问掩码和尽可能早的 pipeline stage VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT。
		* 应该注意的是，VK_PIPELINE_STAGE_TRANSFER_BIT 并不是图形和计算管道中的真实阶段。它更像是一个发生转移的伪阶段。
		* 请参阅 文档 以了解更多信息和伪阶段的其他示例。
		* 
		* 图像将写入同一管道阶段，随后由片段着色器读取，这就是我们在片段着色器管道阶段指定着色器读取访问权限的原因。
		* 如果我们将来需要做更多的转换，那么我们将扩展函数。应用程序现在应该成功运行，当然还没有视觉变化。
		* 
		* 需要注意的一点是，命令缓冲区提交会导致在开始时隐式VK_ACCESS_HOST_WRITE_BIT同步。
		* 由于 transitionImageLayout 函数仅使用单个命令执行命令缓冲区，因此，如果您在布局过渡中需要VK_ACCESS_HOST_WRITE_BIT依赖项，
		* 则可以使用此隐式同步并将 srcAccessMask 设置为 0。是否要明确说明取决于您，但我个人不喜欢依赖这些类似 OpenGL 的“隐藏”操作。
		* 
		* 实际上，有一种特殊类型的图像布局支持所有操作，VK_IMAGE_LAYOUT_GENERAL。当然，它的问题在于它不一定为任何操作提供最佳性能。
		* 在某些特殊情况下，例如将图像用作输入和输出，或者在图像离开预初始化布局后读取图像时，它是必需的。
		* 
		* 到目前为止，提交命令的所有帮助程序函数都已设置为通过等待队列变为空闲来同步执行。
		* 对于实际应用程序，建议将这些操作合并到单个命令缓冲区中，并异步执行它们以提高吞吐量，尤其是 createTextureImage 函数中的过渡和复制。
		* 尝试通过创建帮助程序函数将命令记录到的 setupCommandBuffer 来试验这一点，并添加 flushSetupCommands 来执行到目前为止已记录的命令。
		* 最好在纹理映射工作后执行此操作，以检查纹理资源是否仍设置正确。
		*/
		VkPipelineStageFlags sourceStage;
		VkPipelineStageFlags destinationStage;

		if (oldLayout == VK_IMAGE_LAYOUT_UNDEFINED && newLayout == VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL) 
		{
			barrier.srcAccessMask = 0;
			barrier.dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;

			sourceStage = VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT;
			destinationStage = VK_PIPELINE_STAGE_TRANSFER_BIT;
		}
		else if (oldLayout == VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL && newLayout == VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL) 
		{
			barrier.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
			barrier.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;

			sourceStage = VK_PIPELINE_STAGE_TRANSFER_BIT;
			destinationStage = VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT;
		}
		else if (oldLayout == VK_IMAGE_LAYOUT_UNDEFINED && newLayout == VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL) 
		{
			barrier.srcAccessMask = 0;
			barrier.dstAccessMask = VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_READ_BIT | VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT;

			sourceStage = VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT;
			destinationStage = VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT;
		}
		else
		{
			throw std::invalid_argument("unsupported layout transition!");
		}

		/*
		* 所有类型的管道障碍都使用相同的函数提交。命令缓冲区后的第一个参数指定操作发生在 barrier 之前应发生的管道阶段。
		* 第二个参数指定操作将在 barrier 上等待的管道阶段。允许您在屏障之前和之后指定的管道阶段取决于您在屏障之前和之后如何使用资源。
		* 允许的值列在规范的此表中。例如，如果要在屏障之后从 uniform 读取数据，
		* 则可以指定 VK_ACCESS_UNIFORM_READ_BIT 的用法以及将从 uniform 中读取的最早着色器作为管道阶段，
		* 例如 VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT。为此类使用指定非着色器管道阶段没有意义，并且当您指定与使用类型不匹配的管道阶段时，
		* 验证层将向您发出警告。
		* 
		* 第三个参数为 0 或 VK_DEPENDENCY_BY_REGION_BIT。后者将屏障转换为每个区域的条件。
		* 这意味着，例如，允许 implementation 已经开始从到目前为止编写的资源部分开始读取。
		* 
		* 最后三对参数引用三种可用类型的管道屏障数组：内存屏障、缓冲区内存屏障和图像内存屏障，就像我们在这里使用的一样。
		* 请注意，我们还没有使用 VkFormat 参数，但我们将该参数用于深度缓冲区章节中的特殊过渡。
		*/
		vkCmdPipelineBarrier(
			commandBuffer,
			sourceStage, destinationStage,
			0,
			0, nullptr,
			0, nullptr,
			1, &barrier
		);

		endSingleTimeCommands(commandBuffer);
	}


	VkCommandBuffer VertexBuffer::beginSingleTimeCommands() 
	{
		VkCommandBufferAllocateInfo allocInfo{};
		allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
		allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
		allocInfo.commandPool = v_CommandPool;
		allocInfo.commandBufferCount = 1;

		VkCommandBuffer commandBuffer;
		vkAllocateCommandBuffers(v_LDevice, &allocInfo, &commandBuffer);

		VkCommandBufferBeginInfo beginInfo{};
		beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
		beginInfo.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;

		vkBeginCommandBuffer(commandBuffer, &beginInfo);

		return commandBuffer;
	}

	void VertexBuffer::endSingleTimeCommands(VkCommandBuffer commandBuffer) {
		vkEndCommandBuffer(commandBuffer);

		VkSubmitInfo submitInfo{};
		submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
		submitInfo.commandBufferCount = 1;
		submitInfo.pCommandBuffers = &commandBuffer;

		vkQueueSubmit(v_GraphicsQueue, 1, &submitInfo, VK_NULL_HANDLE);
		vkQueueWaitIdle(v_GraphicsQueue);

		vkFreeCommandBuffers(v_LDevice, v_CommandPool, 1, &commandBuffer);
	}

	void VertexBuffer::copyBufferToImage(VkBuffer buffer, VkImage image, uint32_t width, uint32_t height)
	{
		VkCommandBuffer commandBuffer = beginSingleTimeCommands();

		/**
		* 这些字段中的大多数都是不言自明的。bufferOffset 指定像素值开始的缓冲区中的字节偏移量。
		* bufferRowLength 和 bufferImageHeight 字段指定像素在内存中的布局方式。例如，您可以在图像的行之间有一些填充字节。
		* 为两者指定 0 表示像素只是像我们一样紧密排列。imageSubresource、imageOffset 和 imageExtent 字段指示要将像素复制到图像的哪个部分。
		*/
		VkBufferImageCopy region{};
		region.bufferOffset = 0;
		region.bufferRowLength = 0;
		region.bufferImageHeight = 0;

		region.imageSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
		region.imageSubresource.mipLevel = 0;
		region.imageSubresource.baseArrayLayer = 0;
		region.imageSubresource.layerCount = 1;

		region.imageOffset = { 0, 0, 0 };
		region.imageExtent = {
			width,
			height,
			1
		};

		/**
		* 第四个参数指示图像当前使用的布局。我在这里假设图像已经过渡到最适合将像素复制到的布局。
		* 现在，我们只将一个像素块复制到整个图像，但可以指定一个 VkBufferImageCopy 数组，通过一次操作从该缓冲区向图像执行许多不同的复制。
		*/
		vkCmdCopyBufferToImage(
			commandBuffer,
			buffer,
			image,
			VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
			1,
			&region
		);

		endSingleTimeCommands(commandBuffer);
	}

	void VertexBuffer::generateMipmaps(VkImage image, VkFormat imageFormat, int32_t texWidth, int32_t texHeight, uint32_t mipLevels)
	{
		// Check if image format supports linear blitting
		VkFormatProperties formatProperties;
		vkGetPhysicalDeviceFormatProperties(v_PDevice, imageFormat, &formatProperties);

		if (!(formatProperties.optimalTilingFeatures & VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT)) 
		{
			throw std::runtime_error("texture image format does not support linear blitting!");
		}

		VkCommandBuffer commandBuffer = beginSingleTimeCommands();

		VkImageMemoryBarrier barrier{};
		barrier.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
		barrier.image = image;
		barrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
		barrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
		barrier.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
		barrier.subresourceRange.baseArrayLayer = 0;
		barrier.subresourceRange.layerCount = 1;
		barrier.subresourceRange.levelCount = 1;

		int32_t mipWidth = texWidth;
		int32_t mipHeight = texHeight;

		for (uint32_t i = 1; i < mipLevels; i++)
		{
			barrier.subresourceRange.baseMipLevel = i - 1;
			barrier.oldLayout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
			barrier.newLayout = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
			barrier.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
			barrier.dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;

			vkCmdPipelineBarrier(commandBuffer,
				VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0,
				0, nullptr,
				0, nullptr,
				1, &barrier);

			VkImageBlit blit{};
			blit.srcOffsets[0] = { 0, 0, 0 };
			blit.srcOffsets[1] = { mipWidth, mipHeight, 1 };
			blit.srcSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
			blit.srcSubresource.mipLevel = i - 1;
			blit.srcSubresource.baseArrayLayer = 0;
			blit.srcSubresource.layerCount = 1;
			blit.dstOffsets[0] = { 0, 0, 0 };
			blit.dstOffsets[1] = { mipWidth > 1 ? mipWidth / 2 : 1, mipHeight > 1 ? mipHeight / 2 : 1, 1 };
			blit.dstSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
			blit.dstSubresource.mipLevel = i;
			blit.dstSubresource.baseArrayLayer = 0;
			blit.dstSubresource.layerCount = 1;

			vkCmdBlitImage(commandBuffer,
				image, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
				image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
				1, &blit,
				VK_FILTER_LINEAR);

			barrier.oldLayout = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
			barrier.newLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
			barrier.srcAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
			barrier.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;

			vkCmdPipelineBarrier(commandBuffer,
				VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, 0,
				0, nullptr,
				0, nullptr,
				1, &barrier);

			if (mipWidth > 1) mipWidth /= 2;
			if (mipHeight > 1) mipHeight /= 2;
		}

		barrier.subresourceRange.baseMipLevel = mipLevels - 1;
		barrier.oldLayout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
		barrier.newLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
		barrier.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
		barrier.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;

		vkCmdPipelineBarrier(commandBuffer,
			VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, 0,
			0, nullptr,
			0, nullptr,
			1, &barrier);

		endSingleTimeCommands(commandBuffer);
	}

}