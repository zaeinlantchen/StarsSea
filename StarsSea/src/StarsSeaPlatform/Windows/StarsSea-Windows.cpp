#include "StarsSea-Windows.h"
#include "../../StarsSea/Log.h"

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
		starsseaData.Title = props.Title;
		starsseaData.Width = props.Width;
		starsseaData.Height = props.Height;

		STARSEACOREINFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!starsseaGLFWInitialized)
		{
			int success = glfwInit();
			STARSEACOREASSERT(success, "Could not initialize GLFW!");
			starsseaGLFWInitialized = true;
		}

		StarsSeaWindow = glfwCreateWindow((int)props.Width, (int)props.Height, starsseaData.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(StarsSeaWindow);
		glfwSetWindowUserPointer(StarsSeaWindow, &starsseaData);
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
		starsseaData.VSync = enabled;
	}

	bool StarsSeaWindows::IsVSync() const
	{
		return starsseaData.VSync;
	}
}