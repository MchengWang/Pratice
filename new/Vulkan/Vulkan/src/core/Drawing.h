#pragma once

#include <vector>
#include <chrono>

#include <vulkan/vulkan.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Device.h"
#include "VertexArray.h"
#include "GraphicsPipeline.h"
#include "Texture.h"

namespace WMC {

	class Drawing
	{
	public:
		Drawing() = default;
		Drawing(GraphicsPipeline& graphicsPipeline);
		~Drawing() = default;

		void createFramebuffers();
		void createCommandPool();
		void createCommandBuffers();
		void createSyncObjects();
		void drawFrame(bool& framebufferResized);
		void recreateSwapChain();
		void updateUniformBuffer(uint32_t currentImage);
		void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);
		void SetTexture(Texture* texture) { v_Texture = texture; }
		void SetWindow(GLFWwindow* window) { v_Window = window; }
		void SetDevice(LogicalDevice* device) { v_Device = device; }

	public:
		VkCommandPool GetCommandPool() { return v_CommandPool; }
		VkDevice GetLogicalDevice() { return v_LDevice; }
		VkPhysicalDevice GetPhysicalDevice() { return v_PDevice; }
		VkQueue GetGraphicsQueue() { return v_GraphicsQueue; }
		VkQueue GetPresentQueue() { return v_PresentQueue; }
		VkExtent2D GetSwapChainExtent() { return v_SwapChainExtent; }

		std::vector<VkFramebuffer> GetSwapChainFramebuffers() { return v_SwapChainFramebuffers; }
		std::vector<VkSemaphore> GetImageSemaphores() { return v_ImageAvailableSemaphores; }
		std::vector<VkSemaphore> GetRenderSemaphores() { return v_RenderFinishedSemaphores; }
		std::vector<VkFence> GetFences() { return v_InFlightFences; }
		std::vector<void*> GetUniformBuffersMapped() { return v_UniformBuffersMapped; }

		void SetVertexBuffer(VkBuffer vertexBuffer) { v_VertexBuffer = vertexBuffer; }
		void SetIndexBuffer(VkBuffer indexBuffer) { v_IndexBuffer = indexBuffer; }
		void SetIndices(const std::vector<uint32_t>& in) { indices = in; }
		void SetDescriptorSets(const std::vector<VkDescriptorSet>& descriptorSets) { v_DescriptorSets = descriptorSets; }
		void SetSwapChain(VkSwapchainKHR swapChain) { v_SwapChain = swapChain; }
		void SetSwapChainExtent2D(VkExtent2D swapChainExtent) { v_SwapChainExtent = swapChainExtent; }
		void SetUniformBuffersMapped(const std::vector<void*> mapped) { v_UniformBuffersMapped = mapped; }
		void SetSwapChainImageViews(std::vector<VkImageView> sss) { v_SwapChainImageViews = sss; }
		void SetDepthImageView(VkImageView imageView) { v_DepthImageView = imageView; }
		void SetColorImageView(VkImageView imageView) { v_ColorImageView = imageView; }
		void SetPipeline(VkPipeline pipeline) { v_GraphicsPipeline = pipeline; }
		

	private:
		GLFWwindow* v_Window;

		std::vector<VkFramebuffer> v_SwapChainFramebuffers;
		std::vector<VkImageView> v_SwapChainImageViews;
		std::vector<uint32_t> indices;
		std::vector<VkDescriptorSet> v_DescriptorSets;
		std::vector<void*> v_UniformBuffersMapped;

		VkRenderPass v_RenderPass;
		VkPhysicalDevice v_PDevice;
		VkDevice v_LDevice;
		VkExtent2D v_SwapChainExtent;
		VkSwapchainKHR v_SwapChain;
		VkQueue v_GraphicsQueue;
		VkQueue v_PresentQueue;
		VkBuffer v_VertexBuffer;
		VkBuffer v_IndexBuffer;
		VkPipeline v_PipeLine;
		VkPipelineLayout v_PipelineLayout;
		VkImageView v_DepthImageView;
		VkImageView v_ColorImageView;
		VkPipeline v_GraphicsPipeline;

		VkCommandPool v_CommandPool;
		std::vector<VkCommandBuffer> v_CommandBuffers;

		std::vector<VkSemaphore> v_ImageAvailableSemaphores;
		std::vector<VkSemaphore> v_RenderFinishedSemaphores;
		std::vector<VkFence> v_InFlightFences;

		uint32_t currentFrame = 0;

		Texture* v_Texture;
		LogicalDevice* v_Device;
	};

}