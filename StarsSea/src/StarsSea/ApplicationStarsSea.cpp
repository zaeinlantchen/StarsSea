#include "ApplicationStarsSea.h"

#include "../StarsSeaEvents/ApplicationEvent.h"
#include "../StarsSeaEvents/StarsSea-Event.h"
#include "Log.h"

#include <glad/glad.h>
#include "../StarsSea-pch.h"
#include "../StarsSea-Input/StarsSea-Input.h"

namespace StarsSea{

#define BINDEVENTFN(x) std::bind(&ApplicationStarsSea::x, this, std::placeholders::_1)

	ApplicationStarsSea* ApplicationStarsSea::starseaInstance = nullptr;

	ApplicationStarsSea::ApplicationStarsSea()
	{
		STARSEACOREASSERT(!starsseaInstance, "已退出星海核心！");
		starseaInstance = this;
		starsseaWindow = std::unique_ptr<Window>(Window::Create());
		starsseaWindow->SetEventCallback(BINDEVENTFN(OnEvent));
	}
	ApplicationStarsSea::~ApplicationStarsSea()
	{
	}

	void ApplicationStarsSea::PushLayer(Layer* layer)
	{
		starseaLayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void ApplicationStarsSea::PushOverlay(Layer* overlay)
	{
		starseaLayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	void ApplicationStarsSea::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BINDEVENTFN(OnWindowClose));
		/*STARSEACOREINFO("{0}", e.ToString());*/

		for (auto it = starseaLayerStack.end(); it != starseaLayerStack.begin();) {
			(*--it)->OnEvent(e);
			if (e.starseaHandled)
				break;
		}

	}


	void ApplicationStarsSea::Run()
	{
		while (starsseaRunning) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : starseaLayerStack) {
				layer->OnUpdate();
			}
			//auto [x, y] = StarsSeaInput::GetMousePosition();
			//STARSEACORETRACE("{0}, {1}", x, y);

			starsseaWindow->OnUpdate();
		};
	}

	bool ApplicationStarsSea::OnWindowClose(WindowCloseEvent& e)
	{
		starsseaRunning = false;
		return true;
	}
}

