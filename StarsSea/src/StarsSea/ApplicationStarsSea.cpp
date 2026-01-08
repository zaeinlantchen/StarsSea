#include "../StarsSea-pch.h"

#include "ApplicationStarsSea.h"

#include "../StarsSeaEvents/ApplicationEvent.h"
#include "Log.h"

#include <GLFW/glfw3.h>

namespace StarsSea{
	ApplicationStarsSea::ApplicationStarsSea()
	{
		starsseaWindow = std::unique_ptr<Window>(Window::Create());
	}
	ApplicationStarsSea::~ApplicationStarsSea()
	{
	}

	void ApplicationStarsSea::Run()
	{
		while (starsseaRunning) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			starsseaWindow->OnUpdate();
		};
	}
}

