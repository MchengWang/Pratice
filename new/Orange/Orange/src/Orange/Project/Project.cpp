#include "ogpch.h"

#include "Project.h"
#include "ProjectSerializer.h"

namespace Orange {

	Ref<Project> Project::New()
	{
		o_ActiveProject = CreateRef<Project>();
		return o_ActiveProject;
	}

	Ref<Project> Project::Load(const std::filesystem::path& path)
	{
		Ref<Project> project = CreateRef<Project>();
		ProjectSerializer serializer(project);
		if (serializer.Deserialize(path))
		{
			project->o_ProjectDirectory = path.parent_path();
			o_ActiveProject = project;
			return o_ActiveProject;
		}
		return nullptr;
	}

	bool Project::SaveActive(const std::filesystem::path& path)
	{
		ProjectSerializer serializer(o_ActiveProject);
		if (serializer.Serialize(path))
		{
			o_ActiveProject->o_ProjectDirectory = path.parent_path();
			return true;
		}
		return false;
	}
}
