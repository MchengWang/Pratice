#pragma once

#include "Orange/Core/Timestep.h"
#include "Orange/Core/UUID.h"
#include "Orange/Renderer/EditorCamera.h"

#include "entt.hpp"

class b2World;

namespace Orange
{

	class Entity;

	class Scene
	{
	public:
		Scene();
		~Scene();

		static Ref<Scene> Copy(Ref<Scene> other);

		Entity CreateEntity(const std::string& name = std::string());
		Entity CreateEntityWithUUID(UUID uuid, const std::string& name = std::string());
		void DestroyEntity(Entity entity);

		void OnRuntimeStart();
		void OnRuntimeStop();

		void OnSimulationStart();
		void OnSimulationStop();

		void OnUpdateRuntime(Timestep timestep);
		void OnUpdateSimulation(Timestep timestep, EditorCamera& camera);
		void OnUpdateEditor(Timestep timestep, EditorCamera& camera);
		void OnViewportResize(uint32_t width, uint32_t height);

		Entity DuplicateEntity(Entity entity);

		Entity FindEntityByName(std::string_view name);
		Entity GetEntityByUUID(UUID uuid);

		Entity GetPrimaryCameraEntity();

		bool IsRunning() const { return o_IsRunning; }

		bool IsPaused() const { return o_IsPaused; }

		void SetPaused(bool paused) { o_IsPaused = paused; }
		
		void Step(int frames = 1);

		template <typename... Components>
		auto GetAllEntitiesWith()
		{
			return o_Registry.view<Components...>();
		}

	private:
		template <typename T>
		void OnComponentAdded(Entity entity, T& component);

		void OnPhysics2DStart();
		void OnPhysics2DStop();

		void RenderScene(EditorCamera& camera);

	private:
		entt::registry o_Registry;
		uint32_t o_ViewportWidth = 0, o_ViewportHeight = 0;
		bool o_IsRunning = false;
		bool o_IsPaused = false;
		int o_StepFrames = 0;


		b2World* o_PhysicsWorld = nullptr;

		std::unordered_map<UUID, entt::entity> o_EntityMap;

		friend class Entity;
		friend class SceneHierarchyPanel;
		friend class SceneSerializer;
	};

}
