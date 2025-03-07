#include "ogpch.h"
#include "Orange/Renderer/OrthographicCamera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace Orange
{
	OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top)
		:o_ProjMatrix(glm::ortho(left, right, bottom, top, -1.0f, 1.0f)), o_ViewMatrix(1.0f)
	{
		HZ_PROFILE_FUNCTION();

		o_ViewProjMatrix = o_ProjMatrix * o_ViewMatrix;
	}

	void OrthographicCamera::SetProjection(float left, float right, float bottom, float top)
	{
		HZ_PROFILE_FUNCTION();

		o_ProjMatrix = glm::ortho(left, right, bottom, top, -1.0f, 1.0f);
		o_ViewProjMatrix = o_ProjMatrix * o_ViewMatrix;
	}

	void OrthographicCamera::RecalculateViewMatrix()
	{
		HZ_PROFILE_FUNCTION();

		glm::mat4 transform = glm::translate(glm::mat4(1.0f), o_Position) *
			glm::rotate(glm::mat4(1.0f), glm::radians(o_Rotation), glm::vec3(0, 0, 1));

		o_ViewMatrix = glm::inverse(transform);

		o_ViewProjMatrix = o_ProjMatrix * o_ViewMatrix;
	}

}