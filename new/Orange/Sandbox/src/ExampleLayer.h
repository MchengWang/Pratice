#pragma once

#include "Orange.h"

class ExampleLayer : public Orange::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Orange::Timestep timestep) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Orange::Event& event) override;

private:
	Orange::ShaderLibrary o_ShaderLibrary;
	Orange::Ref<Orange::Shader> o_Shader;
	Orange::Ref<Orange::VertexArray> o_VertexArray;

	Orange::Ref<Orange::Shader> o_FlatColorShader;
	Orange::Ref<Orange::VertexArray> o_SquareVA;

	Orange::Ref<Orange::Texture2D> o_Texture, o_OrangeLogoTexture;

	Orange::OrthographicCameraController o_CameraController;
	glm::vec3 o_SquareColor = { 0.2f, 0.3f, 0.8f };
};