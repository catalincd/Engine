#include "window.h"
#include "Screen.h"
#include "../World/World.h"
#include "../time/TimeManager.h"

extern Core::TimeManager G_TimeManager;
extern Core::Screen G_Screen;
extern Core::World G_World;
Core::Window G_Window;
///Add Callback system and Log System in future builds

static void ErrorCallback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}

void WindowResizeCallback(GLFWwindow* window, int width, int height)
{
	G_Screen.SetScreenSize(vector2(width, height));
	G_World.ComputeBucketLimits(vector2(width, height));
	std::cout << "Window resized: " << width << " x " << height << std::endl;
}


namespace Core
{
	Window::Window()
	{

	}

	Window::Window(const char* title, int width, int height)
	{
		Initialize(title, width, height);
	}

	void Window::Initialize(const char* title, int width, int height)
	{
		m_title = title;
		m_width = width;
		m_height = height;


		glfwSetErrorCallback(ErrorCallback);

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

		glfwSetWindowSizeCallback(m_window, WindowResizeCallback);

		std::cout << glGetString(GL_VERSION) << std::endl;
		std::cout << "Initialized window!" << std::endl;


		glEnable(GL_BLEND);
		glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		
		
		glEnable(GL_POINT_SMOOTH);
		glDisable(GL_DEPTH_TEST);
		glEnable(GL_ALPHA_TEST);
		
		glfwSwapInterval(1);
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
			G_TimeManager.SetCurrentFrameStartTime(glfwGetTime());

			glfwGetFramebufferSize(G_Window.Get(), &m_width, &m_height);
			glfwSwapBuffers(m_window);
			glfwPollEvents();
			Update();

			G_TimeManager.Update();
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
			CheckForErrors();
		}
	}

	void Window::CheckForErrors()
	{
		GLenum err;
		while ((err = glGetError()) != GL_NO_ERROR)
		{
			std::cout << "GL Context error: " << err << std::endl;
		}
	}

	void Window::AddFunction(Function function)
	{
		m_functions.push_back(function);
	}
}


