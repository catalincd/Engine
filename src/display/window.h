#pragma once

#include "../basic.h"

typedef void (*Function) ();

namespace Core
{
	class Window
	{
		int m_width;
		int m_height;
		const char* m_title;
		GLFWwindow* m_window;
		std::vector<Function> m_functions;

	public:
		Window(const char* title, int width, int height);
		~Window();

		void Start();
		void Update();

		void AddFunction(Function function);
		inline GLFWwindow* Get() { return m_window; }
		inline int GetWidth() { return m_width; }
		inline int GetHeight() { return m_height; }
	};
}