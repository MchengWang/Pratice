#include "GraphicsPipeline.h"
#include "VertexArray.h"

#include <fstream>

namespace WMC {

	///////////////////////////////
	////// 辅助函数 ///////////////
	//////////////////////////////
	
	static VkDevice s_Device;

	/**
	* 函数从指定文件中读取所有字节，并将字节数组存储到 std::vector
	*  ate 从文件末尾开始读取
	*  binary 将文件作为二进制文件读取
	*/
	static std::vector<char> readFile(const std::string& filename)
	{
		std::ifstream file(filename, std::ios::ate | std::ios::binary);

		if (!file.is_open())
		{
			throw std::runtime_error("failed to open file!");
		}

		// 使用读取位置来确定文件的大小并分配缓冲区
		size_t fileSize = (size_t)file.tellg();
		std::vector<char> buffer(fileSize);

		// 返回开头，一次性读取全部文件
		file.seekg(0);
		file.read(buffer.data(), fileSize);

		file.close();

		return buffer;
	}

	/* 创建着色器模块 */
	VkShaderModule createShaderModule(const std::vector<char>& code) 
	{
		VkShaderModuleCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
		createInfo.codeSize = code.size();
		createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());

		VkShaderModule shaderModule;
		if (vkCreateShaderModule(s_Device, &createInfo, nullptr, &shaderModule) != VK_SUCCESS) {
			throw std::runtime_error("failed to create shader module!");
		}

