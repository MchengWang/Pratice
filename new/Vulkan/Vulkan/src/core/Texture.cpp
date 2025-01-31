#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#define TINYOBJLOADER_IMPLEMENTATION
#include <tiny_obj_loader.h>

namespace WMC {

	VertexBuffer* s_VertexBuffer = nullptr;

	extern uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties, VkPhysicalDevice physicalDevice);

	Texture::Texture(VertexBuffer* vertexBuffer)
		: v_VertexBuffer(vertexBuffer)
	{
		s_VertexBuffer = vertexBuffer;
	}

	void Texture::createImage(uint32_t width, uint32_t height, uint32_t miplevels, VkSampleCountFlagBits numSamples, VkFormat format,
			VkImageTiling tiling, VkImageUsageFlags usage, VkMemoryPropertyFlags properties, VkImage& image, VkDeviceMemory& imageMemory)
	{
		/**
		* 在 imageType 字段中指定的图像类型告诉 Vulkan 图像中的纹素将采用哪种坐标系进行寻址。
		* 可以创建 1D、2D 和 3D 图像。例如，一维图像可用于存储数据数组或渐变，二维图像主要用于纹理，三维图像可用于存储体素体积。
		* extent 字段指定图像的尺寸，基本上每个轴上有多少个纹素。这就是为什么 depth 必须为 1 而不是 0。
		* 我们的纹理不会是一个数组，我们现在不会使用 mipmapping。
		*/
		VkImageCreateInfo imageInfo{};
		imageInfo.sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
		imageInfo.imageType = VK_IMAGE_TYPE_2D;
		imageInfo.extent.width = static_cast<uint32_t>(width);
		imageInfo.extent.height = static_cast<uint32_t>(height);
		imageInfo.extent.depth = 1;
		imageInfo.mipLevels = miplevels;
		imageInfo.arrayLayers = 1;

		// Vulkan 支持许多可能的图像格式，但我们应该对纹素使用与缓冲区中像素相同的格式，否则复制操作将失败
		imageInfo.format = format;

		/**
		* tiling 该字段可以具有两个值之一：
		*  VK_IMAGE_TILING_LINEAR：纹素像我们的数组一样按行优先顺序排列pixels
		*  VK_IMAGE_TILING_OPTIMAL：纹素按实现定义的顺序布局，以实现最佳访问
		* 
		* 与图像的布局不同，平铺模式以后无法更改。如果希望能够直接访问图像内存中的纹素，则必须使用 VK_IMAGE_TILING_LINEAR。
		* 我们将使用暂存缓冲区而不是暂存映像，因此这不是必需的。我们将使用 VK_IMAGE_TILING_OPTIMAL 从着色器进行高效访问。
		*/
		imageInfo.tiling = tiling;

		/**
		* 图像的 initialLayout 只有两个可能的值：
		*  VK_IMAGE_LAYOUT_UNDEFINED：GPU 不可用，第一次过渡将丢弃纹素。
		*  VK_IMAGE_LAYOUT_PREINITIALIZED：GPU 不可用，但第一个过渡将保留纹素
		* 
		* 在第一次转换期间需要保留纹素的情况很少。但是，例如，如果要将映像用作暂存映像，并与 VK_IMAGE_TILING_LINEAR 布局结合使用。
		* 在这种情况下，您需要将纹素数据上传到该图像，然后将图像转换为传输源，而不会丢失数据。
		* 但是，在我们的示例中，我们首先将图像转换为传输目标，然后将纹素数据从缓冲区对象复制到该图像，
		* 因此我们不需要此属性，可以安全地使用VK_IMAGE_LAYOUT_UNDEFINED。
		*/
		imageInfo.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;

		/**
		* usage 字段与缓冲区创建期间的 usage 字段具有相同的语义。该图像将用作缓冲区副本的目标，因此应将其设置为传输目标。
		* 我们还希望能够从着色器访问图像来为网格着色，因此用法应包括 VK_IMAGE_USAGE_SAMPLED_BIT。
		*/
		imageInfo.usage = usage;
		imageInfo.samples = numSamples;

		// 该映像将仅由一个队列系列使用：支持图形（因此也支持）传输操作的队列系列.
		imageInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;

		/**
		* samples 标志与多重采样相关。这仅与将用作附件的图像相关，因此请坚持使用一个示例。对于与稀疏图像相关的图像，有一些可选标志。
		* 稀疏图像是只有某些区域实际上由内存支持的图像。例如，如果您为体素地形使用 3D 纹理，则可以使用它来避免分配内存来存储大量 “air” 值。
		* 在本教程中，我们不会使用它，因此请将其保留为默认值 0。
		*/
		imageInfo.samples = VK_SAMPLE_COUNT_1_BIT;
		imageInfo.flags = 0; // Optional

		/**
		* 该图像是使用 vkCreateImage 创建的，它没有任何特别值得注意的参数。图形硬件可能不支持 VK_FORMAT_R8G8B8A8_SRGB 格式。
		* 您应该有一个可接受的替代方案列表，并选择受支持的最佳替代方案。但是，对这种特定格式的支持非常广泛，因此我们将跳过此步骤。
		* 使用不同的格式也需要烦人的转换。我们将在 depth buffer 章节中回到这个问题，在那里我们将实现这样一个系统。
		*/
		if (vkCreateImage(v_LDevice, &imageInfo, nullptr, &image) != VK_SUCCESS) 
		{
			throw std::runtime_error("failed to create image!");
		}

		/**
		* 为图像分配内存的工作方式与为缓冲区分配内存的方式完全相同。
		* 使用 vkGetImageMemoryRequirements 而不是 vkGetBufferMemoryRequirements，使用 vkBindImageMemory 而不是 vkBindBufferMemory。
		*/
		VkMemoryRequirements memRequirements;
		vkGetImageMemoryRequirements(v_LDevice, image, &memRequirements);

		VkMemoryAllocateInfo allocInfo{};
		allocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
		allocInfo.allocationSize = memRequirements.size;
		allocInfo.memoryTypeIndex = findMemoryType(memRequirements.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,v_PDevice);

		if (vkAllocateMemory(v_LDevice, &allocInfo, nullptr, &imageMemory) != VK_SUCCESS) {
			throw std::runtime_error("failed to allocate image memory!");
		}

		vkBindImageMemory(v_LDevice, image, imageMemory, 0);
	}

	void Texture::createTextureImage()
	{
		int texWidth, texHeight, texChannels;
		stbi_uc* pixels = stbi_load(path->Texture.c_str(), &texWidth, &texHeight, &texChannels, STBI_rgb_alpha);
		VkDeviceSize imageSize = texWidth * texHeight * 4;
		v_MipLevels = static_cast<uint32_t>(std::floor(std::log2(std::max(texWidth, texHeight)))) + 1;

		if (!pixels) 
			throw std::runtime_error("failed to load texture image!");

		VkBuffer stagingBuffer;
		VkDeviceMemory stagingBufferMemory;
		v_VertexBuffer->createBuffer(imageSize, VK_BUFFER_USAGE_TRANSFER_SRC_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, stagingBuffer, stagingBufferMemory);

		void* data;
		vkMapMemory(v_LDevice, stagingBufferMemory, 0, imageSize, 0, &data);
		memcpy(data, pixels, static_cast<size_t>(imageSize));
		vkUnmapMemory(v_LDevice, stagingBufferMemory);

		stbi_image_free(pixels);

		createImage(texWidth, texHeight, v_MipLevels, VK_SAMPLE_COUNT_8_BIT, VK_FORMAT_R8G8B8A8_SRGB, VK_IMAGE_TILING_OPTIMAL, VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, v_TextureImage, v_TextureImageMemory);
		s_VertexBuffer->transitionImageLayout(&v_TextureImage, VK_FORMAT_R8G8B8A8_SRGB, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, v_MipLevels);
		s_VertexBuffer->copyBufferToImage(stagingBuffer, v_TextureImage, static_cast<uint32_t>(texWidth), static_cast<uint32_t>(texHeight));

		//s_VertexBuffer->transitionImageLayout(&v_TextureImage, VK_FORMAT_R8G8B8A8_SRGB, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL, v_MipLevels);
		
		SetTextureImage(v_TextureImage);

		vkDestroyBuffer(v_LDevice, stagingBuffer, nullptr);
		vkFreeMemory(v_LDevice, stagingBufferMemory, nullptr);

		v_VertexBuffer->generateMipmaps(v_TextureImage, VK_FORMAT_R8G8B8A8_SRGB, texWidth, texHeight, v_MipLevels);
	}

	VkImageView Texture::createImageView(VkImage image, VkFormat format, VkImageAspectFlags aspectFlags, uint32_t mipLevels)
	{
		VkImageViewCreateInfo viewInfo{};
		viewInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
		viewInfo.image = image;
		viewInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
		viewInfo.format = format;
		viewInfo.subresourceRange.aspectMask = aspectFlags;
		viewInfo.subresourceRange.baseMipLevel = 0;
		viewInfo.subresourceRange.levelCount = mipLevels;
		viewInfo.subresourceRange.baseArrayLayer = 0;
		viewInfo.subresourceRange.layerCount = 1;

		VkImageView imageView;
		if (vkCreateImageView(v_LDevice, &viewInfo, nullptr, &imageView) != VK_SUCCESS) 
		{
			throw std::runtime_error("failed to create image view!");
		}

		return imageView;
	}

	void Texture::createTextureImageView()
	{
		v_TextureImageView = createImageView(v_TextureImage, VK_FORMAT_R8G8B8A8_SRGB, VK_IMAGE_ASPECT_COLOR_BIT, v_MipLevels);
	}

	/* 采样器通过 VkSamplerCreateInfo 结构进行配置，该结构指定了应应用的所有过滤器和转换。 */
	void Texture::createTextureSampler()
	{
		VkPhysicalDeviceProperties properties{};
		vkGetPhysicalDeviceProperties(v_PDevice, &properties);

		/**
		* magFilter 和 minFilter 字段指定如何对放大或缩小的纹素进行插值。放大涉及上述过采样问题，而缩小涉及欠采样。
		* 选项包括 VK_FILTER_NEAREST 和 VK_FILTER_LINEAR，对应于上图中演示的模式。
		*/
		VkSamplerCreateInfo samplerInfo{};
		samplerInfo.sType = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO;
		samplerInfo.magFilter = VK_FILTER_LINEAR;
		samplerInfo.minFilter = VK_FILTER_LINEAR;

		/**
		* 可以使用 addressMode 字段为每个轴指定寻址模式。下面列出了可用值。
		* 上图演示了其中的大部分。请注意，这些轴称为 U、V 和 W，而不是 X、Y 和 Z。这是纹理空间坐标的约定。
		* 
		* VK_SAMPLER_ADDRESS_MODE_REPEAT：超出图像尺寸时重复纹理。
		* VK_SAMPLER_ADDRESS_MODE_MIRRORED_REPEAT：类似于 repeat，但在超出维度时反转坐标以镜像图像。
		* VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE：采用最靠近图像尺寸外坐标的边缘的颜色。
		* VK_SAMPLER_ADDRESS_MODE_MIRROR_CLAMP_TO_EDGE：类似于 clamp to edge，但使用与最近 edge 相反的 edge。
		* VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER：当采样超出图像尺寸时，返回纯色。
		*/
		samplerInfo.addressModeU = VK_SAMPLER_ADDRESS_MODE_REPEAT;
		samplerInfo.addressModeV = VK_SAMPLER_ADDRESS_MODE_REPEAT;
		samplerInfo.addressModeW = VK_SAMPLER_ADDRESS_MODE_REPEAT;

		/**
		* 这两个字段指定是否应使用各向异性过滤。除非性能是一个问题，否则没有理由不使用它。maxAnisotropy 字段限制可用于计算最终颜色的纹素样本数。
		* 值越低，性能越好，但结果质量越低。要弄清楚我们可以使用哪个值，我们需要检索物理设备的属性，如下所示：
		*/
		samplerInfo.anisotropyEnable = VK_FALSE;
		samplerInfo.maxAnisotropy = properties.limits.maxSamplerAnisotropy;

		/**
		* borderColor 字段指定在使用 clamp to border 寻址模式对图像之外进行采样时返回哪种颜色。
		* 可以以 float 或 int 格式返回 black、white 或 transparent。不能指定任意颜色。
		*/
		samplerInfo.borderColor = VK_BORDER_COLOR_INT_OPAQUE_BLACK;

		/**
		* unnormalizedCoordinates 字段指定要用于对图像中的纹素进行寻址的坐标系。
		* 如果此字段VK_TRUE，则只需使用 [0， texWidth） 和 [0， texHeight） 范围内的坐标。
		* 如果为 VK_FALSE，则在所有轴上使用 [0， 1） 范围寻址纹素。实际应用程序几乎总是使用标准化坐标，
		* 因为这样就可以使用具有完全相同坐标的不同分辨率的纹理。
		*/
		samplerInfo.unnormalizedCoordinates = VK_FALSE;

		/**
		* 如果启用了比较功能，则首先将纹素与值进行比较，并将该比较的结果用于筛选操作。
		* 这主要用于阴影贴图上的百分比接近筛选。我们将在下一章中探讨这一点。
		*/
		samplerInfo.compareEnable = VK_FALSE;
		samplerInfo.compareOp = VK_COMPARE_OP_ALWAYS;

		samplerInfo.mipmapMode = VK_SAMPLER_MIPMAP_MODE_LINEAR;
		samplerInfo.minLod = 0.0f; // Optional
		samplerInfo.maxLod = VK_LOD_CLAMP_NONE;
		samplerInfo.mipLodBias = 0.0f; // Optional

		/**
		* 请注意，采样器不会在任何地方引用 VkImage。采样器是一个不同的对象，它提供了一个用于从纹理中提取颜色的接口。
		* 它可以应用于您想要的任何图像，无论是 1D、2D 还是 3D。这与许多较旧的 API 不同，后者将纹理图像和筛选合并为单个状态。
		*/
		if (vkCreateSampler(v_LDevice, &samplerInfo, nullptr, &v_TextureSampler) != VK_SUCCESS) 
		{
			throw std::runtime_error("failed to create texture sampler!");
		}
	}

	VkFormat Texture::findSupportedFormat(const std::vector<VkFormat>& candidates, VkImageTiling tiling, VkFormatFeatureFlags features, VkPhysicalDevice device) 
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

	VkFormat Texture::findDepthFormat(VkPhysicalDevice device) {
		return findSupportedFormat(
			{ VK_FORMAT_D32_SFLOAT, VK_FORMAT_D32_SFLOAT_S8_UINT, VK_FORMAT_D24_UNORM_S8_UINT },
			VK_IMAGE_TILING_OPTIMAL,
			VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT, device
		);
	}

	bool hasStencilComponent(VkFormat format) 
	{
		return format == VK_FORMAT_D32_SFLOAT_S8_UINT || format == VK_FORMAT_D24_UNORM_S8_UINT;
	}

	void Texture::createDepthResources()
	{
		VkFormat depthFormat = findDepthFormat(v_PDevice);
		createImage(v_SwapChainExtent.width, v_SwapChainExtent.height, 1, v_MsaaSamples, depthFormat, VK_IMAGE_TILING_OPTIMAL, VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, v_DepthImage, v_DepthImageMemory);
		v_DepthImageView = createImageView(v_DepthImage, depthFormat, VK_IMAGE_ASPECT_DEPTH_BIT, 1);
	}

	/**
	* OBJ 文件由位置、法线、纹理坐标和面组成。面由任意数量的顶点组成，其中每个顶点通过索引引用位置、法线和/或纹理坐标。
	* 这样，不仅可以重用整个顶点，还可以重用单个属性。
	*/
	void Texture::loadModel()
	{
		/**
		* attrib 容器在其 attrib.vertices、attrib.normals 和 attrib.texcoords 矢量中包含所有位置、法线和纹理坐标。
		* 形状容器包含所有单独的对象及其面。每个面都由一个顶点数组组成，每个顶点都包含位置、法线和纹理坐标属性的索引。
		* OBJ 模型还可以定义每个面的材质和纹理，但我们将忽略这些。
		*/
		tinyobj::attrib_t attrib;
		std::vector<tinyobj::shape_t> shapes;
		std::vector<tinyobj::material_t> materials;
		std::string warn, err;

		/**
		* err 字符串包含错误，warn 字符串包含加载文件时发生的警告，例如缺少材质定义。
		* 仅当 LoadObj 函数返回 false 时，加载才会真正失败。如上所述，OBJ 文件中的面实际上可以包含任意数量的顶点，
		* 而我们的应用程序只能渲染三角形。幸运的是，LoadObj 有一个可选参数来自动对此类面进行三角剖分，该参数默认处于启用状态。
		*/
		if (!tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, path->Obj.c_str()))
		{
			throw std::runtime_error(warn + err);
		}

		std::unordered_map<Vertex, uint32_t> uniqueVertices{};
		for (const auto& shape : shapes) {
			for (const auto& index : shape.mesh.indices) {
				Vertex vertex{};

				vertex.pos = {
					attrib.vertices[3 * index.vertex_index + 0],
					attrib.vertices[3 * index.vertex_index + 1],
					attrib.vertices[3 * index.vertex_index + 2]
				};

				vertex.texCoord = {
					attrib.texcoords[2 * index.texcoord_index + 0],
					1.0f - attrib.texcoords[2 * index.texcoord_index + 1]
				};

				vertex.color = { 1.0f, 1.0f, 1.0f };

				if (uniqueVertices.count(vertex) == 0)
				{
					uniqueVertices[vertex] = static_cast<uint32_t>(v_Vertices.size());
					v_Vertices.push_back(vertex);
				}

				v_Indices.push_back(uniqueVertices[vertex]);
			}
		}
	}

	void Texture::createColorResources() {
		VkFormat colorFormat = v_SwapChainImageFormat;

		createImage(v_SwapChainExtent.width,v_SwapChainExtent.height, 1, v_MsaaSamples, colorFormat, VK_IMAGE_TILING_OPTIMAL, VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT | VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, v_ColorImage, v_ColorImageMemory);
		v_ColorImageView = createImageView(v_ColorImage, colorFormat, VK_IMAGE_ASPECT_COLOR_BIT, 1);
	}

}