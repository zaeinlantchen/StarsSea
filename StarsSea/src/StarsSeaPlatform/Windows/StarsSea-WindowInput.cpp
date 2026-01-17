#include "../../StarsSea-pch.h"
#include "StarsSea-WindowInput.h"
#include "../../StarsSea/ApplicationStarsSea.h"

#include <GLFW/glfw3.h>

namespace StarsSea {

	StarsSeaInput* StarsSeaInput::staseaInstance = new StarsSeaWindowsInput();

	bool StarsSea::StarsSeaWindowsInput::IsKeyPressedImpl(int keycode)
	{
		auto starseawindow =static_cast<GLFWwindow*>(ApplicationStarsSea::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(starseawindow, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool StarsSeaWindowsInput::IsMouseButtonPressedImpl(int button)
	{
		auto starseawindow = static_cast<GLFWwindow*>(ApplicationStarsSea::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(starseawindow, button);
		return state == GLFW_PRESS;
	}

	std::pair<float, float> StarsSeaWindowsInput::GetMousePositionImpl()
	{
		auto starseawindow = static_cast<GLFWwindow*>(ApplicationStarsSea::Get().GetWindow().GetNativeWindow());
		double xpos, ypos;
		glfwGetCursorPos(starseawindow, &xpos, &ypos);

		return { (float)xpos, (float)ypos};
	}

	float StarsSeaWindowsInput::GetMouseXImpl()
	{
		auto [x, y] = GetMousePositionImpl();
		return x;
	}

	float StarsSeaWindowsInput::GetMouseYImpl()
	{
		auto [x, y] = GetMousePositionImpl();
		return y;
	}

}