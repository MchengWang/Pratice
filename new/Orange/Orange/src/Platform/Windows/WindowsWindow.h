#pragma once

#include "Orange/Core/Window.h"
#include "Orange/Renderer/GraphicsContext.h"

#include <GLFW/glfw3.h>

namespace Orange
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		unsigned int GetWidth() const override { return o_Data.Width; }
		unsigned int GetHeight() const override { return o_Data.Height; }

		// ¥∞ø⁄ Ù–‘
		void SetEventCallback(const EventCallbackFn& callback) override { o_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		virtual void* GetNativeWindow() const { return o_Window; }

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

	private:
		GLFWwindow* o_Window;
		Scope<GraphicsContext> o_Context;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData o_Data;
	};
}
