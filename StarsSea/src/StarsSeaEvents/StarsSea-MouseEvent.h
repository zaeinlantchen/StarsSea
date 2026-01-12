#pragma once

#include "../StarsSea-pch.h"

#include "StarsSea-Event.h"

namespace StarsSea {
	class STARSSEAAPI MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y)
			: starseaMouseX(x), starseaMouseY(y) {
		}

		inline float GetX() const { return starseaMouseX; }
		inline float GetY() const { return starseaMouseY; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << starseaMouseX << ", " << starseaMouseY;
			return ss.str();
		}

		EVENTCLASSTYPE(MouseMoved)
			EVENTCLASSCATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float starseaMouseX, starseaMouseY;
	};

	class STARSSEAAPI MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			: starseaXOffset(xOffset), starseaYOffset(yOffset) {
		}

		inline float GetXOffset() const { return starseaXOffset; }
		inline float GetYOffset() const { return starseaYOffset; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << starseaXOffset << ", " << starseaYOffset;
			return ss.str();
		}

		EVENTCLASSTYPE(MouseScrolled)
		EVENTCLASSCATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float starseaXOffset, starseaYOffset;
	};

	class STARSSEAAPI MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return starseaButton; }
		EVENTCLASSCATEGORY(EventCategoryMouse | EventCategoryInput | EventCategoryMouseButton)
	protected:
		MouseButtonEvent(int button)
			: starseaButton(button) {
		}
		int starseaButton;
	};
	class STARSSEAAPI MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button) {
		}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << starseaButton;
			return ss.str();
		}

		EVENTCLASSTYPE(MouseButtonPressed)
	};

	class STARSSEAAPI MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) {
		}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << starseaButton;
			return ss.str();
		}

		EVENTCLASSTYPE(MouseButtonReleased)
	};

}

