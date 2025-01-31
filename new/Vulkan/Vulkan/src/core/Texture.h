#pragma once

#include <stdexcept>
#include <unordered_map>

#include <vulkan/vulkan.h>

#include "VertexArray.h"
#include "VertexBuffer.h"

namespace WMC {

	struct Path
	{
		const std::string Texture;
		const std::string Obj;

		Path(std::string texture = "assets/textures/viking_room.png", std::string obj = "assets/models/viking_room.obj")
			: Texture(texture), Obj(obj) {}
	};

	class Texture
	{
	public:
		Texture(VertexBuffer* vertexBuffer);
		~Texture() = default;

		void createTextureImage();
		void createTextureImageView();
		void createTextureSampler();
		void createDepthResources();
		void loadModel();
		void createColorResources();

	public:
		void createImage(uint32_t width, uint32_t height, uint32_t mipLevels, VkSampleCountFlagBits numSamples, VkFormat format, VkImageTiling tiling, VkImageUsageFlags usage, VkMemoryPropertyFlags properties, VkImage& image, VkDeviceMemory& imageMemory);
		VkImageView createImageView(VkImage image, VkFormat format, VkImageAspectFlags aspectFlags, uint32_t mipLevels);
		VkFormat findSupportedFormat(const std::vector<VkFormat>& candidates, VkImageTiling tiling, VkFormatFeatureFlags features, VkPhysicalDevice device);
		VkFormat findDepthFormat(VkPhysicalDevice device);

	public:
		/* GET */
		VkImage GetTextureImage() { return v_TextureImage; }
		VkDeviceMemory GetTextureImageMemory() { return v_TextureImageMemory; }
		VkImageView GetImageView() { return v_TextureImageView; }
		VkImageView GetDepthImageView() { return v_DepthImageView; }
		VkImage GetDepthImage() { return v_DepthImage; }
		VkDeviceMemory GetDepthImageMemory() { return v_ColorImageMemory; }
		VkImageView GetColorImageView() { return v_ColorImageView; }
		VkImage GetColorImage() { return v_ColorImage; }
		VkDeviceMemory GetColorImageMemory() { return v_DepthImageMemory; }
		VkSampler GetImageSampler() { return v_TextureSampler; }
		std::vector<Vertex> GetVertices() { return v_Vertices; }
		std::vector<uint32_t> GetIndices() { return v_Indices; }

		/* SET */
		void SetLogicalDevice(VkDevice device) { v_LDevice = device; }
		void SetPhysicalDevice(VkPhysicalDevice device) { v_PDevice = device; }
		void SetGraphicsQueue(VkQueue graphicsQueue) { v_GraphicsQueue = graphicsQueue; }
		void SetSwapChainExtent(VkExtent2D extent) { v_SwapChainExtent = extent; }
		void SetTextureImage(VkImage image) { v_TextureImage = image; }
		void SetVertices(std::vector<Vertex> vertices) { v_Vertices = vertices; }
		void SetIndices(std::vector<uint32_t> indices) { v_Indices = indices; }
		void SetSwapChainImageFormat(VkFormat format) { v_SwapChainImageFormat = format; }
		void SetMassSamples(VkSampleCountFlagBits msaaSamples) { v_MsaaSamples = msaaSamples; }

	private:
		VkDevice v_LDevice;
		VkPhysicalDevice v_PDevice;
		VkQueue v_GraphicsQueue;
		VkExtent2D v_SwapChainExtent;
		VkImage v_ColorImage;
		VkDeviceMemory v_ColorImageMemory;
		VkImageView v_ColorImageView;
		VkSampleCountFlagBits v_MsaaSamples = VK_SAMPLE_COUNT_1_BIT;

		uint32_t v_MipLevels;
		VkImage v_TextureImage;
		VkDeviceMemory v_TextureImageMemory;
		VkImageView v_TextureImageView;
		VkSampler v_TextureSampler;
		VkImage v_DepthImage;
		VkDeviceMemory v_DepthImageMemory;
		VkImageView v_DepthImageView;
		VkFormat v_SwapChainImageFormat;

		std::vector<Vertex> v_Vertices;
		std::vector<uint32_t> v_Indices;

		VertexBuffer* v_VertexBuffer;

		Path* path = new Path();
	};

}