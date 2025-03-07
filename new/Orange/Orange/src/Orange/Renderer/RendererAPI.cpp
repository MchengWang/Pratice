#include "ogpch.h"
#include "Orange/Renderer/RendererAPI.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Orange
{

	RendererAPI::API RendererAPI::o_API = RendererAPI::API::OpenGL;

	Scope<RendererAPI> RendererAPI::Create()
	{
		switch (o_API)
		{
		case RendererAPI::API::None: OG_CORE_ASSERT(false, "当前并不支持渲染接口：None!"); return nullptr;
		case RendererAPI::API::OpenGL: return CreateScope<OpenGLRendererAPI>();
		}

		OG_CORE_ASSERT(false, "未知的渲染接口！");
		return nullptr;
	}

}
