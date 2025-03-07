#pragma once

#include <string>
#include <filesystem>

#include "Orange/Core/Base.h"

namespace Orange {

	struct ProjectConfig
	{
		std::string Name = "Untitled";
		std::filesystem::path StartScene;
		std::filesystem::path AssetDirectory;
		std::filesystem::path ScriptModulePath;
	};

	class Project
	{
	public:
		static const std::filesystem::path& GetProjectDirectory()
		{
			OG_CORE_ASSERT(o_ActiveProject);
			return o_ActiveProject->o_ProjectDirectory;
		}

		static std::filesystem::path GetAssetDirectory()
		{
			OG_CORE_ASSERT(o_ActiveProject);
			return GetProjectDirectory() / o_ActiveProject->o_Config.AssetDirectory;
		}

		// TODO(Yan): move to asset manager when we have one
		static std::filesystem::path GetAssetFileSystemPath(const std::filesystem::path& path)
		{
			OG_CORE_ASSERT(o_ActiveProject);
			return GetAssetDirectory() / path;
		}

		ProjectConfig& GetConfig() { return o_Config; }

		static Ref<Project> GetActive() { return o_ActiveProject; }
		static Ref<Project> New();
		static Ref<Project> Load(const std::filesystem::path& path);
		static bool SaveActive(const std::filesystem::path& path);

	private:
		ProjectConfig o_Config;
		std::filesystem::path o_ProjectDirectory;
		inline static Ref<Project> o_ActiveProject;
	};
}
