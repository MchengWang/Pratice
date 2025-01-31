#pragma once

#include <vector>
#include <stdexcept>

#include <vulkan/vulkan.h>
#include <glm/glm.hpp>

#include "VertexArray.h"

namespace WMC {

	class VertexBuffer
	{
	public:
		VertexBuffer() = default;
		~VertexBuffer() = default;

		void createVertexBuffer();
		void createIndexBuffer();
		void createDescriptorSetLayout();
		void createUniformBuffers();
		void createDescriptorPool();
		void createDescriptorSets();

	public:
		VkCommandBuffer beginSingleTimeCommands();
		void createBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory);
		void copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);
		void copyBufferToImage(VkBuffer buffer, VkImage image, uint32_t width, uint32_t height);
		void endSingleTimeCommands(VkCommandBuffer commandBuffer);
		void transitionImageLayout(VkImage* image, VkFormat format, VkImageLayout oldLayout, VkImageLayout newLayout, uint32_t mipLevels);
		void generateMipmaps(VkImage image, VkFormat imageFormat, int32_t texWidth, int32_t texHeight, uint32_t mipLevels);

	public:
		VkBuffer GetVertexBuffer() const { return v_VertexBuffer; }
		VkBuffer GetIndexBuffer() const { return v_IndexBuffer; }
		VkDeviceMemory GetVertexBufferMemory() const { return v_VertexBufferMemory; }
		VkDeviceMemory GetIndexBufferMemory() const { return v_IndexBufferMemory; }

		VkDescriptorPool GetDescriptorPool() const { return v_DescriptorPool; }
		VkDescriptorSetLayout GetLayout() { return v_DescriptorSetLayout; }
		std::vector<VkBuffer> GetBuffers() const { return v_UniformBuffers; }
		std::vector<VkDeviceMemory> GetDeviceMemory() const { return v_UniformBuffersMemory; }
		std::vector<VkDescriptorSet> GetDescriptorSets() const { return v_DescriptorSets; }
		std::vector<void*> GetUniformMapped() { return v_UniformBuffersMapped; }

		std::vector<Vertex> GetVertices() { return v_Vertices; }
		std::vector<uint32_t> GetIndices() { return v_Indices; }

		//void SetCommandPool(VkCommandPool commandPool) { v_CommandPool = commandPool; }
		void SetDescriptorSetLayout(VkDescriptorSetLayout layout) { v_DescriptorSetLayout = layout; }
		void SetGraphicsQueue(VkQueue graphicsQueue) { v_GraphicsQueue = graphicsQueue; }
		void SetTextureSampler(VkSampler sampler) { v_TextureSampler = sampler; }
		void SetTextureImageView(VkImageView view) { v_TextureImageView = view; }
		void SetVertices(std::vector<Vertex> vertices) { v_Vertices = vertices; }
		void SetIndices(std::vector<uint32_t> indices) { v_Indices = indices; }
		void SetSwapChainExtent(VkExtent2D extent) { v_SwapChainExtent = extent; }
		void SetUniformBufferMapped(std::vector<void*> mapped) { v_UniformBuffersMapped = mapped; }
		void SetCommandPool(VkCommandPool commandPool) { v_CommandPool = commandPool; }
		void SetPhysicalDevice(VkPhysicalDevice physicalDevice) { v_PDevice = physicalDevice; }
		void SetLogicalDevice(VkDevice device) { v_LDevice = device; }

	private:
		VkDevice v_LDevice;
		VkPhysicalDevice v_PDevice;
		VkExtent2D v_SwapChainExtent;
		VkDescriptorPool v_DescriptorPool;
		VkCommandPool v_CommandPool;
		VkQueue v_GraphicsQueue;

		uint32_t v_MipLevels;

		/* 顶点集 */
		std::vector<Vertex> v_Vertices;
		/**
		* = {
			{{-0.5f, -0.5f, 0.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f}},
			{{0.5f, -0.5f, 0.0f}, {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f}},
			{{0.5f, 0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 1.0f}},
			{{-0.5f, 0.5f, 0.0f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}},

			{{-0.5f, -0.5f, -0.5f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f}},
			{{0.5f, -0.5f, -0.5f}, {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f}},
			{{0.5f, 0.5f, -0.5f}, {0.0f, 0.0f, 1.0f}, {1.0f, 1.0f}},
			{{-0.5f, 0.5f, -0.5f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}}
		}
		*/

		/* 索引集 */
		std::vector<uint32_t> v_Indices;

		/**
		* = {
			0, 1, 2, 2, 3, 0,
			4, 5, 6, 6, 7, 4
		};
		*/

		VkBuffer v_VertexBuffer;
		VkDeviceMemory v_VertexBufferMemory;
		VkBuffer v_IndexBuffer;
		VkDeviceMemory v_IndexBufferMemory;
		VkDescriptorSetLayout v_DescriptorSetLayout;
		VkImageView v_TextureImageView;
		VkSampler v_TextureSampler;

		std::vector<VkDescriptorSet> v_DescriptorSets;
		std::vector<VkBuffer> v_UniformBuffers;
		std::vector<VkDeviceMemory> v_UniformBuffersMemory;
		std::vector<void*> v_UniformBuffersMapped;

		UniformBufferObject* v_UniformBufferObject;

	};

}