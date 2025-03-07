#pragma once

#include <glm/glm.hpp>

namespace Orange
{

	class Camera
	{
	public:
		Camera() = default;
		Camera(const glm::mat4& projection)
			:o_Projection(projection)
		{ }

		virtual ~Camera() = default;

		const glm::mat4& GetProjection() const { return o_Projection; }

	protected:
		glm::mat4 o_Projection = glm::mat4(1.0f);
	};

}