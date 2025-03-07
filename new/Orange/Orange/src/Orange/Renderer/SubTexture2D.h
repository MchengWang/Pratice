#pragma once

#include <glm/glm.hpp>

#include "Texture.h"

namespace Orange
{

	class SubTexture2D
	{
	public:
		SubTexture2D(const Ref<Texture2D>& texture, const glm::vec2& min, const glm::vec2& max);

		const Ref<Texture2D> GetTexture() const { return o_Texture; }
		const glm::vec2* GetTexCoords() const { return o_TexCoords; }

		static Ref<SubTexture2D> CreateFromCoords(const Ref<Texture2D>& texture, const glm::vec2& coords, const glm::vec2& cellSize, const glm::vec2& spriteSize = { 1, 1 });
	private:
		Ref<Texture2D> o_Texture;
		glm::vec2 o_TexCoords[4];
	};

}