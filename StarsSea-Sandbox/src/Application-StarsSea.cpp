#include <StarsSea.h>

#include "../ImGui/imgui.h"

class ExampleLayer : public StarsSea::Layer
{
public:
	ExampleLayer() 
		: StarsSea::Layer("示例") {
	}
	
	void OnUpdate() override {
		if (StarsSea::StarsSeaInput::IsKeyPressed(STARSSEAKEYTAB))
			STARSEATRACE("Tab被按下！");
	}

	void OnImGuiRender() override {

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
	}
	~StarsSeaSandbox() {

	}

private:

};

StarsSea::ApplicationStarsSea* StarsSea::CreateApplication()
{
	return new StarsSeaSandbox();
}