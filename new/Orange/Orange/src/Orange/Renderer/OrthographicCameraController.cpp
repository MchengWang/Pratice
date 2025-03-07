#include "ogpch.h"
#include "Orange/Renderer/OrthographicCameraController.h"

#include "Orange/Core/Input.h"
#include "Orange/Core/KeyCodes.h"

namespace Orange
{

	OrthographicCameraController::OrthographicCameraController(float aspectRatio, bool rotation)
		:o_AspectRatio(aspectRatio), o_Camera(-o_AspectRatio * o_ZoomLevel, o_AspectRatio* o_ZoomLevel, -o_ZoomLevel, o_ZoomLevel),
		o_Bounds({ -o_AspectRatio * o_ZoomLevel, o_AspectRatio * o_ZoomLevel, -o_ZoomLevel, o_ZoomLevel }), o_Rotation(rotation)
	{
	}

	void OrthographicCameraController::OnUpdate(Timestep timestep)
	{
		HZ_PROFILE_FUNCTION();

		if (Input::IsKeyPressed(Key::A))
		{
			o_CameraPostion.x -= cos(glm::radians(o_CameraRotation) * o_CameraTranslationSpeed * timestep);
			o_CameraPostion.y -= sin(glm::radians(o_CameraRotation) * o_CameraTranslationSpeed * timestep);
		}
		else if (Input::IsKeyPressed(Key::D))
		{
			o_CameraPostion.x += cos(glm::radians(o_CameraRotation) * o_CameraTranslationSpeed * timestep);
			o_CameraPostion.y += sin(glm::radians(o_CameraRotation) * o_CameraTranslationSpeed * timestep);
		}

		if (Input::IsKeyPressed(Key::W))
		{
			o_CameraPostion.x += -sin(glm::radians(o_CameraRotation) * o_CameraTranslationSpeed * timestep);
			o_CameraPostion.y += cos(glm::radians(o_CameraRotation) * o_CameraTranslationSpeed * timestep);
		}
		else if (Input::IsKeyPressed(Key::S))
		{
			o_CameraPostion.x -= -sin(glm::radians(o_CameraRotation) * o_CameraTranslationSpeed * timestep);
			o_CameraPostion.y -= cos(glm::radians(o_CameraRotation) * o_CameraTranslationSpeed * timestep);
		}

		if (o_Rotation)
		{
			if (Input::IsKeyPressed(Key::Q))
				o_CameraRotation += o_CameraRotationSpeed * timestep;
			else if (Input::IsKeyPressed(Key::E))
				o_CameraRotation -= o_CameraRotationSpeed * timestep;

			if (o_CameraRotation > 180.0f)
				o_CameraRotation -= 360.0f;
			else if (o_CameraRotation <= -180.0f)
				o_CameraRotation += 360.0f;

			o_Camera.SetRotation(o_CameraRotation);
		}

		o_Camera.SetPosition(o_CameraPostion);

		o_CameraTranslationSpeed = o_ZoomLevel;
	}

	void OrthographicCameraController::OnEvent(Event& event)
	{
		HZ_PROFILE_FUNCTION();

		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<MouseScrolledEvent>(OG_BIND_EVENT_FN(OrthographicCameraController::OnMouseScrolled));
		dispatcher.Dispatch<WindowResizeEvent>(OG_BIND_EVENT_FN(OrthographicCameraController::OnWindowResized));
	}

	void OrthographicCameraController::CalculateView()
	{
		o_Bounds = { -o_AspectRatio * o_ZoomLevel, o_AspectRatio * o_ZoomLevel, -o_ZoomLevel, o_ZoomLevel };
		o_Camera.SetProjection(o_Bounds.Left, o_Bounds.Right, o_Bounds.Bottom, o_Bounds.Top);
	}

	void OrthographicCameraController::OnResize(float width, float height)
	{
		o_AspectRatio = width / height;
		o_Camera.SetProjection(-o_AspectRatio * o_ZoomLevel, o_AspectRatio * o_ZoomLevel, -o_ZoomLevel, o_ZoomLevel);
	}

	bool OrthographicCameraController::OnMouseScrolled(MouseScrolledEvent& event)
	{ 
		HZ_PROFILE_FUNCTION();

		o_ZoomLevel -= event.GetOffsetY() * 0.25f;
		o_ZoomLevel = std::max(o_ZoomLevel, 0.25f);
		o_Camera.SetProjection(-o_AspectRatio * o_ZoomLevel, o_AspectRatio * o_ZoomLevel, -o_ZoomLevel, o_ZoomLevel);
		return false;
	}

	bool OrthographicCameraController::OnWindowResized(WindowResizeEvent& event)
	{
		HZ_PROFILE_FUNCTION();

		OnResize((float)event.GetWidth(), (float)event.GetHeight());
		return false;
	}

}