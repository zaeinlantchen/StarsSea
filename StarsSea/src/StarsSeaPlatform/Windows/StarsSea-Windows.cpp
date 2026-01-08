#include "../../StarsSea-pch.h"

#include "StarsSea-Windows.h"

namespace StarsSea{
	
	static bool starsseaGLFWInitialized = false;

	Window* Window::Create(const WindowPrps& props)
	{
		return new StarsSeaWindows(props);
	}

	StarsSeaWindows::StarsSeaWindows(const WindowPrps& props)
	{
		Init(props);
	}

	StarsSeaWindows::~StarsSeaWindows()
	{
		Shutdown();
	}

	void StarsSeaWindows::Init(const WindowPrps& props)
	{
		starsseaDate.Title = props.Title;
		starsseaDate.Width = props.Width;
		starsseaDate.Height = props.Height;

		STARSEAINFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!starsseaGLFWInitialized)
		{
			int success = glfwInit();
			STARSEACOREASSERT(success, "Could not initialize GLFW!");
			starsseaGLFWInitialized = true;
		}

		StarsSeaWindow = glfwCreateWindow((int)props.Width, (int)props.Height, starsseaDate.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(StarsSeaWindow);
		glfwSetWindowUserPointer(StarsSeaWindow, &starsseaDate);
		SetVSync(true);
	}

	void StarsSeaWindows::Shutdown()
	{
		glfwDestroyWindow(StarsSeaWindow);
	}

	void StarsSeaWindows::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(StarsSeaWindow);
	}

	void StarsSeaWindows::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);
		starsseaDate.VSync = enabled;
	}

	bool StarsSeaWindows::IsVSync() const
	{
		return starsseaDate.VSync;
	}
}