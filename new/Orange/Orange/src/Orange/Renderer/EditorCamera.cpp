#include "ogpch.h"
#include "EditorCamera.h"

#include "Orange/Core/Input.h"
#include "Orange/Core/KeyCodes.h"
#include "Orange/Core/MouseCodes.h"

#include <GLFW/glfw3.h>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>

namespace Orange
{

	EditorCamera::EditorCamera(float fov, float aspectRatio, float nearClip, float farClip)
		:o_FOV(fov), o_AspectRatio(aspectRatio), o_NearClip(nearClip), o_FarClip(farClip), Camera(glm::perspective(glm::radians(fov),
			aspectRatio, nearClip, farClip))
	{
		UpdateView();
	}

	void EditorCamera::UpdateProjection()
	{
		o_AspectRatio = o_ViewportWidth / o_ViewportHeight;
		o_Projection = glm::perspective(glm::radians(o_FOV), o_AspectRatio, o_NearClip, o_FarClip);
	}

	void EditorCamera::UpdateView()
	{
		//o_Yaw = o_Pitch = 0.0f; // Lock the Camera's rotation
		o_Position = CalculatePosition();

		glm::quat orientation = GetOrientation();
		o_ViewMatrix = glm::translate(glm::mat4(1.0f), o_Position) * glm::toMat4(orientation);
		o_ViewMatrix = glm::inverse(o_ViewMatrix);
	}

	std::pair<float, float> EditorCamera::PanSpeed() const
	{
		float x = std::min(o_ViewportWidth / 1000.0f, 2.4f); // Max = 2.4f
		float xFactor = 0.0366f * (x * x) - 0.1778f * x + 0.3021f;

		float y = std::min(o_ViewportHeight / 1000.0f, 2.4f); // Max = 2.4f
		float yFactor = 0.0366f * (y * y) - 0.1778f * y + 0.3021f;

		return { xFactor, yFactor };
	}

	float EditorCamera::RotationSpeed() const
	{
		return 0.8f;
	}

	float EditorCamera::ZoomSpeed() const
	{
		float distance = o_Distance * 0.2f;
		distance = std::max(distance, 0.0f);
		float speed = distance * distance;
		speed = std::min(speed, 100.0f); // Max speed = 100
		return speed;
	}

	void EditorCamera::OnUpdate(Timestep timestep)
	{
		if (Input::IsKeyPressed(Key::LeftAlt))
		{
			const glm::vec2& mouse{ Input::GetMouseX(), Input::GetMouseY() };
			glm::vec2 delta = (mouse - o_InitialMousePosition) * 0.003f;
			o_InitialMousePosition = mouse;

			if (Input::IsMouseButtonPressed(Mouse::ButtonMiddle))
				MousePan(delta);
			else if (Input::IsMouseButtonPressed(Mouse::ButtonLeft))
				MouseRotate(delta);
			else if (Input::IsMouseButtonPressed(Mouse::ButtonRight))
				MouseZoom(delta.y);
		}

		UpdateView();
	}

	void EditorCamera::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<MouseScrolledEvent>(OG_BIND_EVENT_FN(EditorCamera::OnMouseScroll));
	}

	bool EditorCamera::OnMouseScroll(MouseScrolledEvent& event)
	{
		float delta = event.GetOffsetY() * 0.1f;
		MouseZoom(delta);
		UpdateView();
		return false;
	}

	void EditorCamera::MousePan(const glm::vec2& delta)
	{
		auto [xSpeed, ySpeed] = PanSpeed();
		o_FocalPoint += -GetRightDirection() * delta.x * xSpeed * o_Distance;
		o_FocalPoint += GetUpDirection() * delta.y * ySpeed * o_Distance;
	}

	void EditorCamera::MouseRotate(const glm::vec2& delta)
	{
		float yawSign = GetUpDirection().y < 0 ? -1.0f : 1.0f;
		o_Yaw += yawSign * delta.x * RotationSpeed();
		o_Pitch += delta.y * RotationSpeed();
	}

	void EditorCamera::MouseZoom(float delta)
	{
		o_Distance -= delta * ZoomSpeed();
		if (o_Distance < 1.0f)
		{
			o_FocalPoint += GetForwardDirection();
			o_Distance = 1.0f;
		}
	}

	glm::vec3 EditorCamera::GetUpDirection() const
	{
		return glm::rotate(GetOrientation(), glm::vec3(0.0f, 1.0f, 0.0f));
	}

	glm::vec3 EditorCamera::GetRightDirection() const
	{
		return glm::rotate(GetOrientation(), glm::vec3(1.0f, 0.0f, 0.0f));
	}

	glm::vec3 EditorCamera::GetForwardDirection() const
	{
		return glm::rotate(GetOrientation(), glm::vec3(0.0f, 0.0f, -1.0f));
	}

	glm::vec3 EditorCamera::CalculatePosition() const
	{
		return o_FocalPoint - GetForwardDirection() * o_Distance;
	}

	glm::quat EditorCamera::GetOrientation() const
	{
		return glm::quat(glm::vec3(-o_Pitch, -o_Yaw, 0.0f));
	}
}
