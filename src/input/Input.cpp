#include "Input.h"

extern Core::Window G_Window;
Core::InputManager Input;

namespace Core
{

	InputManager::InputManager()
	{
		m_cursors.push_back(glfwCreateStandardCursor(GLFW_ARROW_CURSOR));
		m_cursors.push_back(glfwCreateStandardCursor(GLFW_IBEAM_CURSOR));
		m_cursors.push_back(glfwCreateStandardCursor(GLFW_CROSSHAIR_CURSOR));
		m_cursors.push_back(glfwCreateStandardCursor(GLFW_HAND_CURSOR));
		m_cursors.push_back(glfwCreateStandardCursor(GLFW_HRESIZE_CURSOR));
		m_cursors.push_back(glfwCreateStandardCursor(GLFW_VRESIZE_CURSOR));
	}

	InputManager::~InputManager()
	{
		for(int i=0;i<m_cursors.size();i++)
			glfwDestroyCursor(m_cursors[i]);
	}

	int InputManager::GetKeyState(int Key)
	{
		return glfwGetKey(G_Window.Get(), Key);
	}

	int InputManager::GetLeftMouse()
	{
		return glfwGetMouseButton(G_Window.Get(), GLFW_MOUSE_BUTTON_LEFT);
	}

	int InputManager::GetRightMouse()
	{
		return glfwGetMouseButton(G_Window.Get(), GLFW_MOUSE_BUTTON_RIGHT);
	}
	vector2 InputManager::GetCursorPosition()
	{
		double x, y;
		glfwGetCursorPos(G_Window.Get(), &x, &y);
		return vector2(x, y);
	}

	void InputManager::SetCursor(int Cursor)
	{
		glfwSetCursor(G_Window.Get(), m_cursors[Cursor - GLFW_ARROW_CURSOR]);
	}
}