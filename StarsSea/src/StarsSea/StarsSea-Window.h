#pragma once

#include "StarSea-Core.h"
#include "../StarsSeaEvents/StarsSea-Event.h"

namespace StarsSea{
	struct WindowPrps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowPrps(const std::string& title = "星海核心",
			unsigned int width = 1280,
			unsigned int height = 720)
			: Title(title), Width(width), Height(height)
		{
		}
	};

	class STARSSEAAPI Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowPrps& props = WindowPrps());
	};
}