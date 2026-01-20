#pragma once

#include "../../StarsSea-Renderer/StarsSeaGraphicsContext.h"

struct GLFWwindow;
namespace StarsSea {
	class OpenGLContext : public GraphicsContext {
		public:
			OpenGLContext(GLFWwindow* starsseaWindow);
			virtual void Init() override;
			virtual void SwapBuffers() override;
		private:
			GLFWwindow* StarsSeaWindow;
	};
}