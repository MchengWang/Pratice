#pragma once

#include "Orange/Renderer/Camera.h"

namespace Orange
{

	class SceneCamera : public Camera
	{
	public:
		enum class ProjectionType { Perspective = 0, Orthographic = 1};
	public:
		SceneCamera();
		virtual ~SceneCamera() = default;

		void SetPerspective(float verticalFOV, float nearClip, float farClip);
		void SetOrthographic(float size, float nearClip, float farClip);

		void SetViewportSize(uint32_t width, uint32_t height);

		float GetPerspectiveVerticalFOV() const { return o_PerspectiveFOV; }
		void SetPerspectiveVerticalFOV(float verticalFov) { o_PerspectiveFOV = verticalFov; RecalculateProjection(); }
		float GetPerspectiveNearClip() const { return o_PerspectiveNear; }
		void SetPerspectiveNearClip(float nearClip) { o_PerspectiveNear = nearClip; RecalculateProjection(); }
		float GetPerspectiveFarClip() const { return o_PerspectiveFar; }
		void SetPerspectiveFarClip(float farClip) { o_PerspectiveFar = farClip; RecalculateProjection(); }

		float GetOrthographicSize() const { return o_OrthographicSize; }
		void SetOrthographicSize(float size) { o_OrthographicSize = size; RecalculateProjection(); }
		float GetOrthographicNearClip() const { return o_OrthographicNear; }
		void SetOrthographicNearClip(float nearClip) { o_OrthographicNear = nearClip; RecalculateProjection(); }
		float GetOrthographicFarClip() const { return o_OrthographicFar; }
		void SetOrthographicFarClip(float farClip) { o_OrthographicFar = farClip; RecalculateProjection(); }

		ProjectionType GetProjectionType() const { return o_ProjectionType; }
		void SetProjectionType(ProjectionType type) { o_ProjectionType = type; RecalculateProjection(); }

	private:
		void RecalculateProjection();

	private:
		ProjectionType o_ProjectionType = ProjectionType::Orthographic;

		float o_PerspectiveFOV = glm::radians(45.0f);
		float o_PerspectiveNear = 0.01f, o_PerspectiveFar = 1000.0f;

		float o_OrthographicSize = 10.0f;
		float o_OrthographicNear = -1.0f, o_OrthographicFar = 1.0f;

		float o_AspectRatio = 0.0f;
	};

}
