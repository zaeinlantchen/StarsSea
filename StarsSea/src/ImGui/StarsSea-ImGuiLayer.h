#pragma once

#include "../StarsSeaLayers/StarsSea-Layer.h"

namespace StarsSea
{
	class STARSSEAAPI StarsSeaImGuiLayer : public Layer
	{
		public:
			StarsSeaImGuiLayer();
			~StarsSeaImGuiLayer();
			void OnAttach();
			void OnDetach();
			void OnUpdate();
			void OnEvent(Event& event);
			void OnImGuiRender();
		private:
			float starsseaTime = 0.0f;
	};
}