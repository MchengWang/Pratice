#include "ogpch.h"

#include "Orange/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace Orange
{

	Ref<Shader> Shader::Create(const std::string& filepath)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: OG_CORE_ASSERT(false, "当前暂不支持渲染接口：None！"); return nullptr;
		case RendererAPI::API::OpenGL: return CreateRef<OpenGLShader>(filepath);
		}

		OG_CORE_ASSERT(false, "未知的渲染接口！");
		return nullptr;
	}

	Ref<Shader> Shader::Create(const std::string& name, const std::string& vertSrc, const std::string& fragSrc)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: OG_CORE_ASSERT(false, "当前暂不支持渲染接口：None！"); return nullptr;
		case RendererAPI::API::OpenGL: return CreateRef<OpenGLShader>(name, vertSrc, fragSrc);
		}

		OG_CORE_ASSERT(false, "未知的渲染接口！");
		return nullptr;
	}

	void ShaderLibrary::Add(const std::string& name, const Ref<Shader>& shader)
	{
		OG_CORE_ASSERT(!Exists(name), "着色器已经存在！");
		o_Shaders[name] = shader;
	}

	void ShaderLibrary::Add(const Ref<Shader>& shader)
	{
		auto& name = shader->GetName();
		Add(name, shader);
	}

	Ref<Shader> ShaderLibrary::Load(const std::string& filepath)
	{
		auto shader = Shader::Create(filepath);
		Add(shader);
		return shader;
	}

	Ref<Shader> ShaderLibrary::Load(const std::string& name, const std::string& filepath)
	{
		auto shader = Shader::Create(filepath);
		Add(name, shader);
		return shader;
	}

	Ref<Shader> ShaderLibrary::Get(const std::string& name)
	{
		OG_CORE_ASSERT(Exists(name), "找不到着色器！");
		return o_Shaders[name];
	}

	bool ShaderLibrary::Exists(const std::string& name) const
	{
		return o_Shaders.find(name) != o_Shaders.end();
	}
}