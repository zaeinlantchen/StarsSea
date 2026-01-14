#pragma once

#include "../StarsSea/StarSea-Core.h"
#include "StarsSea-Layer.h"
#include <vector>

namespace StarsSea {
	class STARSSEAAPI LayerStack {
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return starseaLayers.begin(); }
		std::vector<Layer*>::iterator end() { return starseaLayers.end(); }
	private:
		std::vector<Layer*> starseaLayers;
		std::vector<Layer*>::iterator starseaLayerInsert;
	};
} // namespace StarsSea