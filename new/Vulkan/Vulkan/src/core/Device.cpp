#include "Device.h"

namespace WMC {

    ////////////////////////////////////////////
    //////// 辅助函数 //////////////////////////
    ////////////////////////////////////////////

    VkSurfaceKHR* surface = nullptr;
    PhysicalDevice* s_PhysicalDevice = nullptr;

    /* 该函数将根据是否启用验证层返回所需的扩展列表 */
    std::vector<const char*> getRequiredExtensions() {
        uint32_t glfwExtensionCount = 0;
        const char** glfwExtensions;
        glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

        std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

        if (enableValidationLayers) {
            extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
        }

        return extensions;
    }

    /* 检查是否所有请求的图层都可用 */
    bool checkValidationLayerSupport() {
        uint32_t layerCount;
        vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

        std::vector<VkLayerProperties> availableLayers(layerCount);
        vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

        // 检查列表中是否存在所有层
        for (const char* layerName : validationLayers) {
            bool layerFound = false;

            for (const auto& layerProperties : availableLayers) {
                if (strcmp(layerName, layerProperties.layerName) == 0) {
                    layerFound = true;
                    break;
                }
            }

            if (!layerFound) {
                return false;
            }
        }

        return true;
    }

    /**
    * 回调函数
    * messageSeverity 指定消息的严重性
    * messageType 消息的类型
    * pCallbackData 该参数引用包含消息本身详细信息的结构
    * pUserData 包含在设置回调期间指定的指针，并允许将数据传递给它
    */
    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
        VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
        VkDebugUtilsMessageTypeFlagsEXT messageType,
        const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
        void* pUserData) {

        std::cerr << "validation layer: " << pCallbackData->pMessage << std::endl;

        return VK_FALSE;
    }

    VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, 
        const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger) {
        auto func = (PFN_vkCreateDebugUtilsMessengerEXT)vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");
        if (func != nullptr) {
            return func(instance, pCreateInfo, pAllocator, pDebugMessenger);
        }
        else {
            return VK_ERROR_EXTENSION_NOT_PRESENT;
        }
    }

    /* 填写结构，包含有关 Messenger 及其回调的详细信息 */
    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo) {
        createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
        createInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT |
            VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
            VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT; // 允许指定希望调用回调的所有类型的严重性
        createInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT |
            VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |
            VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT; // 允许筛选通知回传的消息类型
        createInfo.pfnUserCallback = debugCallback; // 指向回调函数的指针
        createInfo.pUserData = nullptr; // Optional
    }

    /* 寻找合适的队列 */
    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice& device)
    {
        QueueFamilyIndices indices;

        uint32_t queueFamilyCount = 0;
        vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);

        std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
        vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilies.data());

        int i = 0;
        for (const auto& queueFamily : queueFamilies) {
            if (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT) {
                indices.graphicsFamily = i;
            }

            VkBool32 presentSupport = false;
            vkGetPhysicalDeviceSurfaceSupportKHR(device, i, *surface, &presentSupport);

            if (presentSupport)
            {
                indices.presentFamily = i;
            }

            if (indices.isComplete())
                break;

            i++;
        }

        return indices;
    }

    // 检查是否包含所有扩展在其中
    bool checkDeviceExtensionSupport(VkPhysicalDevice& device)
    {
        uint32_t extensionCount;
        vkEnumerateDeviceExtensionProperties(device, nullptr, &extensionCount, nullptr);

        std::vector<VkExtensionProperties> availableExtensions(extensionCount);
        vkEnumerateDeviceExtensionProperties(device, nullptr, &extensionCount, availableExtensions.data());

        std::set<std::string> requiredExtensions(deviceExtensions.begin(), deviceExtensions.end());

        for (const auto& extension : availableExtensions) {
            requiredExtensions.erase(extension.extensionName);
        }

        return requiredExtensions.empty();
    }

    /* 随后会定义具体的函数内容 */
    SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device) {
        SwapChainSupportDetails details;

        // 查询 Surface 基本功能
        vkGetPhysicalDeviceSurfaceCapabilitiesKHR(device, s_PhysicalDevice->GetSurface(), &details.capabilities);

        // 查询支持的 Surface 格式
        uint32_t formatCount;
        vkGetPhysicalDeviceSurfaceFormatsKHR(device, s_PhysicalDevice->GetSurface(), &formatCount, nullptr);

        if (formatCount != 0) {
            details.formats.resize(formatCount);
            vkGetPhysicalDeviceSurfaceFormatsKHR(device, s_PhysicalDevice->GetSurface(), &formatCount, details.formats.data());
        }

        // 查询模式的工作方式
        uint32_t presentModeCount;
        vkGetPhysicalDeviceSurfacePresentModesKHR(device, s_PhysicalDevice->GetSurface(), &presentModeCount, nullptr);

        if (presentModeCount != 0) {
            details.presentModes.resize(presentModeCount);
            vkGetPhysicalDeviceSurfacePresentModesKHR(device, s_PhysicalDevice->GetSurface(), &presentModeCount, details.presentModes.data());
        }

        return details;
    }

    /* 评估并检查是否适合需要执行的操作 */
    bool isDeviceSuitable(VkPhysicalDevice device)
    {
        QueueFamilyIndices indices = findQueueFamilies(device);
        bool extensionSupported = checkDeviceExtensionSupport(device);

        // 验证交换链支持是否足够
        bool swapChainAdequate = false;
        if (extensionSupported) {
            SwapChainSupportDetails swapChainSupport = querySwapChainSupport(device);
            swapChainAdequate = !swapChainSupport.formats.empty() && !swapChainSupport.presentModes.empty();
        }

        VkPhysicalDeviceFeatures supportedFeatures;
        vkGetPhysicalDeviceFeatures(device, &supportedFeatures);

        return indices.isComplete() && extensionSupported && swapChainAdequate && supportedFeatures.samplerAnisotropy;
    }

    /**
    *交换链模式通常有三种,
    *  表面格式（颜色深度）
    *  演示模式（将图像‘交换’到屏幕的条件）
    *  交换范围（交换链中图像的分辨率）
    */

    /* Surface 格式 */
    VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats)
    {
        for (const auto& availableFormat : availableFormats)
        {
            if (availableFormat.format == VK_FORMAT_B8G8R8A8_SRGB &&
                availableFormat.colorSpace == VK_COLOR_SPACE_SRGB_NONLINEAR_KHR)
            {
                return availableFormat;
            }
        }

        return availableFormats[0];
    }

    /**
    *演示模式
    * VK_PRESENT_MODE_IMMEDIATE_KHR：应用程序提交的图像会立即传输到屏幕上，可能会导致撕裂。
    * VK_PRESENT_MODE_FIFO_KHR：交换链是一个队列，当显示刷新时，显示器从队列的前面获取图像，程序在队列的后面插入渲染的图像。
    * 如果队列已满，则程序必须等待。 这与现代游戏中的垂直同步最相似。 刷新显示的时刻称为 “vertical blank”
    * VK_PRESENT_MODE_FIFO_RELAXED_KHR：仅当应用程序延迟并且队列在最后一个垂直空白处为空时，此模式才与前一种模式不同。
    * 图像最终到达时会立即传输，而不是等待下一个垂直空白。 这可能会导致明显的撕裂。
    * VK_PRESENT_MODE_MAILBOX_KHR：这是第二种模式的另一种变体。 当队列已满时，不会阻止应用程序，而是简单地将已排队的映像替换为较新的映像。
    * 此模式可用于尽可能快地渲染帧，同时仍避免撕裂，从而比标准垂直同步产生的延迟问题更少。
    * 这通常被称为 “三重缓冲”，尽管仅存在三个缓冲区并不一定意味着帧速率被解锁。
    */
    VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes)
    {
        for (const auto& availablePresentMode : availablePresentModes)
        {
            if (availablePresentMode == VK_PRESENT_MODE_MAILBOX_KHR)
            {
                return availablePresentMode;
            }
        }

        return VK_PRESENT_MODE_FIFO_KHR;
    }

    /** 交换范围
    * 交换范围是交换链图像的分辨率，它几乎总是完全等于我们正在绘制的窗口的分辨率（以像素为单位）
    * 此处使用该函数来限制实现支持的允许的最小和最大范围的值。
    */
    VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities)
    {
        if (capabilities.currentExtent.width != std::numeric_limits<uint32_t>::max())
        {
            return capabilities.currentExtent;
        }
        else
        {
            int width, height;
            glfwGetFramebufferSize(s_PhysicalDevice->GetWindows(), &width, &height);

            VkExtent2D actualExtent = {
                static_cast<uint32_t>(width),
                static_cast<uint32_t>(height)
            };

            actualExtent.width = std::clamp(actualExtent.width, capabilities.minImageExtent.width, capabilities.maxImageExtent.width);
            actualExtent.height = std::clamp(actualExtent.height, capabilities.minImageExtent.height, capabilities.maxImageExtent.height);

            return actualExtent;
        }
    }

    ////////////////////////////////////////////
    /////// PhysicalDevice /////////////////////
    ////////////////////////////////////////////

    PhysicalDevice::PhysicalDevice(GLFWwindow* window)
        : v_Window(window)
    {
        s_PhysicalDevice = this;
    }

	void PhysicalDevice::createInstance()
	{
        if (enableValidationLayers && !checkValidationLayerSupport())
            throw std::runtime_error("validation layers requested, but not available!");

        // 填写有关我们应用程序的一些信息(可选)
        VkApplicationInfo appInfo{};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = "Hello Triangle";
        appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.pEngineName = "No Engine";
        appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.apiVersion = VK_API_VERSION_1_0;

        // 下面的结构体告诉 Vulkan 驱动程序要使用哪些全局扩展和验证层
        VkInstanceCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        createInfo.pApplicationInfo = &appInfo;

        // 确定要启用的全局验证层
        auto extensions = getRequiredExtensions();
        createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
        createInfo.ppEnabledExtensionNames = extensions.data();

        VkDebugUtilsMessengerCreateInfoEXT debugCreateInfo{};
        if (enableValidationLayers) {
            createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
            createInfo.ppEnabledLayerNames = validationLayers.data();

            populateDebugMessengerCreateInfo(debugCreateInfo);
            createInfo.pNext = (VkDebugUtilsMessengerCreateInfoEXT*)&debugCreateInfo;
        }
        else {
            createInfo.enabledLayerCount = 0;

            createInfo.pNext = nullptr;
        }

        if (vkCreateInstance(&createInfo, nullptr, &v_Instance) != VK_SUCCESS) {
            throw std::runtime_error("failed to create instance!");
        }
	}

    void PhysicalDevice::setupDebugMessenger()
    {
        if (!enableValidationLayers) return;

        VkDebugUtilsMessengerCreateInfoEXT createInfo{};
        populateDebugMessengerCreateInfo(createInfo);

        if (CreateDebugUtilsMessengerEXT(v_Instance, &createInfo, nullptr, &v_DebugMessenger) != VK_SUCCESS) {
            throw std::runtime_error("failed to set up debug messenger!");
        }
    }

    void PhysicalDevice::DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger,
        const VkAllocationCallbacks* pAllocator)
    {
        auto func = (PFN_vkDestroyDebugUtilsMessengerEXT)vkGetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT");
        if (func != nullptr) {
            func(instance, debugMessenger, pAllocator);
        }
    }

    void PhysicalDevice::pickPhysicalDevice()
    {
        // 列出可用显卡数量
        uint32_t deviceCount = 0;
        vkEnumeratePhysicalDevices(v_Instance, &deviceCount, nullptr);

        if (deviceCount == 0) // 没有设备支持 Vulkan
        {
            throw std::runtime_error("failed to find GPUs with Vulkan support!");
        }

        // 保存所有支持 Vulkan 的物理设备
        std::vector<VkPhysicalDevice> devices(deviceCount);
        vkEnumeratePhysicalDevices(v_Instance, &deviceCount, devices.data());

        // 检查是否有任何物理设备满足添加到该功能中的要求
        for (const auto& device : devices)
        {
            if (isDeviceSuitable(device))
            {
                v_PhysicalDevice = device;
                v_MsaaSamples = getMaxUsableSampleCount();
                break;
            }
        }

        if (v_PhysicalDevice == VK_NULL_HANDLE)
        {
            throw std::runtime_error("failed to find a suitable GPU!");
        }

    }

    void PhysicalDevice::createSurface()
    {
        if (glfwCreateWindowSurface(v_Instance, v_Window, nullptr, &v_Surface) != VK_SUCCESS) {
            throw std::runtime_error("failed to create window surface!");
        }

        surface = &v_Surface;
    }
   

    ////////////////////////////////////////////
    /////// LogicalDevice //////////////////////
    ////////////////////////////////////////////
    
    LogicalDevice::LogicalDevice(PhysicalDevice physicalDevice)
        : physicalDevice(physicalDevice)
    {
        v_PDevice = physicalDevice.GetPhysicalDevice();
    }

    void LogicalDevice::createLogicalDevice()
    {

        // 创建逻辑设备需要使用结构指定一系列细节
        QueueFamilyIndices indices = findQueueFamilies(v_PDevice);

        // 当前可用的驱动程序只允许为每个队列系列创建少量队列，实际上并不需要多个队列
        std::vector<VkDeviceQueueCreateInfo> queueCreateInfos;
        std::set<uint32_t> uniqueQueueFamilies = {
           indices.graphicsFamily.value(),
           indices.presentFamily.value()
        };

        // 允许为队列分配优先级，使用 0.0f 和 1.0f 之间的浮点数来影响命令缓冲区执行的调度
        float queuePriority = 1.0f;
        for (uint32_t queueFamily : uniqueQueueFamilies) {
            VkDeviceQueueCreateInfo queueCreateInfo{};
            queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
            queueCreateInfo.queueFamilyIndex = queueFamily;
            queueCreateInfo.queueCount = 1;
            queueCreateInfo.pQueuePriorities = &queuePriority;
            queueCreateInfos.push_back(queueCreateInfo);
        }

        // 指定将要使用的设备功能集
        VkPhysicalDeviceFeatures deviceFeatures{};
        deviceFeatures.samplerAnisotropy = VK_TRUE;

        // 创建逻辑设备
        VkDeviceCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;

        createInfo.queueCreateInfoCount = static_cast<uint32_t>(queueCreateInfos.size());
        createInfo.pQueueCreateInfos = queueCreateInfos.data();

        createInfo.pEnabledFeatures = &deviceFeatures;

        // 启用拓展 支持交换链
        // 允许将渲染的图像从该设备呈现到 Windows
        createInfo.enabledExtensionCount = static_cast<uint32_t>(deviceExtensions.size());
        createInfo.ppEnabledExtensionNames = deviceExtensions.data();


        // 通过适当命名的函数来实例化逻辑设备
        if (vkCreateDevice(v_PDevice, &createInfo, nullptr, &v_LDevice) != VK_SUCCESS)
        {
            throw std::runtime_error("failed to create logical device!");
        }

        // 检索每个队列系列的队列句柄
        vkGetDeviceQueue(v_LDevice, indices.graphicsFamily.value(), 0, &graphicsQueue);
        vkGetDeviceQueue(v_LDevice, indices.presentFamily.value(), 0, &presentQueue);
    }

    void LogicalDevice::createSwapChain() {
        SwapChainSupportDetails swapChainSupport = querySwapChainSupport(physicalDevice.GetPhysicalDevice());

        VkSurfaceFormatKHR surfaceFormat = chooseSwapSurfaceFormat(swapChainSupport.formats);
        VkPresentModeKHR presentMode = chooseSwapPresentMode(swapChainSupport.presentModes);
        VkExtent2D extent = chooseSwapExtent(swapChainSupport.capabilities);

        // 设置比当前驱动支持最小值多一个
        uint32_t imageCount = swapChainSupport.capabilities.minImageCount + 1;

        // 应确保在执行是，不超多最大的图形数
        if (swapChainSupport.capabilities.maxImageCount > 0 && imageCount > swapChainSupport.capabilities.maxImageCount)
        {
            imageCount = swapChainSupport.capabilities.maxImageCount;
        }

        VkSwapchainCreateInfoKHR createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
        createInfo.surface = physicalDevice.v_Surface; // 指定交换链应绑定到那个图面后

        // 指定交换链印象的详细信息
        createInfo.minImageCount = imageCount;
        createInfo.imageFormat = surfaceFormat.format;
        createInfo.imageColorSpace = surfaceFormat.colorSpace;
        createInfo.imageExtent = extent;
        createInfo.imageArrayLayers = 1; // 指定每个图像包含的层数 开发3D的时候需要修改
        createInfo.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT; // 指定了将使用交换链中的图像进行何种操作

        QueueFamilyIndices indices = findQueueFamilies(v_PDevice);
        uint32_t queueFamilyIndices[] = { indices.graphicsFamily.value(), indices.presentFamily.value() };

        if (indices.graphicsFamily != indices.presentFamily)
        {
            // 图像可以跨多个队列系列使用，而无需显式所有权转移。
            createInfo.imageSharingMode = VK_SHARING_MODE_CONCURRENT;
            createInfo.queueFamilyIndexCount = 2;
            createInfo.pQueueFamilyIndices = queueFamilyIndices;
        }
        else
        {
            // 图像一次由一个队列系列拥有，必须先明确转移所有权，然后才能在另一个队列系列中使用它。 此选项可提供最佳性能
            createInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
            createInfo.queueFamilyIndexCount = 0; // Optional
            createInfo.pQueueFamilyIndices = nullptr; // Optional
        }

        createInfo.preTransform = swapChainSupport.capabilities.currentTransform;
        createInfo.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR; // 指定是否应使用 Alpha 通道与窗口系统中的其他窗口混合
        createInfo.presentMode = presentMode;
        createInfo.clipped = VK_TRUE;

        //createInfo.oldSwapchain = VK_NULL_HANDLE;

        if (vkCreateSwapchainKHR(v_LDevice, &createInfo, nullptr, &v_SwapChain) != VK_SUCCESS)
        {
            throw std::runtime_error("failed to create swap chain!");
        }

        vkGetSwapchainImagesKHR(v_LDevice, v_SwapChain, &imageCount, nullptr);
        v_SwapChainImages.resize(imageCount);
        vkGetSwapchainImagesKHR(v_LDevice, v_SwapChain, &imageCount, v_SwapChainImages.data());

        v_SwapChainImageFormat = surfaceFormat.format;
        v_SwapChainExtent = extent;
    }

    void LogicalDevice::createImageViews()
    {
        v_SwapChainImageViews.resize(v_SwapChainImages.size());

        for (size_t i = 0; i < v_SwapChainImages.size(); i++) {
            VkImageViewCreateInfo createInfo{};
            createInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
            createInfo.image = v_SwapChainImages[i];

            // 指定应如何解释图像数据
            createInfo.viewType = VK_IMAGE_VIEW_TYPE_2D; // 允许指定 1D，2D，3D 和立方体贴图
            createInfo.format = v_SwapChainImageFormat;

            // 设置颜色通道
            createInfo.components.r = VK_COMPONENT_SWIZZLE_IDENTITY;
            createInfo.components.g = VK_COMPONENT_SWIZZLE_IDENTITY;
            createInfo.components.b = VK_COMPONENT_SWIZZLE_IDENTITY;
            createInfo.components.a = VK_COMPONENT_SWIZZLE_IDENTITY;

            // 描述图像的用途以及应访问图像的哪个部分
            createInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
            createInfo.subresourceRange.baseMipLevel = 0;
            createInfo.subresourceRange.levelCount = 1;
            createInfo.subresourceRange.baseArrayLayer = 0;
            createInfo.subresourceRange.layerCount = 1;

            if (vkCreateImageView(v_LDevice, &createInfo, nullptr, &v_SwapChainImageViews[i]) != VK_SUCCESS) {
                throw std::runtime_error("failed to create image views!");
            }

        }
    }

    void LogicalDevice::cleanupSwapChain(std::vector<VkFramebuffer> swapChianFramebuffers)
    {
        vkDestroyImageView(v_LDevice, v_DepthImageView, nullptr);
        vkDestroyImage(v_LDevice, v_DepthImage, nullptr);
        vkFreeMemory(v_LDevice, v_DepthImageMemory, nullptr);

        vkDestroyImageView(v_LDevice, v_ColorImageView, nullptr);
        vkDestroyImage(v_LDevice, v_ColorImage, nullptr);
        vkFreeMemory(v_LDevice, v_ColorImageMemory, nullptr);

        for (auto framebuffer : swapChianFramebuffers)
        {
            vkDestroyFramebuffer(v_LDevice, framebuffer, nullptr);
        }

        for (auto imageView : v_SwapChainImageViews)
        {
            vkDestroyImageView(v_LDevice, imageView, nullptr);
        }

        vkDestroySwapchainKHR(v_LDevice, v_SwapChain, nullptr);
    }

    VkSampleCountFlagBits PhysicalDevice::getMaxUsableSampleCount() {
        VkPhysicalDeviceProperties physicalDeviceProperties;
        vkGetPhysicalDeviceProperties(v_PhysicalDevice, &physicalDeviceProperties);

        VkSampleCountFlags counts = physicalDeviceProperties.limits.framebufferColorSampleCounts & physicalDeviceProperties.limits.framebufferDepthSampleCounts;
        if (counts & VK_SAMPLE_COUNT_64_BIT) { return VK_SAMPLE_COUNT_64_BIT; }
        if (counts & VK_SAMPLE_COUNT_32_BIT) { return VK_SAMPLE_COUNT_32_BIT; }
        if (counts & VK_SAMPLE_COUNT_16_BIT) { return VK_SAMPLE_COUNT_16_BIT; }
        if (counts & VK_SAMPLE_COUNT_8_BIT) { return VK_SAMPLE_COUNT_8_BIT; }
        if (counts & VK_SAMPLE_COUNT_4_BIT) { return VK_SAMPLE_COUNT_4_BIT; }
        if (counts & VK_SAMPLE_COUNT_2_BIT) { return VK_SAMPLE_COUNT_2_BIT; }

        return VK_SAMPLE_COUNT_1_BIT;
    }

}