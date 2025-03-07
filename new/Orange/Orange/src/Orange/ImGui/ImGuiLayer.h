#pragma once

#include "Orange/Core/Layer.h"

#include "Orange/Events/ApplicationEvent.h"
#include "Orange/Events/KeyEvent.h"
#include "Orange/Events/MouseEvent.h"

namespace Orange {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& event) override;

		void Begin();
		void End();

		void BlockEvents(bool block) { o_BlockEvents = block; }

		void SetDarkThemeColors();

		uint32_t GetActiveWidgetID() const;
	private:
		bool o_BlockEvents = true;
		float m_Time = 0.0f;
	};

}
