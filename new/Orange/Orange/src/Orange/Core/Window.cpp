#include "ogpch.h"
#include "Orange/Core/Window.h"

#ifdef OG_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsWindow.h"
#endif // OG_PLATFORM_WINDOWS

namespace Orange
{

	Scope<Window> Window::Create(const WindowProps& props)
	{
#ifdef OG_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
#else
		OG_CORE_ASSERT(false, "未知的平台类型！");
		return nullptr;
#endif // OG_PLATFORM_WINDOWS

	}

}