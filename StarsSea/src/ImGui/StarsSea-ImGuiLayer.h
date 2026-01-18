#pragma once

#include "../StarsSeaLayers/StarsSea-Layer.h"
#include "../StarsSeaEvents/ApplicationEvent.h"
#include "../StarsSeaEvents/StarsSea-KeyEvent.h"
#include "../StarsSeaEvents/StarsSea-MouseEvent.h"

namespace StarsSea
{
	class STARSSEAAPI StarsSeaImGuiLayer : public Layer
	{
		public:
			StarsSeaImGuiLayer();
			~StarsSeaImGuiLayer();

			virtual void OnAttach() override;
			virtual void OnDetach()override;
			virtual void OnImGuiRender() override;
			void Begin();
			void End();
;			
		private:
			float starsseaTime = 0.0f;
	};
}