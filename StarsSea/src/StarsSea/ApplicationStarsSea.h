#pragma once

#include "../StarsSea-pch.h"

#include "StarSea-Core.h"

#include "StarsSea-Window.h"
#include "../StarsSeaLayers/StarsSea-LayerStack.h"
#include "../StarsSeaEvents/StarsSea-Event.h"
#include "../StarsSeaEvents/ApplicationEvent.h"


namespace StarsSea{

	class STARSSEAAPI ApplicationStarsSea
	{
		public:
			ApplicationStarsSea();
			virtual ~ApplicationStarsSea();

			void Run();

			void OnEvent(Event& e);

			void PushLayer(Layer* layer);
			void PushOverlay(Layer* overlay);

			inline static ApplicationStarsSea& Get() { return *starseaInstance; }

			inline Window& GetWindow() { return *starsseaWindow; }
		private:
			bool OnWindowClose(WindowCloseEvent& e);
			std::unique_ptr<class Window> starsseaWindow;
			bool starsseaRunning = true;
			LayerStack starseaLayerStack;
		private:
			static ApplicationStarsSea* starseaInstance;
	};
	ApplicationStarsSea* CreateApplication();

}


