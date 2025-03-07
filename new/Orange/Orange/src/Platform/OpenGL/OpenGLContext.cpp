#include "ogpch.h"
#include "Platform/OpenGL/OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

namespace Orange
{
	
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		:o_WindowHandle(windowHandle)
	{
		OG_CORE_ASSERT(windowHandle, "window 句柄为空！");
	}

	void OpenGLContext::Init()
	{
		HZ_PROFILE_FUNCTION();

		glfwMakeContextCurrent(o_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		OG_CORE_ASSERT(status, "glad 初始化失败！");

		OG_CORE_INFO("OpenGL 属性: ");
		OG_CORE_INFO("  出厂商: {0}", (char*)glGetString(GL_VENDOR));
		OG_CORE_INFO("  型  号: {0}", (char*)glGetString(GL_RENDERER));
		OG_CORE_INFO("  版  本: {0}", (char*)glGetString(GL_VERSION));

		OG_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "Hazel requires at least OpenGL version 4.5!");

	}

	void OpenGLContext::SwapBuffers()
	{
		HZ_PROFILE_FUNCTION();

		glfwSwapBuffers(o_WindowHandle);
	}

}