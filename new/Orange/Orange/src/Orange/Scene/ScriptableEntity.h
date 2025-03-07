#pragma once

#include "Entity.h"

namespace Orange
{

	class ScriptableEntity
	{
	public:
		virtual ~ScriptableEntity() {}

		template <typename T>
		T& GetComponent()
		{
			return o_Entity.GetComponent<T>();
		}

	protected:
		virtual void OnCreate() {}
		virtual void OnDestroy() {}
		virtual void OnUpdate(Timestep timestep) {}

	private:
		Entity o_Entity;
		friend class Scene;
	};

}
