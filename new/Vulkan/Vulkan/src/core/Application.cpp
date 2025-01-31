#include "Application.h"

namespace WMC{

	//Application* application = nullptr;

	static void framebufferResizeCallback(GLFWwindow* window, int width, int height)
	{
		auto app = reinterpret_cast<Application*>(glfwGetWindowUserPointer(window));
		app->framebufferResized = true;
	}

	Application::Application()
	{
		glfwInit();

		// 不使用 OpenGL 创建上下文
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

		// 暂时禁用窗口大小调整
		//glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
		
		// 创建实际窗口
		v_Window = glfwCreateWindow(props.Width, props.Height, props.Title, nullptr, nullptr);

		glfwSetWindowUserPointer(v_Window, this);
		glfwSetFramebufferSizeCallback(v_Window, [](GLFWwindow* window, int width, int height)
			{
				auto app = reinterpret_cast<Application*>(glfwGetWindowUserPointer(window));
				app->framebufferResized = true;
			});
	}

	void Application::run()
	{
		initVulkan();
		mainLoop();
		cleanup();
	}

	void Application::initVulkan()
	{
		v_PDevice = new PhysicalDevice(v_Window);
		
		/*  创建实例初始化 Vulkan 库 */
		v_PDevice->createInstance(); 
		
		/* 创建测试信使 */
		v_PDevice->setupDebugMessenger(); 
		
		/* 创建窗口表层 */
		v_PDevice->createSurface();
		
		/*  选择物理设备  */
		v_PDevice->pickPhysicalDevice();

		v_LDevice = new LogicalDevice(*v_PDevice);

		/* 创建逻辑设备 */
		v_LDevice->createLogicalDevice();
		
		/* 创建交换链 */
		v_LDevice->createSwapChain();
		
		/*  创建图像视图 */
		v_LDevice->createImageViews();

		v_GraphicsPipeline = new GraphicsPipeline(*v_LDevice);

		/* 创建渲染过程 */
		v_GraphicsPipeline->createRenderPass(); 

		v_Drawing = new Drawing(*v_GraphicsPipeline);
		v_VertexBuffer = new VertexBuffer();
		
		v_VertexBuffer->SetSwapChainExtent(v_LDevice->GetSwapChainExtent());
		v_VertexBuffer->SetUniformBufferMapped(v_Drawing->GetUniformBuffersMapped());
		v_VertexBuffer->SetPhysicalDevice(v_LDevice->GetPhysicalDevice());
		v_VertexBuffer->SetLogicalDevice(v_LDevice->GetLogicalDevice());

		/* 创建描述符布局 */
		v_VertexBuffer->createDescriptorSetLayout();

		auto dd = v_VertexBuffer->GetLayout();
		v_GraphicsPipeline->SetDescriptorSetLayout(dd);
		v_VertexBuffer->SetDescriptorSetLayout(dd);

		/*  创建图形管道 */
		v_GraphicsPipeline->createGraphicsPipeline();


		auto ddes = new Drawing(*v_GraphicsPipeline);
		v_Drawing = ddes;
		v_Drawing->SetPipeline(v_GraphicsPipeline->GetPipeline());

		/* 创建命令缓冲区 */
		v_Drawing->createCommandPool();
		
		v_VertexBuffer->SetCommandPool(v_Drawing->GetCommandPool());

		v_VertexBuffer->SetGraphicsQueue(v_LDevice->GetGraphicsQueue());

		v_Texture = new Texture(v_VertexBuffer);
		v_Texture->SetLogicalDevice(v_LDevice->GetLogicalDevice());
		v_Texture->SetPhysicalDevice(v_LDevice->GetPhysicalDevice());
		v_Texture->SetGraphicsQueue(v_LDevice->GetGraphicsQueue());

		v_Texture->SetSwapChainExtent(v_GraphicsPipeline->GetSwapChainExtent());

		v_Texture->SetSwapChainImageFormat(v_LDevice->GetSwapChainImageFormat());
		v_Texture->SetMassSamples(v_PDevice->GetMsaaSamples());

		/* 创建色彩资源 */
		v_Texture->createColorResources();

		/* 创建深度纹理 */
		v_Texture->createDepthResources();

		v_LDevice->SetDepthImage(v_Texture->GetDepthImage());
		v_LDevice->SetDepthImageView(v_Texture->GetDepthImageView());
		v_LDevice->SetDepthMemory(v_Texture->GetDepthImageMemory());

		v_Drawing->SetDepthImageView(v_Texture->GetDepthImageView());
		v_Drawing->SetColorImageView(v_Texture->GetColorImageView());

		v_GraphicsPipeline->SetMassSamples(v_PDevice->GetMsaaSamples());

		/* 创建帧缓冲 */
		v_Drawing->createFramebuffers();

		/* 创建纹理图像 */
		v_Texture->createTextureImage();

		/* 创建纹理图像视图 */
		v_Texture->createTextureImageView();

		/* 对纹理采样 */
		v_Texture->createTextureSampler();

		v_VertexBuffer->SetTextureImageView(v_Texture->GetImageView());
		v_VertexBuffer->SetTextureSampler(v_Texture->GetImageSampler());

		/*v_Texture->SetVertices(v_VertexBuffer->GetVertices());
		v_Texture->SetIndices(v_VertexBuffer->GetIndices());*/

		/* 加载模型 */
		v_Texture->loadModel();

		v_LDevice->SetColorImage(v_Texture->GetColorImage());
		v_LDevice->SetColorImageView(v_Texture->GetColorImageView());
		v_LDevice->SetColorMemory(v_Texture->GetColorImageMemory());

		v_VertexBuffer->SetVertices(v_Texture->GetVertices());
		v_VertexBuffer->SetIndices(v_Texture->GetIndices());

		/* 创建顶点缓冲区 */
		v_VertexBuffer->createVertexBuffer();

		/* 创建索引缓冲区 */
		v_VertexBuffer->createIndexBuffer();

		/* 创建统一变量缓冲区 */
		v_VertexBuffer->createUniformBuffers();

		/* 描述符池 */
		v_VertexBuffer->createDescriptorPool();

		/* 描述符集 */
		v_VertexBuffer->createDescriptorSets();

		v_Drawing->SetDescriptorSets(v_VertexBuffer->GetDescriptorSets());

		/* 命令缓冲区分配 */
		v_Drawing->createCommandBuffers();

		/* 创建同步机制 */
		v_Drawing->createSyncObjects();
		v_Drawing->SetUniformBuffersMapped(v_VertexBuffer->GetUniformMapped());
		v_Drawing->SetTexture(v_Texture);
		v_Drawing->SetIndexBuffer(v_VertexBuffer->GetIndexBuffer());
		v_Drawing->SetVertexBuffer(v_VertexBuffer->GetVertexBuffer());

		v_Drawing->SetDevice(v_LDevice);
	}

