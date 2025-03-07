#include "ogpch.h"
#include "OpenGLUniformBuffer.h"

#include <glad/glad.h>

namespace Orange
{

	OpenGLUniformBuffer::OpenGLUniformBuffer(uint32_t size, uint32_t binding)
	{
		glCreateBuffers(1, &o_RendererID);
		glNamedBufferData(o_RendererID, size, nullptr, GL_DYNAMIC_DRAW); // TODO: 调查使用提示
		glBindBufferBase(GL_UNIFORM_BUFFER, binding, o_RendererID);
	}

	OpenGLUniformBuffer::~OpenGLUniformBuffer()
	{
		glDeleteBuffers(1, &o_RendererID);
	}

	void OpenGLUniformBuffer::SetData(const void* data, uint32_t size, uint32_t offset)
	{
		glNamedBufferSubData(o_RendererID, offset, size, data);
	}

}
