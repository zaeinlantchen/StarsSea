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

		/*starsSeaImGuiLayer = std::make_unique<StarsSeaImGuiLayer>();*/
		starsSeaImGuiLayer = new StarsSeaImGuiLayer();
		PushOverlay(starsSeaImGuiLayer);

		glGenVertexArrays(1, &starsseaVertexArray);
		glBindVertexArray(starsseaVertexArray);

		glGenBuffers(1, &starsseaVertexBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, starsseaVertexBuffer);

		float vertices[] = {
			-0.5f, -0.5f, 0.0f, // 0
			 0.5f, -0.5f, 0.0f, // 1
			 0.0f,  0.5f, 0.0f, // 2
		};

		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

		glGenBuffers(1, &starsseaIndexBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, starsseaIndexBuffer);

		unsigned int indices[] = {
			0, 1, 2
		};

		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		std::string vertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 starseaPosition;
			out vec3 vstarseaPosition; 
			void main()
			{
				vstarseaPosition = starseaPosition;
				gl_Position = vec4(starseaPosition, 1.0);
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;
			in vec3 vstarseaPosition;
			void main()
			{
				color = vec4(vstarseaPosition * 0.5 + 0.5, 0.5);
			}
		)";

		starseaShader.reset(new StarsSeaShader(vertexSrc, fragmentSrc));

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
			glClearColor(0.1f, 0.1f, 0.1f, 0.1f);
			glClear(GL_COLOR_BUFFER_BIT);

			starseaShader->Bind();

			glBindVertexArray(starsseaVertexArray);
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

			for (Layer* layer : starseaLayerStack) {
				layer->OnUpdate();
			}
			starsSeaImGuiLayer->Begin();
			for (Layer* layer : starseaLayerStack) {
				layer->OnImGuiRender();
			}
			starsSeaImGuiLayer->End();
			/*auto [x, y] = StarsSeaInput::GetMousePosition();
			STARSEACORETRACE("{0}, {1}", x, y);*/
			
			starsseaWindow->OnUpdate();
		};
	}

	bool ApplicationStarsSea::OnWindowClose(WindowCloseEvent& e)
	{
		starsseaRunning = false;
		return true;
	}
}

