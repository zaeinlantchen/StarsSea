#pragma once

#include "../StarsSea/StarSea-Core.h"
#include "../StarsSeaEvents/StarsSea-Event.h"

namespace StarsSea{
	class STARSSEAAPI Layer {
		public:
			Layer(const std::string& name = "Layer");
			virtual ~Layer();

			virtual void OnAttach() {}
			virtual void OnDetach() {}
			virtual void OnUpdate() {}
			virtual void OnImGuiRender() {}
			virtual void OnEvent(Event& event) {}

			inline const std::string& GetName() const { return starseaDebugName; }
		protected:
			std::string starseaDebugName;
	};
}