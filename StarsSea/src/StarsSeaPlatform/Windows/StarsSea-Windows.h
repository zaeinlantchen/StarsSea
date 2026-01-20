#pragma once

#include "../../StarsSea-pch.h"

#include "../../StarsSea/StarsSea-Window.h"

#include "../../StarsSea-Renderer/StarsSeaGraphicsContext.h"

#include <GLFW/glfw3.h>

namespace StarsSea{

	class StarsSeaWindows : public Window
	{
		public:
			StarsSeaWindows(const WindowPrps& props);
			virtual ~StarsSeaWindows();

			void OnUpdate() override;

			inline unsigned int GetWidth() const override { return starsseaData.Width; }
			inline unsigned int GetHeight() const override { return starsseaData.Height; }

			// Window attributes
			inline void SetEventCallback(const EventCallbackFn& callback) override { starsseaData.EventCallback = callback; };
			void SetVSync(bool enabled) override;
			bool IsVSync() const override;

			inline virtual void* GetNativeWindow() const override { return StarsSeaWindow; }

		private:
			virtual void Init(const WindowPrps& props);
			virtual void Shutdown();
		private:
			GLFWwindow* StarsSeaWindow;

			GraphicsContext* starsseaContext;

			struct StarsSeaWindowData
			{
				std::string Title;
				unsigned int Width, Height;
				bool VSync;

				EventCallbackFn EventCallback;
			};
			StarsSeaWindowData starsseaData;
	};
}