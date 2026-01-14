#include "../StarsSea-pch.h"
#include "StarsSea-LayerStack.h"

namespace StarsSea {
	LayerStack::LayerStack()
	{
		starseaLayerInsert = starseaLayers.begin();
	}
	LayerStack::~LayerStack()
	{
		for (Layer* layer : starseaLayers)
			delete layer;
	}
	void LayerStack::PushLayer(Layer* layer)
	{
		starseaLayerInsert = starseaLayers.emplace(starseaLayerInsert, layer);
	}
	void LayerStack::PushOverlay(Layer* overlay)
	{
		starseaLayers.emplace_back(overlay);
	}
	void LayerStack::PopLayer(Layer* layer)
	{
		auto it = std::find(starseaLayers.begin(), starseaLayers.end(), layer);
		if (it != starseaLayers.end()) {
			starseaLayers.erase(it);
			starseaLayerInsert--;
		}
			
	}
	void LayerStack::PopOverlay(Layer* overlay)
	{
		auto it = std::find(starseaLayers.begin(), starseaLayers.end(), overlay);
		if (it != starseaLayers.end())
			starseaLayers.erase(it);
	}
} // namespace StarsSea