	void Application::mainLoop()
	{
		// 添加一个事件循环
		while (!glfwWindowShouldClose(v_Window)) {
			glfwPollEvents();
			/* 开始按帧绘画 */
			v_Drawing->drawFrame(framebufferResized);
		}

		vkDeviceWaitIdle(v_LDevice->GetLogicalDevice());
	}

	void Application::cleanup()	
	{
		/* 调用函数，释放帧缓冲，图像视图和交换链 */
		v_LDevice->cleanupSwapChain(v_Drawing->GetSwapChainFramebuffers());

		/* 删除管道 */
		vkDestroyPipeline(v_LDevice->GetLogicalDevice(), v_GraphicsPipeline->GetPipeline(), nullptr);

		/* 删除管道布局 */
		vkDestroyPipelineLayout(v_LDevice->GetLogicalDevice(), v_GraphicsPipeline->GetPipelineLayout(), nullptr);

		/* 删除渲染过程 */
		vkDestroyRenderPass(v_LDevice->GetLogicalDevice(), v_GraphicsPipeline->GetRenderPass(), nullptr);

		/* 删除统一变量缓冲区 */
		auto Buffers = v_VertexBuffer->GetBuffers();
		auto BuffersMemory = v_VertexBuffer->GetDeviceMemory();
		for (size_t i = 0; i < MAX_FRAMES_IN_FLIGHT; i++) 
		{
			vkDestroyBuffer(v_LDevice->GetLogicalDevice(), Buffers[i], nullptr);
			vkFreeMemory(v_LDevice->GetLogicalDevice(), BuffersMemory[i], nullptr);
		}

		/* 删除描述符池 */
		vkDestroyDescriptorPool(v_LDevice->GetLogicalDevice(), v_VertexBuffer->GetDescriptorPool(), nullptr);

		/* 删除纹理采样 */
		vkDestroySampler(v_LDevice->GetLogicalDevice(), v_Texture->GetImageSampler(), nullptr);

		/* 删除图像视图 */
		vkDestroyImageView(v_LDevice->GetLogicalDevice(), v_Texture->GetImageView(), nullptr);

		/* 删除图像 */
		vkDestroyImage(v_LDevice->GetLogicalDevice(), v_Texture->GetTextureImage(), nullptr);

		/* 释放图像占用内存 */
		vkFreeMemory(v_LDevice->GetLogicalDevice(), v_Texture->GetTextureImageMemory(), nullptr);

		/* 删除描述符布局 */
		vkDestroyDescriptorSetLayout(v_LDevice->GetLogicalDevice(), v_VertexBuffer->GetLayout(), nullptr);

		/* 删除索引缓冲区 */
		vkDestroyBuffer(v_LDevice->GetLogicalDevice(), v_VertexBuffer->GetIndexBuffer(), nullptr);

		/* 释放为索引缓冲区分配的内存空间 */
		vkFreeMemory(v_LDevice->GetLogicalDevice(), v_VertexBuffer->GetIndexBufferMemory(), nullptr);

		/* 删除顶点缓冲区 */
		vkDestroyBuffer(v_LDevice->GetLogicalDevice(), v_VertexBuffer->GetVertexBuffer(), nullptr);

		/* 释放为顶点缓冲区分配的内存空间 */
		vkFreeMemory(v_LDevice->GetLogicalDevice(), v_VertexBuffer->GetVertexBufferMemory(), nullptr);

		/* 删除同步量 */
		for (size_t i = 0; i < MAX_FRAMES_IN_FLIGHT; i++) {
			vkDestroySemaphore(v_LDevice->GetLogicalDevice(), v_Drawing->GetImageSemaphores()[i], nullptr);
			vkDestroySemaphore(v_LDevice->GetLogicalDevice(), v_Drawing->GetRenderSemaphores()[i], nullptr);
			vkDestroyFence(v_LDevice->GetLogicalDevice(), v_Drawing->GetFences()[i], nullptr);
		}

		// 删除命令缓冲区
		vkDestroyCommandPool(v_LDevice->GetLogicalDevice(), v_Drawing->GetCommandPool(), nullptr);

		/* 使用函数销毁设备 */
		vkDestroyDevice(v_LDevice->GetLogicalDevice(), nullptr);

		if (enableValidationLayers) {
			v_PDevice->DestroyDebugUtilsMessengerEXT(v_PDevice->GetInstance(), v_PDevice->GetDebugMessenger(), nullptr);
		}

		/* 销毁表面的特殊功能 */
		vkDestroySurfaceKHR(v_PDevice->GetInstance(), v_PDevice->GetSurface(), nullptr);

		/* 删除实例 */
		vkDestroyInstance(v_PDevice->GetInstance(), nullptr);

		/* 一旦窗口关闭，我们需要通过销毁它并终止 GLFW 本身来清理资源 */
		glfwDestroyWindow(v_Window);

		glfwTerminate();
	}

}