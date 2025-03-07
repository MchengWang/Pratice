#pragma once

#include "Orange.h"
#include "Panels/SceneHierarchyPanel.h"
#include "Panels/ContentBrowserPanel.h"

#include "Orange/Renderer/EditorCamera.h"

namespace Orange
{

	class EditorLayer : public Layer
	{
	public:
		EditorLayer();
		virtual ~EditorLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void OnUpdate(Timestep timestep) override;
		virtual void OnImGuiRender() override;
		void OnEvent(Event& event) override;

	private:
		bool OnKeyPressed(KeyPressedEvent& event);
		bool OnMouseButtonPressed(MouseButtonPressedEvent& event);

		void OnOverlayRender();

		void NewProject();
		bool OpenProject();
		void OpenProject(const std::filesystem::path& path);
		void SaveProject();

		void NewScene();
		void OpenScene();
		void OpenScene(const std::filesystem::path& path);
		void SaveScene();
		void SaveSceneAs();

		void SerializeScene(Ref<Scene> scene, const std::filesystem::path& path);

		void OnScenePlay();
		void OnSceneSimulate();
		void OnSceneStop();
		void OnScenePause();

		void OnDuplicateEntity();

		// UI Panels
		void UI_Toolbar();

	private:
		OrthographicCameraController o_CameraController;

		// ¡Ÿ ±
		Ref<VertexArray> o_SquareVA;
		Ref<Shader> o_FlatColorShader;
		Ref<Framebuffer> o_Framebuffer;

		Ref<Scene> o_ActiveScene;
		Ref<Scene> o_EditorScene;
		std::filesystem::path o_EditorScenePath;
		Entity o_SquareEntity;
		Entity o_CameraEntity;
		Entity o_SecondCamera;

		Entity o_HoveredEntity;

		bool o_PrimaryCamera = true;

		EditorCamera o_EditorCamera;

		Ref<Texture2D> o_CheckerboardTexture;

		bool o_ViewportFocused = false, o_ViewportHovered = false;

		glm::vec2 o_ViewportSize = { 0.0f, 0.0f };
		glm::vec2 o_ViewportBounds[2];

		glm::vec4 o_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };

		int o_GizmoType = -1;

		bool o_ShowPhysicsColliders = false;

		enum class SceneState
		{
			Edit = 0, Play = 1, Simulate = 2
		};

		SceneState o_SceneState = SceneState::Edit;

		// √Ê∞Â
		SceneHierarchyPanel o_SceneHierarchyPanel;
		Scope<ContentBrowerPanel> o_ContentBrowserPanel;

		// Editor resources
		Ref<Texture2D> o_IconPlay, o_IconPause, o_IconStep, o_IconSimulate, o_IconStop;
	};

}
