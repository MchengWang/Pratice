#pragma once

#include "Orange/Renderer/RendererAPI.h"

namespace Orange
{

	class RenderCommand
	{
	public:
		static void Init()
		{
			o_RendererAPI->Init();
		}

		static void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
		{
			o_RendererAPI->SetViewport(x, y, width, height);
		}

		static void SetClearColor(const glm::vec4& color)
		{
			o_RendererAPI->SetClearColor(color);
		}

		static void Clear()
		{
			o_RendererAPI->Clear();
		}

		static void DrawIndexed(const Ref<VertexArray>& vertexArray, uint32_t indexCount = 0)
		{
			o_RendererAPI->DrawIndexed(vertexArray, indexCount);
		}

		static void DrawLines(const Ref<VertexArray>& vertexArray, uint32_t vertexCount)
		{
			o_RendererAPI->DrawLines(vertexArray, vertexCount);
		}

		static void SetLineWidth(float width)
		{
			o_RendererAPI->SetLineWidth(width);
		}

	private:
		static Scope<RendererAPI> o_RendererAPI;
	};

}
