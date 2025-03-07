#include "ogpch.h"
#include "SceneCamera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace Orange
{

	SceneCamera::SceneCamera()
	{
		RecalculateProjection();
	}

	void SceneCamera::SetPerspective(float verticalFOV, float nearClip, float farClip)
	{
		o_ProjectionType = ProjectionType::Perspective;
		o_PerspectiveFOV = verticalFOV;
		o_PerspectiveNear = nearClip;
		o_PerspectiveFar = farClip;

		RecalculateProjection();
	}

	void SceneCamera::SetOrthographic(float size, float nearClip, float farClip)
	{
		o_ProjectionType = ProjectionType::Orthographic;
		o_OrthographicSize = size;
		o_OrthographicNear = nearClip;
		o_OrthographicFar = farClip;

		RecalculateProjection();
	}

	void SceneCamera::SetViewportSize(uint32_t width, uint32_t height)
	{
		OG_CORE_ASSERT(width > 0 && height > 0);
		o_AspectRatio = (float)width / (float)height;
		RecalculateProjection();
	}

	void SceneCamera::RecalculateProjection()
	{
		switch (o_ProjectionType)
		{
		case Orange::SceneCamera::ProjectionType::Perspective:
		{
			o_Projection = glm::perspective(o_PerspectiveFOV, o_AspectRatio, o_PerspectiveNear, o_PerspectiveFar);
			break;
		}
		case Orange::SceneCamera::ProjectionType::Orthographic:
		{
			float orthoLeft = -o_OrthographicSize * o_AspectRatio * 0.5f;
			float orthoRight = o_OrthographicSize * o_AspectRatio * 0.5f;
			float orthoBottom = -o_OrthographicSize * 0.5f;
			float orthoTop = o_OrthographicSize * 0.5f;

			o_Projection = glm::ortho(orthoLeft, orthoRight, orthoBottom, orthoTop,
				o_OrthographicNear, o_OrthographicFar);
			break;
		}
		}
	}

}
