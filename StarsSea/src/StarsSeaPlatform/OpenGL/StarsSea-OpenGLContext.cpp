#include "../../StarsSea-pch.h"
#include "StarsSea-OpenGLContext.h"

#include <GLFW/glfw3.h>

#include <glad/glad.h>

namespace StarsSea {
	OpenGLContext::OpenGLContext(GLFWwindow* starsseaWindow)
		: StarsSeaWindow(starsseaWindow)
	{
		STARSEACOREASSERT(StarsSeaWindow, "窗口句柄为空！");
	}
	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(StarsSeaWindow);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		STARSEACOREASSERT(status, "GLAD 初始化失败");

		STARSEACOREINFO("OpenGL 信息：");
		STARSEACOREINFO("OpenGL Vendor: {0}", (const char*)glGetString(GL_VENDOR));
		STARSEACOREINFO("OpenGL Renderer: {0}", (const char*)glGetString(GL_RENDERER));
		STARSEACOREINFO("OpenGL Version: {0}", (const char*)glGetString(GL_VERSION));

	}
	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(StarsSeaWindow);
	}
}