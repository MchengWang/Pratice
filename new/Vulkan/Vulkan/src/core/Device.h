#pragma once

#include <iostream>
#include <vector>
#include <optional>
#include <set>
#include <limits>
#include <stdexcept> // 供 runtime_error 使用
#include <algorithm>

#include <vulkan/vulkan.h>
#include <glfw/glfw3.h>

namespace WMC {

	const std::vector<const char*> validationLayers = {
		"VK_LAYER_KHRONOS_validation"
	};

	const std::vector<const char*> deviceExtensions = {
		VK_KHR_SWAPCHAIN_EXTENSION_NAME
	};

#ifdef NDEBUG
	const bool enableValidationLayers = false;
#else
	const bool enableValidationLayers = true;
#endif

	struct QueueFamilyIndices
	{
		std::optional<uint32_t> graphicsFamily;
		std::optional<uint32_t> presentFamily;

		bool isComplete()
		{
			return graphicsFamily.has_value() && presentFamily.has_value();
		}
	};

	/**
	* 查询 SwapChain 支持详情
	*  基本表面格式（交换链中的最小/最大图像数，图像的最小/最大宽度和高度）
	*  表面格式（像素个数，色彩空间）
	*  可用的演示模式
	*/
	struct SwapChainSupportDetails {
		VkSurfaceCapabilitiesKHR capabilities;
		std::vector<VkSurfaceFormatKHR> formats;
		std::vector<VkPresentModeKHR> presentModes;
	};

	class PhysicalDevice
	{
	public:
		friend class LogicalDevice;

	public:
		PhysicalDevice(GLFWwindow* window);

		void createInstance();
		void setupDebugMessenger();
		void createSurface();
		void pickPhysicalDevice();

		void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, 
			const VkAllocationCallbacks* pAllocator);

	public:
		GLFWwindow* GetWindows() { return v_Window; }
		VkPhysicalDevice GetPhysicalDevice() { return v_PhysicalDevice; }
		VkInstance GetInstance() { return v_Instance; }
		VkSurfaceKHR GetSurface() { return v_Surface; }
		VkDebugUtilsMessengerEXT GetDebugMessenger() { return v_DebugMessenger; }
		VkSampleCountFlagBits getMaxUsableSampleCount();
		VkSampleCountFlagBits GetMsaaSamples() { return v_MsaaSamples; }

	private:
		GLFWwindow* v_Window;

		VkInstance v_Instance;
		VkDebugUtilsMessengerEXT v_DebugMessenger; 
		VkPhysicalDevice v_PhysicalDevice = VK_NULL_HANDLE;
		VkSurfaceKHR v_Surface;
		VkSampleCountFlagBits v_MsaaSamples = VK_SAMPLE_COUNT_1_BIT;

		//friend SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
	};

	class LogicalDevice
	{
	public:
		LogicalDevice() = default;
		LogicalDevice(PhysicalDevice physicalDevice);
		~LogicalDevice() = default;

		void createLogicalDevice();
		void createSwapChain();
		void createImageViews();
		void cleanupSwapChain(std::vector<VkFramebuffer> swapChianFramebuffers);

	public:
		VkDevice GetLogicalDevice() { return v_LDevice; }
		VkPhysicalDevice GetPhysicalDevice() { return v_PDevice; }
		VkSwapchainKHR GetSwapChain() { return v_SwapChain; }
		VkFormat GetSwapChainImageFormat() { return v_SwapChainImageFormat; }
		std::vector<VkImageView> GetSwapChainImageViews() { return v_SwapChainImageViews; }
		std::vector<VkImage> GetSwapChainImage() { return v_SwapChainImages; }
		VkExtent2D GetSwapChainExtent() { return v_SwapChainExtent; }
		VkQueue GetGraphicsQueue() { return graphicsQueue; }
		VkQueue GetPresentQueue() { return presentQueue; }

		void SetDepthImage(VkImage image) { v_DepthImage = image; }
		void SetDepthMemory(VkDeviceMemory memory) { v_DepthImageMemory = memory; }
		void SetDepthImageView(VkImageView imageView) { v_DepthImageView = imageView; }

		void SetColorImage(VkImage image) { v_ColorImage = image; }
		void SetColorMemory(VkDeviceMemory memory) { v_ColorImageMemory = memory; }
		void SetColorImageView(VkImageView imageView) { v_ColorImageView = imageView; }

	private:
		VkDevice v_LDevice;
		VkPhysicalDevice v_PDevice;
		VkQueue graphicsQueue;
		VkQueue presentQueue;
		VkSwapchainKHR v_SwapChain;
		VkFormat v_SwapChainImageFormat;
		VkExtent2D v_SwapChainExtent;

		VkImage v_DepthImage;
		VkDeviceMemory v_DepthImageMemory;
		VkImageView v_DepthImageView;

		VkImage v_ColorImage;
		VkDeviceMemory v_ColorImageMemory;
		VkImageView v_ColorImageView;

		std::vector<VkImage> v_SwapChainImages;
		std::vector<VkImageView> v_SwapChainImageViews; // 存储图像视图

		PhysicalDevice physicalDevice;
	};

}