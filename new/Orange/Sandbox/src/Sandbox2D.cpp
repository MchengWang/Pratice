#include "Sandbox2D.h"
#include <imgui/imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Platform/OpenGL/OpenGLShader.h"

static const uint32_t mapWidth = 24;

// 在 C++ 中 "ssd" "daf" 两段字符串会进行拼接 -> "ssddaf"
static const char* o_MapTiles = 
"WWWWWWWWWWWWWWWWWWWWWWWW"
"WWWWWWWDDDDDDWWWWWWCWWWW"
"WWWWWDDDDDDDDDDDWWWWWWWW"
"WWWWDDDDDDDDDDDDDDWWWWWW"
"WWWDDWWWDDDDDDDDDDDDWWWW"
"WWDDDDDDDDDDDDDDDDDDDWWW"
"WDDDDWWWWWDDDDDDDDDDDDWW"
"WWDDDDDDDDDDDDDDDDDDDWWW"
"WWWDDDDDDDWWWWDDDDDDWWWW"
"WWWWDDDDDDDDDDDDDDWWWWWW"
"WWWWWDDDDDDDDDDDWWWWWWWW"
"WWWWWWDDDDDDWWWWWWWWWWWW"
"WWWWWWWWWWWWWWWWWWWWWWWW"
"WWWWWWWWWWWWWWWWWWWWWWWW"
	;

Sandbox2D::Sandbox2D()
	:Layer("Sandbox2D"), o_CameraController(1280.0f / 720.0f), o_SquareColor({ 0.2f, 0.3f, 0.8f, 1.0f })
{
}

void Sandbox2D::OnAttach()
{
	HZ_PROFILE_FUNCTION();

	o_CheckerboardTexture = Orange::Texture2D::Create("assets/textures/Checkerboard.png");

	//o_SpriteSheet = Orange::Texture2D::Create("assets/game/textures/RPGpack_sheet_2X.png");

	//o_TextureStairs = Orange::SubTexture2D::CreateFromCoords(o_SpriteSheet, { 0, 11 }, { 128, 128 });
	//o_TextureTree = Orange::SubTexture2D::CreateFromCoords(o_SpriteSheet, { 2, 1 }, { 128, 128 }, { 1, 2 });
	//o_TextureBarrel = Orange::SubTexture2D::CreateFromCoords(o_SpriteSheet, { 2, 1 }, { 128, 128 }, { 1, 2 });

	//o_MapWidth = mapWidth;
	//o_MapHeight = strlen(o_MapTiles) / mapWidth;

	//o_TextureMap['D'] = Orange::SubTexture2D::CreateFromCoords(o_SpriteSheet, {6, 11}, {128, 128});
	//o_TextureMap['W'] = Orange::SubTexture2D::CreateFromCoords(o_SpriteSheet, {11, 11}, {128, 128});

	o_Particle.ColorBegin = { 254 / 255.0f, 212 / 255.0f, 123 / 255.0f, 1.0f };
	o_Particle.ColorEnd = { 254 / 255.0f, 109 / 255.0f, 41 / 255.0f, 1.0f };
	o_Particle.SizeBegin = 0.5f, o_Particle.SizeVariation = 0.3f, o_Particle.SizeEnd = 0.0f;
	o_Particle.LifeTime = 1.0f;
	o_Particle.Velocity = { 0.0f, 0.0f };
	o_Particle.VelocityVariation = { 3.0f, 1.0f };
	o_Particle.Position = { 0.0f, 0.0f };

}

void Sandbox2D::OnDetach()
{
	HZ_PROFILE_FUNCTION();
}