		return shaderModule;
	}

	VkFormat findSupportedFormat(const std::vector<VkFormat>& candidates, VkImageTiling tiling, VkFormatFeatureFlags features, VkPhysicalDevice device)
	{
		for (VkFormat format : candidates)
		{
			/**
			* VkFormatProperties结构包含三个字段：
			*  linearTilingFeatures：线性平铺支持的用例
			*  optimalTilingFeatures：最佳平铺支持的用例
			*  bufferFeatures：缓冲区支持的用例
			*
			* 这里只有前两个是相关的，我们检查的那个取决于函数的 tiling 参数：
			*/
			VkFormatProperties props;
			vkGetPhysicalDeviceFormatProperties(device, format, &props);

			if (tiling == VK_IMAGE_TILING_LINEAR && (props.linearTilingFeatures & features) == features)
			{
				return format;
			}
			else if (tiling == VK_IMAGE_TILING_OPTIMAL && (props.optimalTilingFeatures & features) == features)
			{
				return format;
			}
		}

		throw std::runtime_error("failed to find supported format!");
	}

	VkFormat findDepthFormat(VkPhysicalDevice device) {
		return findSupportedFormat(
			{ VK_FORMAT_D32_SFLOAT, VK_FORMAT_D32_SFLOAT_S8_UINT, VK_FORMAT_D24_UNORM_S8_UINT },
			VK_IMAGE_TILING_OPTIMAL,
			VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT, device
		);
	}
	
	GraphicsPipeline::GraphicsPipeline(LogicalDevice device)
		: v_LDevice(device.GetLogicalDevice())
	{
		s_Device = device.GetLogicalDevice();
		v_SwapChainImageFormat = device.GetSwapChainImageFormat();
		v_SwapChainImageViews = device.GetSwapChainImageViews();
		v_SwapChainExtent = device.GetSwapChainExtent();
		v_PDevice = device.GetPhysicalDevice();
		v_SwapChain = device.GetSwapChain();
		v_GraphicsQueue = device.GetGraphicsQueue();
		v_PresentQueue = device.GetPresentQueue();
		v_Device = &device;
	}

	void GraphicsPipeline::createGraphicsPipeline()
	{
		// 加载着色器的字节码
		auto vertShaderCode = readFile("assets/shaders/texture_vert.spv");
		auto fragShaderCode = readFile("assets/shaders/texture_frag.spv");

		VkShaderModule vertShaderModule = createShaderModule(vertShaderCode);
		VkShaderModule fragShaderModule = createShaderModule(fragShaderCode);

		// 填写顶点着色器结构
		VkPipelineShaderStageCreateInfo vertShaderStageInfo{};
		vertShaderStageInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
		vertShaderStageInfo.stage = VK_SHADER_STAGE_VERTEX_BIT;

		// 告诉 Vulkan 将在那个管道阶段中使用着色器
		vertShaderStageInfo.module = vertShaderModule;
		vertShaderStageInfo.pName = "main";

		// 填写片段着色器结构
		VkPipelineShaderStageCreateInfo fragShaderStageInfo{};
		fragShaderStageInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
		fragShaderStageInfo.stage = VK_SHADER_STAGE_FRAGMENT_BIT;

		// 告诉 Vulkan 将在那个管道阶段中使用着色器
		fragShaderStageInfo.module = fragShaderModule;
		fragShaderStageInfo.pName = "main";

		VkPipelineShaderStageCreateInfo shaderStages[] = { vertShaderStageInfo, fragShaderStageInfo };

		/**
		* 顶点输入
		*  VkPipelineVertexInputStateCreateInfo 描述将传递给着色器的顶点数据的格式
		*  Bindings 数据之间的间距以及数据是按顶点还是实例
		*  Attribute descriptions 传递给顶点着色器的属性类型，从那个绑定加载他们以及在那个偏移处加载他们
		*
		*  pVertexBindingDescriptions 和 pVertexAttributeDescriptions 成员执行一个结构数组，
		*  这些结构描述上述用于加载顶点数据的详细信息
		*/
		VkPipelineVertexInputStateCreateInfo vertexInputInfo{};
		vertexInputInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;

		auto bindingDescription = VertexArray::getBindingDescription();
		auto attributeDescriptions = VertexArray::getAttributeDescriptions();

		vertexInputInfo.vertexBindingDescriptionCount = 1;
		vertexInputInfo.vertexAttributeDescriptionCount = static_cast<uint32_t>(attributeDescriptions.size());
		vertexInputInfo.pVertexBindingDescriptions = &bindingDescription;
		vertexInputInfo.pVertexAttributeDescriptions = attributeDescriptions.data();

		/**
		* 输入组件
		*  VkPipelineInputAssemblyStateCreateInfo 描述了两件事：从顶点绘制什么样的几何体，以及是否应该启用基元重启
		*  绘制几何体可以使用以下值：
		*   VK_PRIMITIVE_TOPOLOGY_POINT_LIST 来自顶点的点
		*   VK_PRIMITIVE_TOPOLOGY_LINE_LIST 每2个顶点的线，不重用
		*   VK_PRIMITIVE_TOPOLOGY_LINE_STRIP 每条线的结束顶点用作于下一条线的起始顶点
		*   VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST 每3个顶点的三角形，不重用
		*   VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP 每个三角形的第二个和第三个顶点用作于下一个三角形的前两个顶点
		*  通常，顶点是按顺序按索引从顶点缓冲区加载的，但使用元素缓冲区，可以指定使用的索引。这允许执行优化，例如 重用顶点。
		*  如果将 primitiveRestartEnable 成员设置为 VK_TRUE ，则可以在_STRIP 拓扑模式下使用 0xFFFF 或 0x FFFF FFFF 的特殊索引来
		*  拆分线条和三角形
		*/
		VkPipelineInputAssemblyStateCreateInfo inputAssembly{};
		inputAssembly.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
		inputAssembly.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
		inputAssembly.primitiveRestartEnable = VK_FALSE;

		VkPipelineViewportStateCreateInfo viewportState{};
		viewportState.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
		viewportState.viewportCount = 1;
		viewportState.scissorCount = 1;

		/** 
		* 光栅器 VkPipelineRasterizationStateCreateInfo
		*  从顶点着色器中获取由顶点塑造的几何图形，并将其转换为片段，以便由片段着色器着色，海之星深度测试，面部剔除和剪刀测试，
		*  并可以配置为输出填充整个多边形或仅填充边缘的片段（线框渲染）
		*/
		VkPipelineRasterizationStateCreateInfo rasterizer{};
		rasterizer.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
		// 如果设置为 VK_TRUE 则超出近平面和原平面的片段将被固定，而不是丢弃
		rasterizer.depthClampEnable = VK_FALSE;  // 使用此功能需要启用 GPU 功能
		// 如果设置为 VK_TRUE 则几何图形永远不会通过光栅器阶段，这基本上禁用了framebuffer的任何输出
		rasterizer.rasterizerDiscardEnable = VK_FALSE; 
		/**
		* polygonMode 确定几何体生成片段
		*  VK_POLYGON_MODE_FILL 用片段填充多边形的区域
		*  VK_POLYGON_MODE_LINE 多边形边缘绘制为线条
		*  VK_POLYGON_MODE_POINT 多边形顶点绘制为点
		* 
		* 使用填充以外的任何模式都需要启用 GPU 功能
		*/
		rasterizer.polygonMode = VK_POLYGON_MODE_FILL;
		// lineWidth 成员很简单，它根据片段数描述线条的粗细。支持的最大线宽取决于硬件，任何粗于 1.0f 的线都需要您启用 wideLines GPU 功能。
		rasterizer.lineWidth = 1.0f;
		// cullMode 变量确定要使用的面剔除类型。您可以禁用剔除、剔除正面和/或剔除背面。
		rasterizer.cullMode = VK_CULL_MODE_BACK_BIT;
		// frontFace 变量指定要被视为正面的面的顶点顺序，可以是顺时针或逆时针。
		rasterizer.frontFace = VK_FRONT_FACE_COUNTER_CLOCKWISE;
		// 光栅器可以通过添加常量值或根据片段的斜率偏置深度值来更改深度值。这有时用于阴影映射 false 不启用
		rasterizer.depthBiasEnable = VK_FALSE;
		rasterizer.depthBiasConstantFactor = 0.0f; // Optional
		rasterizer.depthBiasClamp = 0.0f; // Optional
		rasterizer.depthBiasSlopeFactor = 0.0f; // Optional

		/**
		* 多重采样 VkPipelineMultisampleStateCreateInfo 抗锯齿的方法之一
		*  工作原理是将栅格化为同一像素的多个多边形的片段着色器结果组合在一起。 这主要发生在边缘，
		*  这也是最明显的锯齿伪像出现的地方。 因为如果只有一个多边形映射到一个像素，则不需要多次运行片段着色器，
		*  因此与简单地渲染到更高分辨率然后缩小比例相比，它的成本要低得多。 启用它需要启用 GPU 功能
		*  
		*/
		VkPipelineMultisampleStateCreateInfo multisampling{};
		multisampling.sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
		multisampling.sampleShadingEnable = VK_FALSE;
		multisampling.rasterizationSamples = v_MsaaSamples;

		/**
		* 深度附件现在可以使用了，但仍需要在图形管道中启用深度测试。它通过 VkPipelineDepthStencilStateCreateInfo 结构进行配置：
		* 
		* depthTestEnable 字段指定是否应将新片段的深度与深度缓冲区进行比较，以查看是否应丢弃它们。
		* 该 depthWriteEnable 字段指定是否应将通过深度测试的片段的新深度实际写入深度缓冲区。
		*/
		VkPipelineDepthStencilStateCreateInfo depthStencil{};
		depthStencil.sType = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO;
		depthStencil.depthTestEnable = VK_TRUE;
		depthStencil.depthWriteEnable = VK_TRUE;

		// depthCompareOp 字段指定为保留或丢弃片段而执行的比较。我们坚持较低的深度 = 更近的约定，因此新片段的深度应该更小。
		depthStencil.depthCompareOp = VK_COMPARE_OP_LESS;

		/*
		* depthBoundsTestEnable、minDepthBounds 和 maxDepthBounds 字段用于可选的深度边界测试。
		* 基本上，这允许您只保留位于指定深度范围内的片段。我们不会使用此功能。
		*/
		depthStencil.depthBoundsTestEnable = VK_FALSE;
		depthStencil.minDepthBounds = 0.0f; // Optional
		depthStencil.maxDepthBounds = 1.0f; // Optional
		
		/**
		* 最后三个字段配置模板缓冲区操作，本教程中也不会使用。
		* 如果要使用这些操作，则必须确保深度/模板图像的格式包含模板组件。
		*/
		depthStencil.stencilTestEnable = VK_FALSE;
		depthStencil.front = {}; // Optional
		depthStencil.back = {}; // Optional

		multisampling.minSampleShading = 1.0f; // Optional
		multisampling.pSampleMask = nullptr; // Optional
		multisampling.alphaToCoverageEnable = VK_FALSE; // Optional
		multisampling.alphaToOneEnable = VK_FALSE; // Optional

		/**
		* 颜色混合
		*  片段着色器返回颜色后，需要将其与 framebuffer 中已有的颜色组合在一起，这种转换称为颜色混合，有两种方法可以做到这一点
		*   混合旧值和新值以生成最终颜色
		*   使用按位运算组合旧值和新值
		*  有两种类型的结构体可用于配置颜色混合：
		*   VkPipelineColorBlendAttachmentState 包含每个附加的帧缓冲区的配置
		*   VkPipelineColorBlendStateCreateInfo 包含全局颜色混合设置
		*/
		VkPipelineColorBlendAttachmentState colorBlendAttachment{};
		colorBlendAttachment.colorWriteMask = VK_COLOR_COMPONENT_R_BIT |
											  VK_COLOR_COMPONENT_G_BIT |
											  VK_COLOR_COMPONENT_B_BIT |
											  VK_COLOR_COMPONENT_A_BIT;
		colorBlendAttachment.blendEnable = VK_FALSE;

		colorBlendAttachment.srcColorBlendFactor = VK_BLEND_FACTOR_ONE; // Optional
		colorBlendAttachment.dstColorBlendFactor = VK_BLEND_FACTOR_ZERO; // Optional
		colorBlendAttachment.colorBlendOp = VK_BLEND_OP_ADD; // Optional
		colorBlendAttachment.srcAlphaBlendFactor = VK_BLEND_FACTOR_ONE; // Optional
		colorBlendAttachment.dstAlphaBlendFactor = VK_BLEND_FACTOR_ZERO; // Optional
		colorBlendAttachment.alphaBlendOp = VK_BLEND_OP_ADD; // Optional

		/**
		* 如果要使用第二种混合方法（按位组合），则应将 logicOpEnable 设置为 VK_TRUE。
		* 然后可以在 logicOp 字段中指定按位运算。请注意，这将自动禁用第一种方法，
		* 就像为每个附加的帧缓冲区将 blendEnable 设置为 VK_FALSE一样！
		* colorWriteMask 也将在此模式下用于确定 framebuffer 中的哪些通道实际会受到影响。
		* 也可以禁用这两种模式，就像在这里所做的那样，在这种情况下，片段颜色将不加修改地写入帧缓冲区。
		*/
		VkPipelineColorBlendStateCreateInfo colorBlending{};
		colorBlending.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
		colorBlending.logicOpEnable = VK_FALSE;
		colorBlending.logicOp = VK_LOGIC_OP_COPY; // Optional
		colorBlending.attachmentCount = 1;
		colorBlending.pAttachments = &colorBlendAttachment;
		colorBlending.blendConstants[0] = 0.0f; // Optional
		colorBlending.blendConstants[1] = 0.0f; // Optional
		colorBlending.blendConstants[2] = 0.0f; // Optional
		colorBlending.blendConstants[3] = 0.0f; // Optional

		/**
		* 动态状态
		*  虽然大多数管道状态需要烘焙到管道状态中，但实际上可以更改有限数量的状态，而无需在绘制时重新创建管道。
		*  例如，视区的大小、线宽和混合常量。如果使用动态状态并保留这些属性，则必须填写 VkPipelineDynamicStateCreateInfo 结构
		*/
		std::vector<VkDynamicState> dynamicStates = {
			VK_DYNAMIC_STATE_VIEWPORT,
			VK_DYNAMIC_STATE_SCISSOR
		};

		VkPipelineDynamicStateCreateInfo dynamicState{};
		dynamicState.sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
		dynamicState.dynamicStateCount = static_cast<uint32_t>(dynamicStates.size());
		dynamicState.pDynamicStates = dynamicStates.data();

		VkPipelineLayoutCreateInfo pipelineLayoutInfo{};
		pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
		pipelineLayoutInfo.setLayoutCount = 1; // Optional
		pipelineLayoutInfo.pSetLayouts = &v_DescriptSetLayout; // Optional
		pipelineLayoutInfo.pushConstantRangeCount = 0; // Optional
		pipelineLayoutInfo.pPushConstantRanges = nullptr; // Optional

		if (vkCreatePipelineLayout(v_LDevice, &pipelineLayoutInfo, nullptr, &v_PipelineLayout) != VK_SUCCESS) 
		{
			throw std::runtime_error("failed to create pipeline layout!");
		}

		/**
		* 现在将所有结构和对象组合在一起，创建图形管道
		*  着色器阶段：定义图形管道的可编程阶段功能的着色器模块
		*  固定功能状态： 定义管道的固定功能阶段的所有结构，如输入组合件，光栅器，视区和颜色混合
		*  管道布局：着色器引用的 uniform 和 push 值，可以在绘制时更新
		*  渲染通道：管道阶段引用的附件及其用法
		*/
		VkGraphicsPipelineCreateInfo pipelineInfo{};
		pipelineInfo.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
		pipelineInfo.stageCount = 2;
		pipelineInfo.pStages = shaderStages;

		// 引用固定功能阶段的所有结构
		pipelineInfo.pVertexInputState = &vertexInputInfo;
		pipelineInfo.pInputAssemblyState = &inputAssembly;
		pipelineInfo.pViewportState = &viewportState;
		pipelineInfo.pRasterizationState = &rasterizer;
		pipelineInfo.pMultisampleState = &multisampling;
		pipelineInfo.pDepthStencilState = &depthStencil; // Optional
		pipelineInfo.pColorBlendState = &colorBlending;
		pipelineInfo.pDynamicState = &dynamicState;

	    // 引用管道布局
		pipelineInfo.layout = v_PipelineLayout;

		// 获得对渲染通道的引用和将使用此图形管道的子通道的索引
		pipelineInfo.renderPass = v_RenderPass;
		pipelineInfo.subpass = 0;

		/**
		* 实际上还有两个参数：basePipelineHandle 和 basePipelineIndex。Vulkan 允许您通过从现有管道派生来创建新的图形管道。
		* 管道衍生物的理念是，当管道与现有管道具有许多共同功能时，设置管道的成本较低，并且还可以更快地在来自同一父级的管道之间切换。
		* 您可以使用 basePipelineHandle 指定现有管道的句柄，也可以使用 basePipelineIndex 引用即将由索引创建的另一个管道。
		* 现在只有一个管道，因此我们只需指定一个 null 句柄和一个无效索引。
		* 仅当 VkGraphicsPipelineCreateInfo 的 flags 字段中也指定了 VK_PIPELINE_CREATE_DERIVATIVE_BIT 标志时，才使用这些值。
		*/
		pipelineInfo.basePipelineHandle = VK_NULL_HANDLE; // Optional
		//pipelineInfo.basePipelineIndex = -1; // Optional

		if (vkCreateGraphicsPipelines(v_LDevice, VK_NULL_HANDLE, 1, &pipelineInfo, nullptr, &v_GraphicsPipeline) != VK_SUCCESS) {
			throw std::runtime_error("failed to create graphics pipeline!");
		}

		vkDestroyShaderModule(s_Device, fragShaderModule, nullptr);
		vkDestroyShaderModule(s_Device, vertShaderModule, nullptr);
	}

	/**
	* 在完成管道创建之前，需要告诉 Vulkan 渲染时将使用的帧缓冲区附件。需要指定将有多少个颜色和深度缓冲区，
	* 每个缓冲区使用多少个样本，以及在整个渲染操作中应如何处理内容。所有信息都包装在一个 render-pass 对象中
	*/
	void GraphicsPipeline::createRenderPass()
	{
		VkAttachmentDescription colorAttachment{};
		colorAttachment.format = v_SwapChainImageFormat;
		colorAttachment.samples = v_MsaaSamples;

		/**
		* loadOp 和 storeOp 确定在渲染之前和渲染之后如何处理附件中的数据。
		* 对于 loadOp，我们有以下选择：
		*  VK_ATTACHMENT_LOAD_OP_LOAD 保留附件中的现有内容
		*  VK_ATTACHMENT_LOAD_OP_CLEAR 在开始时将值清除为常量
		*  VK_ATTACHMENT_LOAD_OP_DONT_CARE 现有内容未定义
		* 对于 storeOp 有两种选择
		*  VK_ATTACHMENT_STORE_OP_STORE 渲染的内容将存储在内存中，以后可以读取
		*  VK_ATTACHMENT_STORE_OP_DONT_CARE 渲染操作后，帧缓冲区的内容将未定义
		*/
		colorAttachment.loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
		colorAttachment.storeOp = VK_ATTACHMENT_STORE_OP_STORE;

		/**
		* loadOp 和 storeOp 适用于颜色和深度数据，stencilLoadOp / stencilStoreOp 适用于模板数据。
		* 应用程序不会对模板缓冲区执行任何操作，因此加载和存储的结果无关紧要。
		*/
		colorAttachment.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
		colorAttachment.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;

		/**
		* Vulkan 中的纹理和帧缓冲区由具有特定像素格式的 VkImage 对象表示，但内存中像素的布局可能会根据尝试对图像执行的操作而改变。
		* 
		* 一些最常见的布局是：
		*  VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL：用作颜色附件的图像
		*  VK_IMAGE_LAYOUT_PRESENT_SRC_KHR：要在交换链中呈现的图像
		*  VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL：用作内存复制操作目标的图像
		* 
		* initialLayout 指定图像在渲染通道开始之前将具有的布局。
		* finalLayout 指定在渲染通道完成时自动过渡到的布局。
		*  将 VK_IMAGE_LAYOUT_UNDEFINED 用于 initialLayout 意味着我们不关心图像采用的先前布局。
		*  这个特殊值需要注意的是，不能保证保留图像的内容，但这并不重要，因为无论如何都会清除它。
		*  希望图像在渲染后可以使用交换链进行演示，这就是使用 VK_IMAGE_LAYOUT_PRESENT_SRC_KHR 作为 finalLayout 的原因
		*/
		colorAttachment.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;

		/**
		* 您会注意到，我们已将 finalLayout 从 VK_IMAGE_LAYOUT_PRESENT_SRC_KHR 更改为 VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL。
		* 这是因为多重采样图像无法直接呈现。我们首先需要将它们解析为常规映像。此要求不适用于深度缓冲区，因为它不会在任何时候显示。
		* 因此，我们只需要为 color 添加一个新附件，即所谓的 resolve 附件：
		*/
		colorAttachment.finalLayout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

		/**
		* 格式应与深度图像本身相同。这一次我们不关心存储深度数据 （storeOp），因为在绘制完成后不会使用它。
		* 这可能允许硬件执行其他优化。就像 color buffer 一样，我们不关心前面的 depth 内容，
		* 因此我们可以将 VK_IMAGE_LAYOUT_UNDEFINED 用作 initialLayout。
		*/
		VkAttachmentDescription depthAttachment{};
		depthAttachment.format = findDepthFormat(v_PDevice);
		depthAttachment.samples = v_MsaaSamples;
		depthAttachment.loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
		depthAttachment.storeOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
		depthAttachment.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
		depthAttachment.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
		depthAttachment.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
		depthAttachment.finalLayout = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;

		VkAttachmentDescription colorAttachmentResolve{};
		colorAttachmentResolve.format = v_SwapChainImageFormat;
		colorAttachmentResolve.samples = VK_SAMPLE_COUNT_8_BIT;
		colorAttachmentResolve.loadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
		colorAttachmentResolve.storeOp = VK_ATTACHMENT_STORE_OP_STORE;
		colorAttachmentResolve.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
		colorAttachmentResolve.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
		colorAttachmentResolve.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
		colorAttachmentResolve.finalLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;

		/**
		* attachment 参数通过其在 attachment descriptions 数组中的索引指定要引用的附件。
		* 我们的数组由单个 VkAttachmentDescription 组成，因此其索引为 0。
		* 布局指定了我们希望附件在使用此引用的 subpass 期间具有的布局。当 subpass 启动时，Vulkan 会自动将附件转换为此布局。
		* 我们打算使用附件作为颜色缓冲区，顾名思义，VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL 布局将为我们提供最佳性能。
		*/
		VkAttachmentReference colorAttachmentRef{};
		colorAttachmentRef.attachment = 0;
		colorAttachmentRef.layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

		VkAttachmentReference depthAttachmentRef{};
		depthAttachmentRef.attachment = 1;
		depthAttachmentRef.layout = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;

		VkAttachmentReference colorAttachmentResolveRef{};
		colorAttachmentResolveRef.attachment = 2;
		colorAttachmentResolveRef.layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

		/**
		* subpass 可以引用以下其他类型的附件：
		*  pInputAttachments：从着色器读取的附件
		*  pResolveAttachments：用于多重采样颜色附件的附件
		*  pDepthStencilAttachment：深度和模板数据的附件
		*  pPreserveAttachments：此 subpass 不使用但必须为其保留数据的附件
		*/
		VkSubpassDescription subpass{};
		subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
		subpass.colorAttachmentCount = 1;
		subpass.pColorAttachments = &colorAttachmentRef;
		subpass.pDepthStencilAttachment = &depthAttachmentRef;
		subpass.pResolveAttachments = &colorAttachmentResolveRef;

		// 子通道依赖项在 VkSubpassDependency 结构中指定
		VkSubpassDependency dependency{};

		/**
		* 下面两个字段指定依赖项和依赖项 subpass 的索引。特殊值 VK_SUBPASS_EXTERNAL 是指渲染通道之前或之后的隐式子通道，
		* 具体取决于它是在 srcSubpass 还是 dstSubpass 中指定。索引 0 引用我们的 subpass，它是第一个也是唯一一个。
		* dstSubpass 必须始终高于 srcSubpass，以防止依赖关系图中出现循环（除非其中一个子通道是 VK_SUBPASS_EXTERNAL）。
		*/
		dependency.srcSubpass = VK_SUBPASS_EXTERNAL;
		dependency.dstSubpass = 0;
		
		/**
		* 接下来的两个字段指定要等待的操作以及执行这些操作的阶段。
		* 我们需要等待交换链完成从镜像中读取，然后才能访问它。这可以通过等待颜色附件输出阶段本身来实现。
		*/
		dependency.srcStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT | VK_PIPELINE_STAGE_LATE_FRAGMENT_TESTS_BIT;
		dependency.srcAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT | VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT;

		/**
		* 应等待此操作的操作位于 color attachment 阶段，涉及 color attachment的写入。
		* 这些设置将阻止过渡的发生，直到真正必要 （和允许） 时：当我们想要开始向它写入颜色时。
		*/
		dependency.dstStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT | VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT;
		dependency.dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT | VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT;

		std::array<VkAttachmentDescription, 3> attachments = { colorAttachment, depthAttachment, colorAttachmentResolve };


		VkRenderPassCreateInfo renderPassInfo{};
		renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
		renderPassInfo.attachmentCount = static_cast<uint32_t>(attachments.size());
		renderPassInfo.pAttachments = attachments.data();
		renderPassInfo.subpassCount = 1;
		renderPassInfo.pSubpasses = &subpass;
		renderPassInfo.dependencyCount = 1;
		renderPassInfo.pDependencies = &dependency;

		if (vkCreateRenderPass(v_LDevice, &renderPassInfo, nullptr, &v_RenderPass) != VK_SUCCESS) 
		{
			throw std::runtime_error("failed to create render pass!");
		}
	}

}