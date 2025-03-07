#pragma once

#include "RenderCommand.h"

#include "Orange/Renderer/OrthographicCamera.h"
#include "Orange/Renderer/Shader.h"

namespace Orange
{

	class Renderer
	{
	public:
		static void Init();
		static void Shutdown();

		static void OnWindowResized(uint32_t width, uint32_t height);

		static void BeginScene(OrthographicCamera& camera);
		static void EndScene();

		static void Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray, const glm::mat4& transform = glm::mat4(0.1f));

		static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }

	private:
		struct SceneData
		{
			glm::mat4 ViewProjMatrix;
		};

		static Scope<SceneData> o_SceneData;
	};

}