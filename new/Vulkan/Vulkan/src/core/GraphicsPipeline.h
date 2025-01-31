#pragma once

#include <vector>

#include <vulkan/vulkan.h>

#include "Device.h"

namespace WMC {

	class GraphicsPipeline
	{
	public:
		friend void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);

	public:
		GraphicsPipeline() = default;
		GraphicsPipeline(LogicalDevice device);
		~GraphicsPipeline() = default;

		void createGraphicsPipeline();
		void createRenderPass();

	public:
		VkPipelineLayout GetPipelineLayout()  { return v_PipelineLayout; }
		VkRenderPass GetRenderPass() { return v_RenderPass; }
		VkPipeline GetPipeline() { return v_GraphicsPipeline; }
		std::vector<VkImageView> GetSwapChainImageViews() { return v_SwapChainImageViews; }
		VkDevice GetLogicalDevice() { return v_LDevice; }
		VkExtent2D GetSwapChainExtent() { return v_SwapChainExtent; }
		VkPhysicalDevice GetPhysicalDevice() { return v_PDevice; }
		VkSwapchainKHR GetSwapChain() { return v_SwapChain; }
		VkQueue GetGraphicsQueue() { return v_GraphicsQueue; }
		VkQueue GetPresentQueue() { return v_PresentQueue; }
		LogicalDevice& GetDevice() { return *v_Device; }
		VkDescriptorSetLayout GetSetLayouts() { return v_DescriptSetLayout; }

		void SetDescriptorSetLayout(VkDescriptorSetLayout& descript) { v_DescriptSetLayout = descript; }
		void SetSwapChain(VkSwapchainKHR swapChain) { v_SwapChain = swapChain; }
		void SetSwapchainImageView(std::vector<VkImageView> s) { v_SwapChainImageViews = s; }
		void SetMassSamples(VkSampleCountFlagBits msaaSamples) { v_MsaaSamples = msaaSamples; }

	private:
		VkPhysicalDevice v_PDevice;
		VkDevice v_LDevice;
		VkFormat v_SwapChainImageFormat;
		VkExtent2D v_SwapChainExtent;
		VkSwapchainKHR v_SwapChain;
		VkSampleCountFlagBits v_MsaaSamples = VK_SAMPLE_COUNT_1_BIT;

		VkRenderPass v_RenderPass;
		VkPipelineLayout v_PipelineLayout;
		VkPipeline v_GraphicsPipeline;

		VkQueue v_GraphicsQueue;
		VkQueue v_PresentQueue;

		std::vector<VkImageView> v_SwapChainImageViews;

		LogicalDevice* v_Device;

		VkDescriptorSetLayout v_DescriptSetLayout;
	};

}