#pragma once

#include "glm/glm.hpp"

namespace Orange
{
		
	class OrthographicCamera
	{
	public:
		OrthographicCamera(float left, float right, float bottom, float top);

		void SetProjection(float left, float right, float bottom, float top);

		const glm::vec3& GetPosition() const { return o_Position; }
		void SetPosition(const glm::vec3& position) { o_Position = position; RecalculateViewMatrix(); }

		float GetRotation() const { return o_Rotation; }
		void SetRotation(float rotation) { o_Rotation = rotation; RecalculateViewMatrix(); }

		const glm::mat4& GetProjMatrix() const { return o_ProjMatrix; }
		const glm::mat4& GetViewMatrix() const { return o_ViewMatrix; }
		const glm::mat4& GetViewProjMatrix() const { return o_ViewProjMatrix; }

	private:
		void RecalculateViewMatrix();

	private:
		glm::mat4 o_ProjMatrix;
		glm::mat4 o_ViewMatrix;
		glm::mat4 o_ViewProjMatrix;

		glm::vec3 o_Position = { 0.0f, 0.0f, 0.0f };
		float o_Rotation = 0.0f;
	};

}
