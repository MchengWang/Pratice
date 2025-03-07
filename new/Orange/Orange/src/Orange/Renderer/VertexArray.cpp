#include "ogpch.h"
#include "Orange/Renderer/VertexArray.h"

#include "Orange/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Orange
{

	Ref<VertexArray> VertexArray::Create()
	{ 
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: OG_CORE_ASSERT(false, "当前渲染接口：None 暂不支持！"); return nullptr;
		case RendererAPI::API::OpenGL: return CreateRef<OpenGLVertexArray>();
		}

		OG_CORE_ASSERT(false, "未知的渲染器接口！");
		return nullptr;
	}

}