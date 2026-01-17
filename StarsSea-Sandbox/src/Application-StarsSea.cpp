#include <StarsSea.h>

#include "StarsSea/StarsSea-EntryPoint.h"

class ExampleLayer : public StarsSea::Layer
{
public:
	ExampleLayer() 
		: StarsSea::Layer("示例层") {

	}
	
	void OnUpdate() override {
		if (StarsSea::StarsSeaInput::IsKeyPressed(STARSSEAKEYTAB))
			STARSEATRACE("Tab被按下！");
	}

	void OnEvent(StarsSea::Event& event) override {
		if (event.GetEventType() == StarsSea::EventType::KeyPressed) {
			StarsSea::KeyPressedEvent& e = (StarsSea::KeyPressedEvent&)event;
			STARSEATRACE("{0}", (char)e.GetKeyCode());
		}
	}

private:

};


class StarsSeaSandbox : public StarsSea::ApplicationStarsSea
{
public:
	StarsSeaSandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new StarsSea::StarsSeaImGuiLayer());
	}
	~StarsSeaSandbox() {

	}

private:

};

StarsSea::ApplicationStarsSea* StarsSea::CreateApplication()
{
	return new StarsSeaSandbox();
}