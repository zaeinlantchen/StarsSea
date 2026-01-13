#include "ApplicationStarsSea.h"

#include "../StarsSeaEvents/ApplicationEvent.h"
#include "../StarsSeaEvents/StarsSea-Event.h"
#include "Log.h"

#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include "../StarsSea-pch.h"

namespace StarsSea{

#define BINDEVENTFN(x) std::bind(&ApplicationStarsSea::x, this, std::placeholders::_1)

	ApplicationStarsSea::ApplicationStarsSea()
	{
		starsseaWindow = std::unique_ptr<Window>(Window::Create());
		starsseaWindow->SetEventCallback(BINDEVENTFN(OnEvent));
	}
	ApplicationStarsSea::~ApplicationStarsSea()
	{
	}

	void ApplicationStarsSea::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BINDEVENTFN(OnWindowClose));
		STARSEACOREINFO("{0}", e.ToString());
	}


	void ApplicationStarsSea::Run()
	{
		while (starsseaRunning) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			starsseaWindow->OnUpdate();
		};
	}

	bool ApplicationStarsSea::OnWindowClose(WindowCloseEvent& e)
	{
		starsseaRunning = false;
		return true;
	}
}

