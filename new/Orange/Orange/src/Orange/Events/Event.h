#pragma once

#include "Orange/Debug/Instrumentor.h"
#include "Orange/Core/Base.h"

#include <functional>

namespace Orange
{
	// Orange 中的事件当前处于阻塞状态，这意味着当事件发生时，它会立即被调度，必须立即处理。
	// 对于将来，更好的策略可能是在事件中缓冲事件总线，并在更新阶段的 “event” 部分处理它们。

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication            = BIT(0),
		EventCategoryInput                  = BIT(1),
		EventCategoryKeyboard               = BIT(2),
		EventCategoryMouse                  = BIT(3),
		EventCategoryMouseButton            = BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }
#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class Event
	{
		friend class EventDispatcher;
	public:
		bool Handled = false;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	};

	class EventDispatcher
	{
	public:
		EventDispatcher(Event& event)
			:o_Event(event)
		{
		}

		template<typename T, typename F>
		bool Dispatch(const F& func)
		{
			if (o_Event.GetEventType() == T::GetStaticType())
			{
				o_Event.Handled |= func(static_cast<T&>(o_Event));
				return true;
			}

			return false;
		}

	private:
		Event& o_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}

}
