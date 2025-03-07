#pragma once

#include "Orange/Core/UUID.h"
#include "Scene.h"
#include "Components.h"

#include "entt.hpp"

namespace Orange
{
	class Entity
	{
	public:
		Entity() = default;
		Entity(entt::entity handle, Scene* scene);
		Entity(const Entity& other) = default;

		template<typename T, typename... Args>
		T& AddComponent(Args&&... args)
		{
			OG_CORE_ASSERT(!HasComponent<T>(), "Entity already has component!");
			T& component = o_Scene->o_Registry.emplace<T>(o_EntityHandle, std::forward<Args>(args)...);
			o_Scene->OnComponentAdded<T>(*this, component);
			return component;
		}

		template <typename T, typename... Args>
		T& AddOrReplaceComponent(Args&&... args)
		{
			T& component = o_Scene->o_Registry.emplace_or_replace<T>(o_EntityHandle, std::forward<Args>(args)...);
			o_Scene->OnComponentAdded<T>(*this, component);
			return component;
		}

		template<typename T>
		T& GetComponent()
		{
			OG_CORE_ASSERT(HasComponent<T>(), "Entity does not have component!");
			return o_Scene->o_Registry.get<T>(o_EntityHandle);
		}

		template <typename T>
		bool HasComponent()
		{
			// 最新中 entt 没有 has 方法
			// 替代方法 all_of (检查实体是否是所有给定存储的一部分。) entt.hpp 中标注
			return o_Scene->o_Registry.all_of<T>(o_EntityHandle);
		}

		template<typename T>
		void RemoveComponent()
		{
			OG_CORE_ASSERT(HasComponent<T>(), "Entity does not have component!");
			o_Scene->o_Registry.remove<T>(o_EntityHandle);
		}

		operator bool() const { return o_EntityHandle != entt::null; }
		operator entt::entity() const { return o_EntityHandle; }
		operator uint32_t() const { return (uint32_t)o_EntityHandle; }

		UUID GetUUID() { return GetComponent<IDComponent>().ID; }
		const std::string& GetName() { return GetComponent<TagComponent>().Tag; }

		bool operator==(const Entity& other) const
		{
			return o_EntityHandle == other.o_EntityHandle && o_Scene == other.o_Scene;
		}

		bool operator!=(const Entity& other) const
		{
			return !(*this == other);
		}
	private:
		entt::entity o_EntityHandle{ entt::null };
		Scene* o_Scene = nullptr;
	};
}
