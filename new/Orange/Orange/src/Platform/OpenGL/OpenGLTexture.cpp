#include "ogpch.h"
#include "Platform/OpenGL/OpenGLTexture.h"

#include <stb_image.h>

namespace Orange
{

	namespace Utils {
		static GLenum OrangeImageFormatToGLDataFormat(ImageFormat format)
		{
			switch (format)
			{
			case ImageFormat::RGB8:  return GL_RGB;
			case ImageFormat::RGBA8: return GL_RGBA;
			}

			OG_CORE_ASSERT(false);
			return 0;
		}

		static GLenum OrangeImageFormatToGLInternalFormat(ImageFormat format)
		{
			switch (format)
			{
			case ImageFormat::RGB8:  return GL_RGB8;
			case ImageFormat::RGBA8: return GL_RGBA8;
			}

			OG_CORE_ASSERT(false);
			return 0;
		}
	}

	OpenGLTexture2D::OpenGLTexture2D(const TextureSpecification& specification)
		: o_Specification(specification), o_Width(o_Specification.Width), o_Height(o_Specification.Height)
	{
		HZ_PROFILE_FUNCTION();

		o_InternalFormat = Utils::OrangeImageFormatToGLDataFormat(o_Specification.Format);
		o_DataFormat = Utils::OrangeImageFormatToGLDataFormat(o_Specification.Format);

		glCreateTextures(GL_TEXTURE_2D, 1, &o_RendererID);
		glTextureStorage2D(o_RendererID, 1, o_InternalFormat, o_Width, o_Height);

		glTextureParameteri(o_RendererID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(o_RendererID, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTextureParameteri(o_RendererID, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTextureParameteri(o_RendererID, GL_TEXTURE_WRAP_T, GL_REPEAT);
	}

	OpenGLTexture2D::OpenGLTexture2D(const std::string& path)
		: o_Path(path)
	{
		HZ_PROFILE_FUNCTION();

		int width, height, channels;
		stbi_set_flip_vertically_on_load(1);
		stbi_uc* data = nullptr;
		{
			HZ_PROFILE_SCOPE("stbi_load - OpenGLTexture2D::OpenGLTexture2D(const std::string&)");
			data = stbi_load(path.c_str(), &width, &height, &channels, 0);
		}

		if (data)
		{
			o_IsLoaded = true;

			o_Width = width;
			o_Height = height;

			GLenum internalFormat = 0, dataFormat = 0;
			if (channels == 4)
			{
				internalFormat = GL_RGBA8;
				dataFormat = GL_RGBA;
			}
			else if (channels == 3)
			{
				internalFormat = GL_RGB8;
				dataFormat = GL_RGB;
			}

			o_InternalFormat = internalFormat;
			o_DataFormat = dataFormat;

			OG_CORE_ASSERT(internalFormat & dataFormat, "Format not supported!");

			glCreateTextures(GL_TEXTURE_2D, 1, &o_RendererID);
			glTextureStorage2D(o_RendererID, 1, internalFormat, o_Width, o_Height);

			glTextureParameteri(o_RendererID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTextureParameteri(o_RendererID, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			glTextureParameteri(o_RendererID, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTextureParameteri(o_RendererID, GL_TEXTURE_WRAP_T, GL_REPEAT);

			glTextureSubImage2D(o_RendererID, 0, 0, 0, o_Width, o_Height, dataFormat, GL_UNSIGNED_BYTE, data);

			stbi_image_free(data);
		}
	}
	
	OpenGLTexture2D::~OpenGLTexture2D()
	{
		HZ_PROFILE_FUNCTION();

		glDeleteTextures(1, &o_RendererID);
	}

	void OpenGLTexture2D::SetData(void* data, uint32_t size)
	{
		HZ_PROFILE_FUNCTION();

		uint32_t bpp = o_DataFormat == GL_RGBA ? 4 : 3;
		OG_CORE_ASSERT(size == o_Width * o_Height * bpp, "Data must be entire texture!");
		glTextureSubImage2D(o_RendererID, 0, 0, 0, o_Width, o_Height, o_DataFormat, GL_UNSIGNED_BYTE, data);
	}

	void OpenGLTexture2D::Bind(uint32_t slot) const
	{
		HZ_PROFILE_FUNCTION();

		glBindTextureUnit(slot, o_RendererID);
	}

}
