#pragma once

#include "Orange/Events/Event.h"
#include "Orange/Core/MouseCodes.h"

namespace Orange
{
	class  MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(const float x, const float y)
		:o_MouseVecX(x), o_MouseVecY(y) {}

		float GetVecX() const { return o_MouseVecX; }
		float GetVecY() const { return o_MouseVecY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "鼠标移动事件: X = " << o_MouseVecX << ", Y = " << o_MouseVecY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float o_MouseVecX, o_MouseVecY;
	};

	class MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(const float offsetX, const float offsetY)
			:o_OffsetX(offsetX), o_OffsetY(offsetY) {}

		float GetOffsetX() const { return o_OffsetX; }
		float GetOffsetY() const { return o_OffsetY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "鼠标滚动事件: OffsetX = " << o_OffsetX << ", OffsetY = " << o_OffsetY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float o_OffsetX, o_OffsetY;
	};

	class MouseButtonEvent : public Event
	{
	public:
		MouseCode GetMouseButton() const { return o_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput | EventCategoryMouseButton)

	protected:
		MouseButtonEvent(const MouseCode button)
			:o_Button(button) {}

		MouseCode o_Button;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(const MouseCode button)
			:MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "鼠标按下事件: 已按下 " << o_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(MouseCode button)
			:MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "鼠标释放事件: 释放 " << o_Button;
			return ss.str();
		}
		
		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}
