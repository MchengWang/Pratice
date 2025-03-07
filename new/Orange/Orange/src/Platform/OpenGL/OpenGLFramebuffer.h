#pragma once

#include "Orange/Renderer/FrameBuffer.h"

namespace Orange
{

	class OpenGLFramebuffer : public Framebuffer
	{
	public:
		OpenGLFramebuffer(const FramebufferSpecification& spec);
		virtual ~OpenGLFramebuffer();

		void Invalidate();

		virtual void Bind() override;
		virtual void Unbind() override;

		virtual void Resize(uint32_t width, uint32_t height) override;
		virtual int ReadPixel(uint32_t attachmentIndex, int x, int y) override;

		virtual void ClearAttachment(uint32_t attachmentIndex, int value) override;

		virtual uint32_t GetColorAttachmentRendererID(const uint32_t index = 0) const override {OG_CORE_ASSERT(index < o_ColorAttachments.size()); return o_ColorAttachments[index]; }

		virtual const FramebufferSpecification& GetSpecification() const override { return o_Specification; }

	private:
		uint32_t o_RendererID = 0;
		FramebufferSpecification o_Specification;

		std::vector<FramebufferTextureSpecification> o_ColorAttachmentSpecifications;
		FramebufferTextureSpecification o_DepthAttachmentSpecification = FramebufferTextureFormat::None;

		std::vector<uint32_t> o_ColorAttachments;
		uint32_t o_DepathAttachment = 0;
	};

}
