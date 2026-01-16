#pragma once

#include "../StarsSeaLayers/StarsSea-Layer.h"
#include "../StarsSeaEvents/ApplicationEvent.h"
#include "../StarsSeaEvents/StarsSea-KeyEvent.h"
#include "../StarsSeaEvents/StarsSea-MouseEvent.h"

namespace StarsSea
{
	class STARSSEAAPI StarsSeaImGuiLayer : public Layer
	{
		public:
			StarsSeaImGuiLayer();
			~StarsSeaImGuiLayer();
			void OnAttach();
			void OnDetach();
			void OnUpdate();
			void OnEvent(Event& event);
			void OnImGuiRender();
		private:
			bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& event);
			bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& event);
			bool OnMouseMovedEvent(MouseMovedEvent& event);
			bool OnMouseScrolledEvent(MouseScrolledEvent& event);
			bool OnKeyPressedEvent(KeyPressedEvent& event);
			bool OnKeyReleasedEvent(KeyReleasedEvent& event);
			bool OnKeyTypedEvent(KeyTypedEvent& event);
			bool OnWindowResizeEvent(WindowResizeEvent& event);
		private:
			float starsseaTime = 0.0f;
	};
}