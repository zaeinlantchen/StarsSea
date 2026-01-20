#include "../../StarsSea-pch.h"
#include "StarsSea-OpenGLContext.h"

#include <GLFW/glfw3.h>

#include <glad/glad.h>

namespace StarsSea {
	OpenGLContext::OpenGLContext(GLFWwindow* starsseaWindow)
		: StarsSeaWindow(starsseaWindow)
	{
		STARSEACOREASSERT(StarsSeaWindow, "窗口句柄无效!");
	}
	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(StarsSeaWindow);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		STARSEACOREASSERT(status, "GLAD 初始化失败!");
	}
	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(StarsSeaWindow);
	}
}