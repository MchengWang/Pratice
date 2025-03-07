#include "ogpch.h"
#include "UniformBuffer.h"

#include "Orange/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLUniformBuffer.h"

namespace Orange
{

	Ref<UniformBuffer> UniformBuffer::Create(uint32_t size, uint32_t binding)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: OG_CORE_ASSERT(false, "当前并不支持渲染接口：None!"); return nullptr;
		case RendererAPI::API::OpenGL: return CreateRef<OpenGLUniformBuffer>(size, binding);
		}

		OG_CORE_ASSERT(false, "未知的渲染接口！");
		return nullptr;
	}

}
