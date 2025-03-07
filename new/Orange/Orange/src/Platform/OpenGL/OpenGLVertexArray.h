#pragma once

#include "Orange/Renderer/VertexArray.h"

namespace Orange
{

	class OpenGLVertexArray : public VertexArray
	{
	public:
		OpenGLVertexArray();
		virtual ~OpenGLVertexArray();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual void AddVertexBuffer(const Ref<VertexBuffer>& vertexBuffer) override;
		virtual void SetIndexBuffer(const Ref<IndexBuffer>& indexBuffer) override;

		virtual const std::vector<Ref<VertexBuffer>>& GetVertexBuffers() const { return o_VertexBuffers; }
		virtual const Ref<IndexBuffer>& GetIndexBuffer() const { return o_IndexBuffer; }

	private:
		uint32_t o_RendererID;
		uint32_t o_VertexBufferIndex = 0;
		std::vector<Ref<VertexBuffer>> o_VertexBuffers;
		Ref<IndexBuffer> o_IndexBuffer;

	};

}