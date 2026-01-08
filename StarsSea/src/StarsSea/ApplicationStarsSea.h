#pragma once

#include "StarSea-Core.h"
#include "../StarsSeaEvents/StarsSea-Event.h"
#include "StarsSea-Window.h"

namespace StarsSea{

	class STARSSEAAPI ApplicationStarsSea
	{
		public:
			ApplicationStarsSea();
			virtual ~ApplicationStarsSea();

			void Run();
		private:
			std::unique_ptr<class Window> starsseaWindow;
			bool starsseaRunning = true;
	};
	ApplicationStarsSea* CreateApplication();

}


