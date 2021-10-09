#pragma once

#include "../basic.h"



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
		Window();
		Window(const char* title, int width, int height);
		~Window();

		void Start();
		void Update();

		void Initialize(const char* title, int width, int height);
		void AddFunction(Function function);
		void CheckForErrors();
		inline GLFWwindow* Get() { return m_window; }
		inline int GetWidth() { return m_width; }
		inline int GetHeight() { return m_height; }
		vector2 GetWindowSize() { return vector2(m_width, m_height); }
	};
}