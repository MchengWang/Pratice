#include "ExampleLayer.h"
#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

ExampleLayer::ExampleLayer()
	: Layer("Example"), o_CameraController(1280.0f / 720.0f)
{
	o_VertexArray = Orange::VertexArray::Create();

	float vertices[3 * 7] = {
		-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
		 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
		 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
	};

	Orange::Ref<Orange::VertexBuffer> vertexBuffer = Orange::VertexBuffer::Create(vertices, sizeof(vertices));
	Orange::BufferLayout layout = {
		{ Orange::ShaderDataType::Float3, "a_Position"},
		{ Orange::ShaderDataType::Float4, "a_Color"}
	};

	vertexBuffer->SetLayout(layout);
	o_VertexArray->AddVertexBuffer(vertexBuffer);

	uint32_t indices[3] = { 0, 1, 2 };
	Orange::Ref<Orange::IndexBuffer> indexBuffer = Orange::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t));
	o_VertexArray->SetIndexBuffer(indexBuffer);

	o_SquareVA = Orange::VertexArray::Create();

	float squareVertices[5 * 4] = {
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
		 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
		-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
	};

	Orange::Ref<Orange::VertexBuffer> squareVB = Orange::VertexBuffer::Create(squareVertices, sizeof(squareVertices));

	squareVB->SetLayout({
		{ Orange::ShaderDataType::Float3, "a_Position" },
		{ Orange::ShaderDataType::Float2, "a_TexCoord" }
		});

	o_SquareVA->AddVertexBuffer(squareVB);

	uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
	Orange::Ref<Orange::IndexBuffer> squareIB = Orange::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t));
	o_SquareVA->SetIndexBuffer(squareIB);

	std::string vertSrc = R"(
	
			#version 430 core
			
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);	
			}

		)";

	std::string fragSrc = R"(
	
			#version 430 core
			
			layout(location = 0) out vec4 color;

			in vec3 v_Position;
			in vec4 v_Color;

			void main()
			{
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
				color = v_Color;
			}

		)";

	o_Shader = Orange::Shader::Create("VertexPosColor", vertSrc, fragSrc);

	std::string flatColorShaderVertexSrc = R"(
	
			#version 430 core
			
			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;

			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);	
			}

		)";

	std::string flatColorShaderFragmentSrc = R"(
	
			#version 430 core
			
			layout(location = 0) out vec4 color;

			in vec3 v_Position;
			
			uniform vec3 u_Color;

			void main()
			{
				color = vec4(u_Color, 1.0);
			}

		)";

	o_FlatColorShader = Orange::Shader::Create("FlatColor", flatColorShaderVertexSrc, flatColorShaderFragmentSrc);

	auto textureShader = o_ShaderLibrary.Load("assets/shaders/Texture.gsc");

	o_Texture = Orange::Texture2D::Create("assets/textures/Checkerboard.png");
	o_OrangeLogoTexture = Orange::Texture2D::Create("assets/textures/LogoO.png");

	textureShader->Bind();
	textureShader->SetInt("u_Texture", 0);
}

void ExampleLayer::OnAttach()
{
}

void ExampleLayer::OnDetach()
{
}

void ExampleLayer::OnUpdate(Orange::Timestep timestep)
{
	// 更新
	o_CameraController.OnUpdate(timestep);

	// 渲染
	Orange::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
	Orange::RenderCommand::Clear();

	Orange::Renderer::BeginScene(o_CameraController.GetCamera());

	glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

	o_FlatColorShader->Bind();
	o_FlatColorShader->SetFloat3("u_Color", o_SquareColor);

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			glm::vec3 pos(j * 0.11f, i * 0.11f, 0.0f);
			glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
			Orange::Renderer::Submit(o_FlatColorShader, o_SquareVA, transform);
		}
	}
	auto textureShader = o_ShaderLibrary.Get("Texture");

	o_Texture->Bind();
	Orange::Renderer::Submit(textureShader, o_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

	o_OrangeLogoTexture->Bind();
	Orange::Renderer::Submit(textureShader, o_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

	// 三角形
	//Orange::Renderer::Submit(o_Shader, o_VertexArray);

	Orange::Renderer::EndScene();
}

void ExampleLayer::OnImGuiRender() 
{
	ImGui::Begin("Settings");
	ImGui::ColorEdit3("Square Color:", glm::value_ptr(o_SquareColor));
	ImGui::End();
}

void ExampleLayer::OnEvent(Orange::Event& event)
{
	o_CameraController.OnEvent(event);
}