#pragma once

/* 集成 GLFW 环境 */
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "Device.h"
#include "GraphicsPipeline.h"
#include "Drawing.h"
#include "VertexBuffer.h"
#include "Texture.h"

namespace WMC{

	/* Application 辅助结构 */
	struct WindowsProps
	{
		const int Width;
		const int Height;
		const char* Title;

		WindowsProps(const int width = 1280, const int height = 650, const char* title = "Vulkan")
			: Width(width), Height(height), Title(title) { }
	};

	void drawFrame();

	class Application
	{
	public:
		Application();
		~Application() = default;

		/* Vulkan 运行程序入口 */
		void run();

	private:
		/* 初始化 Vulkan */
		void initVulkan();

		/* 循环执行 */
		void mainLoop();

		/* 收尾工作,清理资源 */
		void cleanup();

	private:
		GLFWwindow* v_Window;

		WindowsProps props{};
		PhysicalDevice* v_PDevice;
		LogicalDevice* v_LDevice;
		GraphicsPipeline* v_GraphicsPipeline;
		Drawing* v_Drawing;
		VertexBuffer* v_VertexBuffer;
		Texture* v_Texture;

		/* 显示处理调整大小 */
		bool framebufferResized = false;

		friend static void framebufferResizeCallback(GLFWwindow* window, int width, int height);
	};

}