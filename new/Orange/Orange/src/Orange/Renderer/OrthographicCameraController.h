#pragma once

#include "Orange/Renderer/OrthographicCamera.h"
#include "Orange/Core/Timestep.h"

#include "Orange/Events/ApplicationEvent.h"
#include "Orange/Events/MouseEvent.h"

namespace Orange
{
	struct OrthographicCameraBounds
	{
		float Left, Right;
		float Bottom, Top;

		float GetWidth() { return Right - Left; }
		float GetHeight() { return Top - Bottom; }
	};

	class OrthographicCameraController
	{
	public:
		OrthographicCameraController(float aspectRatio, bool rotation = false);

		void OnUpdate(Timestep timestep);
		void OnEvent(Event& e);

		void OnResize(float width, float height);

		OrthographicCamera& GetCamera() { return o_Camera; }
		const OrthographicCamera& GetCamera() const { return o_Camera; }

		float GetZoomLevel() const { return o_ZoomLevel; }
		void SetZoomLevel(float zoomLevel) { o_ZoomLevel = zoomLevel; /*CalculateView();*/ }

		const OrthographicCameraBounds& GetBounds() const { return o_Bounds; }

	private:
		void CalculateView();

		bool OnMouseScrolled(MouseScrolledEvent& event);
		bool OnWindowResized(WindowResizeEvent& event);

	private:
		float o_AspectRatio;
		float o_ZoomLevel = 1.0f;
		OrthographicCameraBounds o_Bounds;
		OrthographicCamera o_Camera;

		bool o_Rotation;

		glm::vec3 o_CameraPostion = { 0.0f, 0.0f, 0.0f };
		float o_CameraRotation = 0.0f; // 以度为单位，逆时针方向
		float o_CameraTranslationSpeed = 5.0f, o_CameraRotationSpeed = 180.0f;
	};

}