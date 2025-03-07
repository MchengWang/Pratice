#include "ogpch.h"
#include "Orange/Renderer/GraphicsContext.h"

#include "Orange/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace Orange
{

	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: OG_CORE_ASSERT(false, "当前并不支持渲染接口：None!"); return nullptr;
		case RendererAPI::API::OpenGL: return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		OG_CORE_ASSERT(false, "未知的渲染接口！");
		return nullptr;
	}

}