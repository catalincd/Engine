#include "window.h"

namespace Core
{
	Window::Window(const char* title, int width, int height)
	{
		m_title = title;
		m_width = width;
		m_height = height;

		


		if (!glfwInit())
			std::cout << "Failed to initialize GLFW" << std::endl;

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

		m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
		if (!m_window)
		{
			glfwTerminate();
			std::cout << "Failed to initialize Window" << std::endl;
			return;
		}

		glfwMakeContextCurrent(m_window);
		if (!gladLoadGL()) {
			std::cout << "Failed to initialize OpenGL context" << std::endl;
			return;
		}
		glfwSwapInterval(1);
		std::cout << glGetString(GL_VERSION) << std::endl;
		std::cout << "Initialized window!" << std::endl;		
	}

	Window::~Window()
	{
		glfwDestroyWindow(m_window);
		glfwTerminate();
	}

	void Window::Start()
	{
		while (!glfwWindowShouldClose(m_window))
		{
			Update();
			glfwSwapBuffers(m_window);
			glfwPollEvents();
		}
	}

	void Window::Update()
	{
		for (int i = 0; i < m_functions.size(); i++)
		{
			m_functions[i]();
		}

		if (DEBUG)
		{
			GLenum err;
			while ((err = glGetError()) != GL_NO_ERROR)
			{
				std::cout << "GL Context error: " << err << std::endl;
			}
		}
	}

	void Window::AddFunction(Function function)
	{
		m_functions.push_back(function);
	}
}