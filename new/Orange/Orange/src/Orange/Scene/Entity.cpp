#include "ogpch.h"
#include "Entity.h"
namespace Orange
{
	Entity::Entity(entt::entity handle, Scene* scene)
		:o_EntityHandle(handle), o_Scene(scene)
	{
	}
}