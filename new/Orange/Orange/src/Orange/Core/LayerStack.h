#pragma once

#include "Orange/Core/Base.h"
#include "Orange/Core/Layer.h"

#include <vector>

namespace Orange {

	class LayerStack
	{
	public:
		LayerStack() = default;
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return o_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return o_Layers.end(); }
		std::vector<Layer*>::reverse_iterator rbegin() { return o_Layers.rbegin(); }
		std::vector<Layer*>::reverse_iterator rend() { return o_Layers.rend(); }

		std::vector<Layer*>::const_iterator begin() const { return o_Layers.begin(); }
		std::vector<Layer*>::const_iterator end() const { return o_Layers.end(); }
		std::vector<Layer*>::const_reverse_iterator rbegin() const { return o_Layers.rbegin(); }
		std::vector<Layer*>::const_reverse_iterator rend() const { return o_Layers.rend(); }
	private:
		std::vector<Layer*> o_Layers;
		unsigned int o_LayerInsertIndex = 0;
	};

}