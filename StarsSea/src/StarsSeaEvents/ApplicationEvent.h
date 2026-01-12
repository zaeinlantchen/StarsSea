#pragma once

#include "../StarsSea-pch.h"

#include "StarsSea-Event.h"

namespace StarsSea {
	class STARSSEAAPI WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: starseaWidth(width), starseaHeight(height) {
		}

		inline unsigned int GetWidth() const { return starseaWidth; }
		inline unsigned int GetHeight() const { return starseaHeight; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "WindowResizeEvent: " << starseaWidth << ", " << starseaHeight;
			return ss.str();
		}

		EVENTCLASSTYPE(WindowResize)
		EVENTCLASSCATEGORY(EventCategoryApplication)
	private:
		unsigned int starseaWidth, starseaHeight;
	};

	class STARSSEAAPI WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		EVENTCLASSTYPE(WindowClose)
		EVENTCLASSCATEGORY(EventCategoryApplication)
	};

	class STARSSEAAPI AppTickEvent : public Event
	{
		public:
		AppTickEvent() {}

		EVENTCLASSTYPE(AppTick)
		EVENTCLASSCATEGORY(EventCategoryApplication)
	};

	class STARSSEAAPI AppUpdateEvent : public Event
	{
		public:
		AppUpdateEvent() {}

		EVENTCLASSTYPE(AppUpdate)
		EVENTCLASSCATEGORY(EventCategoryApplication)
	};

	class STARSSEAAPI AppRenderEvent : public Event
	{
		public:
		AppRenderEvent() {}

		EVENTCLASSTYPE(AppRender)
		EVENTCLASSCATEGORY(EventCategoryApplication)
	};
}