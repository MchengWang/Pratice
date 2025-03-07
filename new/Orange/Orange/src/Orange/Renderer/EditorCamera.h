#pragma once

#include "Camera.h"
#include "Orange/Core/Timestep.h"
#include "Orange/Events/Event.h"
#include "Orange/Events/MouseEvent.h"

#include <glm/glm.hpp>

namespace Orange
{

	class EditorCamera : public Camera
	{
	public:
		EditorCamera() = default;
		EditorCamera(float fov, float aspectRatio, float nearClip, float farClip);

		void OnUpdate(Timestep timestep);
		void OnEvent(Event& event);

		inline float GetDistance() const { return o_Distance; }
		inline void SetDistance(float distance) { o_Distance = distance; }

		inline void SetViewportSize(float width, float height) { o_ViewportWidth = width; o_ViewportHeight = height; UpdateProjection(); }

		const glm::mat4& GetViewMatrix() const { return o_ViewMatrix; }
		glm::mat4 GetViewProjection() const { return o_Projection * o_ViewMatrix; }

		glm::vec3 GetUpDirection() const;
		glm::vec3 GetRightDirection() const;
		glm::vec3 GetForwardDirection() const;

		const glm::vec3& GetPosition() const { return o_Position; }
		glm::quat GetOrientation() const;

		float GetPitch() const { return o_Pitch; }
		float GetYaw() const { return o_Yaw; }

	private:
		void UpdateProjection();
		void UpdateView();

		bool OnMouseScroll(MouseScrolledEvent& event);

		void MousePan(const glm::vec2& delta);
		void MouseRotate(const glm::vec2& delta);
		void MouseZoom(float delta);

		glm::vec3 CalculatePosition() const;

		std::pair<float, float> PanSpeed() const;
		float RotationSpeed() const;
		float ZoomSpeed() const;

	private:
		float o_FOV = 45.0f, o_AspectRatio = 1.778f, o_NearClip = 0.1f, o_FarClip = 1000.0f;

		glm::mat4 o_ViewMatrix;
		glm::vec3 o_Position = { 0.0f, 0.0f, 0.0f };
		glm::vec3 o_FocalPoint = { 0.0f, 0.0f, 0.0f };

		glm::vec2 o_InitialMousePosition = { 0.0f, 0.0f };

		float o_Distance = 10.0f;
		float o_Pitch = 0.0f, o_Yaw = 0.0f;

		float o_ViewportWidth = 1280, o_ViewportHeight = 720;

	};

}
