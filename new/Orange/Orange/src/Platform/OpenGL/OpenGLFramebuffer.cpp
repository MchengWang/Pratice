#include "ogpch.h"
#include "Platform/OpenGL/OpenGLFramebuffer.h"

#include <glad/glad.h>

namespace Orange
{

	static const uint32_t s_MaxFramebufferSize = 8192;

	namespace Utils
	{

		static GLenum TextureTarget(bool multisampled)
		{
			return multisampled ? GL_TEXTURE_2D_MULTISAMPLE : GL_TEXTURE_2D;
		}

		static void CreateTextures(bool multisampled, uint32_t* outID, uint32_t count)
		{
			glCreateTextures(TextureTarget(multisampled), count, outID);
		}

		static void BindTexture(bool multisampled, uint32_t id)
		{
			glBindTexture(TextureTarget(multisampled), id);
		}

		static void AttachColorTexture(uint32_t id, int samples, GLenum internalFormat, GLenum format, uint32_t width, uint32_t height, int index)
		{
			bool multisampled = samples > 1;

			if (multisampled)
			{
				glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, samples, internalFormat, width, height, GL_FALSE);
			}
			else
			{
				glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, format, GL_UNSIGNED_BYTE, nullptr);

				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			}

			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + index, TextureTarget(multisampled), id, 0);
		}

		static void AttachDepthTexture(uint32_t id, int samples, GLenum format, GLenum attachmentType, uint32_t width, uint32_t height)
		{
			bool multisampled = samples > 1;

			if (multisampled)
			{
				glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, samples, format, width, height, GL_FALSE);
			}
			else
			{
				glTexStorage2D(GL_TEXTURE_2D, 1, format, width, height);

				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			}

			glFramebufferTexture2D(GL_FRAMEBUFFER, attachmentType, TextureTarget(multisampled), id, 0);
		}

		static bool IsDepthFormat(FramebufferTextureFormat format)
		{
			switch (format)
			{
			case FramebufferTextureFormat::None:
			case FramebufferTextureFormat::RGBA8:
				return false;
			case FramebufferTextureFormat::DEPTH24STENCIL8:
				return true;
			}

			return false;
		}

		static GLenum OrangeFBTextureFormatToGL(FramebufferTextureFormat format)
		{
			switch (format)
			{
				case FramebufferTextureFormat::RGBA8:       return GL_RGBA8;
				case FramebufferTextureFormat::RED_INTEGET: return GL_RED_INTEGER;
			}

			OG_CORE_ASSERT(false);
			return 0;
		}

	}

	OpenGLFramebuffer::OpenGLFramebuffer(const FramebufferSpecification& spec)
		:o_Specification(spec)
	{
		for (auto spec : o_Specification.Attachments.Attachments)
		{
			if (!Utils::IsDepthFormat(spec.TextureFormat))
				o_ColorAttachmentSpecifications.emplace_back(spec);
			else
				o_DepthAttachmentSpecification = spec;
		}

		Invalidate();
	}

	OpenGLFramebuffer::~OpenGLFramebuffer()
	{
		glDeleteFramebuffers(1, &o_RendererID);
		glDeleteTextures(o_ColorAttachments.size(), o_ColorAttachments.data());
		glDeleteTextures(1, &o_DepathAttachment);
	}

	void OpenGLFramebuffer::Invalidate()
	{
		if (o_RendererID)
		{
			glDeleteFramebuffers(1, &o_RendererID);
			glDeleteTextures(o_ColorAttachments.size(), o_ColorAttachments.data());
			glDeleteTextures(1, &o_DepathAttachment);

			o_ColorAttachments.clear();
			o_DepathAttachment = 0;
		}

		glCreateFramebuffers(1, &o_RendererID);
		glBindFramebuffer(GL_FRAMEBUFFER, o_RendererID);

		bool multisample = o_Specification.Samples > 1;

		// 附件
		if (o_ColorAttachmentSpecifications.size())
		{
			o_ColorAttachments.resize(o_ColorAttachmentSpecifications.size());
			Utils::CreateTextures(multisample, o_ColorAttachments.data(), o_ColorAttachments.size());

			for (size_t i = 0; i < o_ColorAttachments.size(); i++)
			{
				Utils::BindTexture(multisample, o_ColorAttachments[i]);
				switch (o_ColorAttachmentSpecifications[i].TextureFormat)
				{
				case FramebufferTextureFormat::RGBA8:
					Utils::AttachColorTexture(o_ColorAttachments[i], o_Specification.Samples, GL_RGBA8, GL_RGBA, o_Specification.Width, o_Specification.Height, i);
					break;
				case FramebufferTextureFormat::RED_INTEGET:
					Utils::AttachColorTexture(o_ColorAttachments[i], o_Specification.Samples, GL_R32I, GL_RED_INTEGER, o_Specification.Width, o_Specification.Height, i);
					break;
				}
			}
		}

		if (o_DepthAttachmentSpecification.TextureFormat != FramebufferTextureFormat::None)
		{
			Utils::CreateTextures(multisample, &o_DepathAttachment, 1);
			Utils::BindTexture(multisample, o_DepathAttachment);
			switch (o_DepthAttachmentSpecification.TextureFormat)
			{
			case FramebufferTextureFormat::DEPTH24STENCIL8:
				Utils::AttachDepthTexture(o_DepathAttachment, o_Specification.Samples, GL_DEPTH24_STENCIL8, GL_DEPTH_STENCIL_ATTACHMENT, o_Specification.Width, o_Specification.Height);
				break;
			}
		}

		if (o_ColorAttachments.size() > 1)
		{
			OG_CORE_ASSERT(o_ColorAttachments.size() <= 4);
			GLenum buffers[4] = { GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1, GL_COLOR_ATTACHMENT2, GL_COLOR_ATTACHMENT3 };
			glDrawBuffers(o_ColorAttachments.size(), buffers);
		}
		else if (o_ColorAttachments.empty())
		{
			// 仅深度通道
			glDrawBuffer(GL_NONE);
		}

		OG_CORE_ASSERT(glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE, "帧缓冲区不完整！");

		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	void OpenGLFramebuffer::Bind()
	{
		glBindFramebuffer(GL_FRAMEBUFFER, o_RendererID);
		glViewport(0, 0, o_Specification.Width, o_Specification.Height);
	}

	void OpenGLFramebuffer::Unbind()
	{
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	void OpenGLFramebuffer::Resize(uint32_t width, uint32_t height)
	{
		if (width == 0 || height == 0 || width > s_MaxFramebufferSize || height > s_MaxFramebufferSize)
		{
			OG_CORE_WARN("尝试将帧缓冲大小调整为 {0}、{1}", width, height);
			return;
		}

		o_Specification.Width = width;
		o_Specification.Height = height;

		Invalidate();
	}

	int OpenGLFramebuffer::ReadPixel(uint32_t attachmentIndex, int x, int y)
	{
		OG_CORE_ASSERT(attachmentIndex < o_ColorAttachments.size());

		glReadBuffer(GL_COLOR_ATTACHMENT0 + attachmentIndex);
		int pixelData;
		glReadPixels(x, y, 1, 1, GL_RED_INTEGER, GL_INT, &pixelData);
		return pixelData;
	}

	void OpenGLFramebuffer::ClearAttachment(uint32_t attachmentIndex, int value)
	{
		OG_CORE_ASSERT(attachmentIndex < o_ColorAttachments.size());

		auto& spec = o_ColorAttachmentSpecifications[attachmentIndex];
		glClearTexImage(o_ColorAttachments[attachmentIndex], 0, Utils::OrangeFBTextureFormatToGL(spec.TextureFormat),
			GL_INT, &value);
	}

}
