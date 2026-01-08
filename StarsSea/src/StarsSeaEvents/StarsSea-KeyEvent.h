#pragma once

#include "../StarsSea-pch.h"
#include "StarsSea-Event.h"


namespace StarsSea {
	class STARSSEAAPI KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return starseaKeyCode; }

		EVENTCLASSCATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int keycode)
			: starseaKeyCode(keycode) {}

		int starseaKeyCode;
	};

	class STARSSEAAPI KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount)
			: KeyEvent(keycode), starseaRepeatCount(repeatCount) {
		}

		inline int GetRepeatCount() const { return starseaRepeatCount; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << starseaKeyCode << " (" << starseaRepeatCount << " repeats)";
			return ss.str();
		}
		EVENTCLASSTYPE(KeyPressed)
	private:
		int starseaRepeatCount;
	};

	class STARSSEAAPI KeyReleasedEvent : public KeyEvent
	{
		public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) {
		}
		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << starseaKeyCode;
			return ss.str();
		}
		EVENTCLASSTYPE(KeyReleased)
	};
}