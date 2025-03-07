#pragma once

#include <filesystem>

#include "Orange/Core/Base.h"
#include "Orange/Renderer/Texture.h"

namespace Orange {

	struct MSDFData;

	class Font
	{
	public:
		Font(const std::filesystem::path& font);
		~Font();

		const MSDFData* GetMSDFData() const { return o_Data; }
		Ref<Texture2D> GetAtlasTexture() const { return o_AtlasTexture; }

		static Ref<Font> GetDefault();
	private:
		MSDFData* o_Data;
		Ref<Texture2D> o_AtlasTexture;

	};

}
