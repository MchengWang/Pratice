#include "ogpch.h"

#include "Application.h"

#include "Orange/Events/ApplicationEvent.h"
#include "Orange/Core/Log.h"

#include "Orange/Renderer/Renderer.h"
#include "Orange/Scripting/ScriptEngine.h"

#include "Input.h"

#include "Orange/Utils/PlatformUtils.h"

namespace Orange
{
	Application* Application::o_Instance = nullptr;

	Application::Application(const ApplicationSpecification& specification)
		: o_Specification(specification)
	{
		HZ_PROFILE_FUNCTION();

		OG_CORE_ASSERT(!o_Instance, "Application 实例已经存在！")
		o_Instance = this;

		// Set working directory here
		if (!o_Specification.WorkingDirectory.empty())
			std::filesystem::current_path(o_Specification.WorkingDirectory);
		o_Window = Window::Create(WindowProps(o_Specification.Name));

		o_Window->SetEventCallback(OG_BIND_EVENT_FN(Application::OnEvent));

		Renderer::Init();

		o_ImGuiLayer = new ImGuiLayer();
		PushOverLayer(o_ImGuiLayer);
	}

	Application::~Application()
	{
		HZ_PROFILE_FUNCTION();

		ScriptEngine::Shutdown();
		Renderer::Shutdown();
	}

	void Application::PushLayer(Layer* layer)
	{
		HZ_PROFILE_FUNCTION();

		o_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverLayer(Layer* overLayer)
	{
		HZ_PROFILE_FUNCTION();

		o_LayerStack.PushOverlay(overLayer);
		overLayer->OnAttach();
	}

	void Application::Close()
	{
		o_Running = false;
	}

	void Application::SubmitToMainThread(const std::function<void()>& function)
	{
		std::scoped_lock<std::mutex> lock(o_MainThreadQueueMutex);

		o_MainThreadQueue.emplace_back(function);
	}

	void Application::OnEvent(Event& e)
	{
		HZ_PROFILE_FUNCTION();

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(OG_BIND_EVENT_FN(Application::OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(OG_BIND_EVENT_FN(Application::OnWindowResized));

		for (auto it = o_LayerStack.rbegin(); it != o_LayerStack.rend(); ++it)
		{
			if (e.Handled)
				break;
			(*it)->OnEvent(e);
		}
	}

	void Application::Run()
	{
		HZ_PROFILE_FUNCTION();

		while (o_Running)
		{
			HZ_PROFILE_SCOPE("RunLoop");

			float time = Time::GetTime();
			Timestep timestep = time - o_LastFrameTime;
			o_LastFrameTime = time;

			ExecuteMainThreadQueue();

			if (!o_Minimized) // 当窗口不是最小化的时候，进行图层更新
			{
				{
					HZ_PROFILE_SCOPE("LayerStack OnUpdate");

					for (Layer* layer : o_LayerStack)
						layer->OnUpdate(timestep);
				}

				o_ImGuiLayer->Begin();
				{
					HZ_PROFILE_SCOPE("LayerStack OnImGuiRender");

					for (Layer* layer : o_LayerStack)
						layer->OnImGuiRender();
				}
				o_ImGuiLayer->End();
			}
			o_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& event)
	{
		o_Running = false;
		return true;
	}

	bool Application::OnWindowResized(WindowResizeEvent& event)
	{
		HZ_PROFILE_FUNCTION();

		if (event.GetWidth() == 0 || event.GetHeight() == 0) // 当窗口尺寸最小化时，宽度和高度即为0
		{
			o_Minimized = true;
			return false;
		}

		o_Minimized = false;
		Renderer::OnWindowResized(event.GetWidth(), event.GetHeight());

		return false;
	}

	void Application::ExecuteMainThreadQueue()
	{
		std::scoped_lock<std::mutex> lock(o_MainThreadQueueMutex);

		for (auto& func : o_MainThreadQueue)
			func();
		
		o_MainThreadQueue.clear();
	}

}
