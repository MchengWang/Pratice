#pragma once

#include "Orange/Renderer/Texture.h"

#include <filesystem>

namespace Orange
{

	class ContentBrowerPanel
	{
	public:
		ContentBrowerPanel();

		void OnImGuiRender();

	private:
		std::filesystem::path o_BaseDirectory;
		std::filesystem::path o_CurrentDirectory;

		Ref<Texture2D> o_DirectoryIcon;
		Ref<Texture2D> o_FileIcon;
	};

}
