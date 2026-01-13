#pragma once

#include "../StarsSea-pch.h"

#include "StarSea-Core.h"
#include "../StarsSeaEvents/StarsSea-Event.h"
#include "../StarsSeaEvents/ApplicationEvent.h"
#include "StarsSea-Window.h"

namespace StarsSea{

	class STARSSEAAPI ApplicationStarsSea
	{
		public:
			ApplicationStarsSea();
			virtual ~ApplicationStarsSea();

			void Run();

			void OnEvent(Event& e);
		private:
			bool OnWindowClose(WindowCloseEvent& e);
			std::unique_ptr<class Window> starsseaWindow;
			bool starsseaRunning = true;
	};
	ApplicationStarsSea* CreateApplication();

}


