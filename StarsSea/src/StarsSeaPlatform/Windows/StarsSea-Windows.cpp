#include "StarsSea-Windows.h"
#include "../../StarsSea/Log.h"]

#include "../../StarsSeaEvents/ApplicationEvent.h"
#include "../../StarsSeaEvents/StarsSea-MouseEvent.h"
#include "../../StarsSeaEvents/StarsSea-KeyEvent.h"


namespace StarsSea{
	
	static bool starsseaGLFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* description)
	{
		STARSEACOREERROR("GLFW Error ({0}): {1}", error, description);
	}

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
			glfwSetErrorCallback(GLFWErrorCallback);
			starsseaGLFWInitialized = true;
		}

		StarsSeaWindow = glfwCreateWindow((int)props.Width, (int)props.Height, starsseaData.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(StarsSeaWindow);
		glfwSetWindowUserPointer(StarsSeaWindow, &starsseaData);
		SetVSync(true);

		glfwSetWindowSizeCallback(StarsSeaWindow, [](GLFWwindow* starsseawindow, int starsseawidth, int starsseaheight) {
			StarsSeaWindowData& starsseadata = *(StarsSeaWindowData*)glfwGetWindowUserPointer(starsseawindow);

			starsseadata.Width = starsseawidth;
			starsseadata.Height = starsseaheight;

			WindowResizeEvent event(starsseawidth, starsseaheight);
			starsseadata.EventCallback(event);
			});

		glfwSetWindowCloseCallback(StarsSeaWindow, [](GLFWwindow* starsseawindow) {
			StarsSeaWindowData& starsseadata = *(StarsSeaWindowData*)glfwGetWindowUserPointer(starsseawindow);
			WindowCloseEvent event;
			starsseadata.EventCallback(event);
			});

		glfwSetKeyCallback(StarsSeaWindow, [](GLFWwindow* starsseawindow, int key, int scancode, int action, int mods) {
			StarsSeaWindowData& starsseadata = *(StarsSeaWindowData*)glfwGetWindowUserPointer(starsseawindow);
			switch (action)
				{
					case GLFW_PRESS:
					{
						KeyPressedEvent event(key, 0);
						starsseadata.EventCallback(event);
						break;
					}
					case GLFW_RELEASE:
					{
						KeyReleasedEvent event(key);
						starsseadata.EventCallback(event);
						break;
					}
					case GLFW_REPEAT:
					{
						KeyPressedEvent event(key, 1);
						starsseadata.EventCallback(event);
						break;
					}
				}
			});
		
		glfwSetMouseButtonCallback(StarsSeaWindow, [](GLFWwindow* starsseawindow, int button, int action, int mods) {
			StarsSeaWindowData& starsseadata = *(StarsSeaWindowData*)glfwGetWindowUserPointer(starsseawindow);
			switch (action)
				{
					case GLFW_PRESS:
					{
						MouseButtonPressedEvent event(button);
						starsseadata.EventCallback(event);
						break;
					}
					case GLFW_RELEASE:
					{
						MouseButtonReleasedEvent event(button);
						starsseadata.EventCallback(event);
						break;
					}
				}
			});

		glfwSetScrollCallback(StarsSeaWindow, [](GLFWwindow* starsseawindow, double xOffset, double yOffset) {
			StarsSeaWindowData& starsseadata = *(StarsSeaWindowData*)glfwGetWindowUserPointer(starsseawindow);
			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			starsseadata.EventCallback(event);
			});

		glfwSetCursorPosCallback(StarsSeaWindow, [](GLFWwindow* starsseawindow, double xPos, double yPos) {
			StarsSeaWindowData& starsseadata = *(StarsSeaWindowData*)glfwGetWindowUserPointer(starsseawindow);
			MouseMovedEvent event((float)xPos, (float)yPos);
			starsseadata.EventCallback(event);
			});
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