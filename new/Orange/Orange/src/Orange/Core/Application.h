#pragma once

#include "Orange/Core/Base.h"

#include "Orange/Core/Window.h"

#include "Orange/Core/LayerStack.h"
#include "Orange/Events/Event.h"
#include "Orange/Events/ApplicationEvent.h"

#include "Orange/Core/Timestep.h"

#include "Orange/ImGui/ImGuiLayer.h"

int main(int argc, char** argv);

namespace Orange
{

	struct ApplicationCommandLineArgs
	{
		int Count = 0;
		char** Args = nullptr;

		const char* operator[](int index) const
		{
			OG_CORE_ASSERT(index < Count);
			return Args[index];
		}
	};

	struct ApplicationSpecification
	{
		std::string Name = "Orange Application";
		std::string WorkingDirectory;
		ApplicationCommandLineArgs CommandLineArgs;
	};


	class Application 
	{
	public:
		Application(const ApplicationSpecification& specification);
		virtual ~Application();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverLayer(Layer* overLayer);

		Window& GetWindow() { return *o_Window; }

		void Close();

		ImGuiLayer* GetImGuiLayer() { return o_ImGuiLayer; }

		static Application& Get() { return *o_Instance; }

		const ApplicationSpecification& GetSpecification() const { return o_Specification; }

		void SubmitToMainThread(const std::function<void()>& function);

	private:
		void Run();
		bool OnWindowClose(WindowCloseEvent& event); // 窗口关闭事件
		bool OnWindowResized(WindowResizeEvent& event); // 窗口尺寸修改事件

		void ExecuteMainThreadQueue();

	private:
		ApplicationSpecification o_Specification;
		Scope<Window> o_Window;
		ImGuiLayer* o_ImGuiLayer;
		bool o_Running = true;
		bool o_Minimized = false; // 设置窗口最小化标志
		LayerStack o_LayerStack;
		float o_LastFrameTime = 0.0f;

		std::vector<std::function<void()>> o_MainThreadQueue;
		std::mutex o_MainThreadQueueMutex;

	private:
		static Application* o_Instance;
		friend int ::main(int argc, char** argv);
	};

	// 在客户端定义
	Application* CreateApplication(ApplicationCommandLineArgs args);

}
