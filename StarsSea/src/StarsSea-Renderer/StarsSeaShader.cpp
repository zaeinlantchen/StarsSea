#include "StarsSea-pch.h"
#include "StarsSeaShader.h"

#include <glad/glad.h>

namespace StarsSea
{
	StarsSeaShader::StarsSeaShader(const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		// 创建一个空的顶点着色器句柄
		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

		// 发送顶点着色器源代码到GL
		// 笔记：std::string的.c_str是以NULL字符结尾的。
		const GLchar* source = (const GLchar*)vertexSrc.c_str();
		glShaderSource(vertexShader, 1, &source, 0);

		// 顶点着色器编译
		glCompileShader(vertexShader);

		GLint isCompiled = 0;
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);
		if (isCompiled == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

			// 最大长度包含NULL字符
			std::vector<GLchar> infoLog(maxLength);
			glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &infoLog[0]);

			//释放着色器。
			glDeleteShader(vertexShader);

			// 使用infoLog按需处理。

			// 
			STARSEACOREERROR("顶点着色器编译失败：{0}", infoLog.data());
			return;
		}

		// 创建一个空的片段着色器句柄
		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		// 发送片段着色器源代码到GL
		// 笔记：std::string的.c_str是以NULL字符结尾的。
		source = (const GLchar*)fragmentSrc.c_str();
		glShaderSource(fragmentShader, 1, &source, 0);

		// 片段着色器编译
		glCompileShader(fragmentShader);

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isCompiled);
		if (isCompiled == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

			// 最大长度包含NULL字符
			std::vector<GLchar> infoLog(maxLength);
			glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &infoLog[0]);

			// 释放片段着色器
			glDeleteShader(fragmentShader);
			// 修改顶点着色器
			glDeleteShader(vertexShader);

			// 使用infoLog按需处理。

			// 在这个简单的项目中，我们就直接返回
			STARSEACOREERROR("片段着色器编译失败：{0}", infoLog.data());
			return;
		}

		// 顶点/片段着色器都编译成功了。
		// 现在我们链接它们到一个着色器程序中
		// 获取一个空的程序对象句柄
		starsseaRendererID = glCreateProgram();
		GLuint program = starsseaRendererID;

		// 到达程序对象附加着色器
		glAttachShader(program, vertexShader);
		glAttachShader(program, fragmentShader);

		// 链接着色器程序
		glLinkProgram(program);

		// 笔记：链接着色器程序需要比编译单个着色器更多的时间。
		GLint isLinked = 0;
		glGetProgramiv(program, GL_LINK_STATUS, (int*)&isLinked);
		if (isLinked == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

			// 最大长度包含NULL字符
			std::vector<GLchar> infoLog(maxLength);
			glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

			// 释放程序
			glDeleteProgram(program);
			// 不要忘了释放着色器
			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);

			// 使用infoLog按需处理。

			// 在这个简单的项目中，我们就直接返回
			STARSEACOREERROR("链接着色器程序失败：{0}", infoLog.data());
			return;
		}

		// 总是释放着色器，因为它们已经链接到程序中了，之后不再需要它们了。
		glDetachShader(program, vertexShader);
		glDetachShader(program, fragmentShader);
	}

	StarsSeaShader::~StarsSeaShader()
	{
		glDeleteProgram(starsseaRendererID);
	}

	void StarsSeaShader::Bind() const
	{
		glUseProgram(starsseaRendererID);
	}

	void StarsSeaShader::Unbind() const
	{
		glUseProgram(0);
	}
}


