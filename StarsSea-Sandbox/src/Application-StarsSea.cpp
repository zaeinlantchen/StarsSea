#include <StarsSea.h>

#include "StarsSea/StarsSea-EntryPoint.h"

class ExampleLayer : public StarsSea::Layer
{
public:
	ExampleLayer() 
		: StarsSea::Layer("Example Layer") {

	}
	
	void OnUpdate() override {
		STARSEAINFO("ExampleLayer::OnUpdate");
	}

	void OnEvent(StarsSea::Event& event) override {
		STARSEATRACE("ExampleLayer::OnEvent {0}", event.ToString());
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