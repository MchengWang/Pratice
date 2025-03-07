#pragma once

#include "Orange/Core/Base.h"
#include "Orange/Scene/Scene.h"
#include "Orange/Scene/Entity.h"

namespace Orange
{

	class SceneHierarchyPanel
	{
	public:
		SceneHierarchyPanel() = default;
		SceneHierarchyPanel(const Ref<Scene>& scene);

		void SetContext(const Ref<Scene>& scene);

		void OnImGuiRender();

		Entity GetSelectedEntity() const { return o_SelectionContext; }
		void SetSelectedEntity(Entity entity);

	private:
		template <typename T>
		void DisplayAddComponentEntry(const std::string& entryName);

		void DrawEntityNode(Entity entity);
		void DrawComponents(Entity entity);

	private:
		Ref<Scene> o_Context;
		Entity o_SelectionContext;
	};

}
