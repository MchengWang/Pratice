#include "ogpch.h"

#include "ContentBrowserPanel.h"

#include "Orange/Project/Project.h"

#include <imgui/imgui.h>

namespace Orange
{

	ContentBrowerPanel::ContentBrowerPanel()
		: o_BaseDirectory(Project::GetAssetDirectory()), o_CurrentDirectory(o_BaseDirectory)
	{
		o_DirectoryIcon = Texture2D::Create("Resources/Icons/ContentBrowser/DirectoryIcon.png");
		o_FileIcon = Texture2D::Create("Resources/Icons/ContentBrowser/FileIcon.png");
	}

	void ContentBrowerPanel::OnImGuiRender()
	{
		ImGui::Begin("Content Browser");

		if (o_CurrentDirectory != std::filesystem::path(o_BaseDirectory))
		{
			if (ImGui::Button("<-"))
			{
				o_CurrentDirectory = o_CurrentDirectory.parent_path();
			}
		}

		static float padding = 16.0f;
		static float thumbnailSize = 128.0f;
		float cellSize = thumbnailSize + padding;

		float panelWidth = ImGui::GetContentRegionAvail().x;
		int columnCount = (int)(panelWidth / cellSize);
		if (columnCount < 1)
			columnCount = 1;

		ImGui::Columns(columnCount, 0, false);

		for (auto& directoryEntity : std::filesystem::directory_iterator(o_CurrentDirectory))
		{
			const auto& path = directoryEntity.path();
			std::string filenameString = path.filename().string();
			
			ImGui::PushID(filenameString.c_str());
			Ref<Texture2D> icon = directoryEntity.is_directory() ? o_DirectoryIcon : o_FileIcon;
			ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0, 0, 0, 0));
			ImGui::ImageButton((ImTextureID)icon->GetRendererID(), { thumbnailSize, thumbnailSize }, { 0, 1 }, { 1, 0 });

			if (ImGui::BeginDragDropSource())
			{ 
				std::filesystem::path relativePath(path);
				const wchar_t* itemPath = relativePath.c_str();
				ImGui::SetDragDropPayload("CONTENT_BROWSER_ITEM", itemPath, (wcslen(itemPath) + 1) * sizeof(wchar_t));
				ImGui::EndDragDropSource();
			}

			ImGui::PopStyleColor();
			 
			if (ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
			{
				if (directoryEntity.is_directory())
					o_CurrentDirectory /= path.filename();
			}

			ImGui::TextWrapped(filenameString.c_str());

			ImGui::NextColumn();

			ImGui::PopID();
		}

		ImGui::Columns(1);
		ImGui::SliderFloat("Thumbnail Size", &thumbnailSize, 16, 512);
		ImGui::SliderFloat("Padding Size", &padding, 0, 32);

		// TODO status bar
		ImGui::End();
	}

}