void Sandbox2D::OnUpdate(Orange::Timestep timestep)
{
	HZ_PROFILE_FUNCTION();

	// 更新
	o_CameraController.OnUpdate(timestep);


	// 渲染
	Orange::Renderer2D::ResetStats();
	{
		HZ_PROFILE_SCOPE("Renderer-Prep");
		Orange::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Orange::RenderCommand::Clear();
	}

	{
		
		static float rotation = 0.0f;
		rotation += timestep * 50.0f;

		HZ_PROFILE_SCOPE("Renderer Draw");
		Orange::Renderer2D::BeginScene(o_CameraController.GetCamera());
		Orange::Renderer2D::DrawRotatedQuad({ 1.0f, 0.0f }, { 0.8f, 0.8f }, glm::radians(- 45.0f), {0.8f, 0.2f, 0.3f, 1.0f});
		Orange::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.52f, 0.21f, 0.52f, 1.0f });
		Orange::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, o_SquareColor);
		Orange::Renderer2D::DrawRotatedQuad({ 0.25f, 0.5f }, { 0.5f, 0.75f }, glm::radians(90.0f), { 0.52f, 0.21f, 0.52f, 1.0f }); // njucolor
		Orange::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 20.0f, 20.0f }, o_CheckerboardTexture, 10.0f);
		Orange::Renderer2D::DrawRotatedQuad({ -2.0f, 0.0f, 0.0f }, { 1.0f, 1.0f }, glm::radians(rotation), o_CheckerboardTexture, 20.0f);
		Orange::Renderer2D::EndScene();

		Orange::Renderer2D::BeginScene(o_CameraController.GetCamera());
		for (float y = -5.0f; y < 5.0f; y += 0.5f)
		{
			for (float x = -5.0f; x < 5.0f; x += 0.5f)
			{
				glm::vec4 color = { (x + 5.0f) / 10.0f, 0.4f, (y + 5.0f) / 10.0f, 0.7f };
				Orange::Renderer2D::DrawQuad({ x, y }, { 0.45f, 0.45f }, color);
			}
		}
		Orange::Renderer2D::EndScene();
	}


	if (Orange::Input::IsMouseButtonPressed(Orange::Mouse::ButtonLeft))
	{
		glm::vec2& cs = Orange::Input::GetMousePosition();
		auto width = Orange::Application::Get().GetWindow().GetWidth();
		auto height = Orange::Application::Get().GetWindow().GetHeight();

		auto bounds = o_CameraController.GetBounds();
		auto pos = o_CameraController.GetCamera().GetPosition();
		cs.x = (cs.x / width) * bounds.GetWidth() - bounds.GetWidth() * 0.5f;
		cs.y = bounds.GetHeight() * 0.5f - (cs.y / height) * bounds.GetHeight();
		o_Particle.Position = { cs.x + pos.x, cs.y + pos.y };
		for (int i = 0; i < 5; i++)
			o_ParticleSystem.Emit(o_Particle);
	}

	o_ParticleSystem.OnUpdate(timestep);
	o_ParticleSystem.OnRender(o_CameraController.GetCamera());

	Orange::Renderer2D::BeginScene(o_CameraController.GetCamera());

	/*for (uint32_t y = 0; y < o_MapHeight; y++)
	{
		for (uint32_t x = 0; x < o_MapWidth; x++)
		{
			char titleType = o_MapTiles[x + y * o_MapWidth];
			Orange::Ref<Orange::SubTexture2D> texture;
			if (o_TextureMap.find(titleType) != o_TextureMap.end())
				texture = o_TextureMap[titleType];
			else
				texture = o_TextureBarrel;

			Orange::Renderer2D::DrawQuad({ x - o_MapWidth / 2.0f, y - o_MapHeight / 2.0f ,0.5f }, { 1.0f, 1.0f }, texture);
		}
	}*/

	//Orange::Renderer2D::DrawQuad({ 0.0f, 0.0f, 1.0f }, { 1.0f, 1.0f }, o_TextureStairs);
	//Orange::Renderer2D::DrawQuad({ 1.0f, 0.0f, 1.0f }, { 1.0f, 1.0f }, o_TextureBarrel);
	//Orange::Renderer2D::DrawQuad({ -1.0f, 0.0f, 1.0f }, { 1.0f, 2.0f }, o_TextureTree);
	Orange::Renderer2D::EndScene();

}

void Sandbox2D::OnImGuiRender()
{
	HZ_PROFILE_FUNCTION();

	ImGui::Begin("Settings");
	auto stats = Orange::Renderer2D::GetStats();
	ImGui::Text("Renderer2D Stats:");
	ImGui::Text("Draw Calls: %d", stats.DrawCalls);
	ImGui::Text("Quads: %d", stats.QuadCount);
	ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
	ImGui::Text("Indices: %d", stats.GetTotalIndexCount());

		
	ImGui::ColorEdit4("Square Color", glm::value_ptr(o_SquareColor));

	uint32_t textureID = o_CheckerboardTexture->GetRendererID();
	ImGui::Image((void*)textureID, ImVec2{ 1280, 720 });
	ImGui::End();

}

void Sandbox2D::OnEvent(Orange::Event& event)
{
	o_CameraController.OnEvent(event);
}
