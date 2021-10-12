#include "Input.h"

extern Core::Window G_Window;
Core::InputManager G_Input;

int KEYS[] = { GLFW_KEY_SPACE, GLFW_KEY_APOSTROPHE, GLFW_KEY_COMMA, GLFW_KEY_MINUS, GLFW_KEY_PERIOD, GLFW_KEY_SLASH, GLFW_KEY_0, GLFW_KEY_1, GLFW_KEY_2, GLFW_KEY_3, GLFW_KEY_4, GLFW_KEY_5, GLFW_KEY_6, GLFW_KEY_7, GLFW_KEY_8, GLFW_KEY_9, GLFW_KEY_SEMICOLON, GLFW_KEY_EQUAL, GLFW_KEY_A, GLFW_KEY_B, GLFW_KEY_C, GLFW_KEY_D, GLFW_KEY_E, GLFW_KEY_F, GLFW_KEY_G, GLFW_KEY_H, GLFW_KEY_I, GLFW_KEY_J, GLFW_KEY_K, GLFW_KEY_L, GLFW_KEY_M, GLFW_KEY_N, GLFW_KEY_O, GLFW_KEY_P, GLFW_KEY_Q, GLFW_KEY_R, GLFW_KEY_S, GLFW_KEY_T, GLFW_KEY_U, GLFW_KEY_V, GLFW_KEY_W, GLFW_KEY_X, GLFW_KEY_Y, GLFW_KEY_Z, GLFW_KEY_LEFT_BRACKET, GLFW_KEY_BACKSLASH, GLFW_KEY_RIGHT_BRACKET, GLFW_KEY_GRAVE_ACCENT, GLFW_KEY_WORLD_1, GLFW_KEY_WORLD_2, GLFW_KEY_ESCAPE, GLFW_KEY_ENTER, GLFW_KEY_TAB, GLFW_KEY_BACKSPACE, GLFW_KEY_INSERT, GLFW_KEY_DELETE, GLFW_KEY_RIGHT, GLFW_KEY_LEFT, GLFW_KEY_DOWN, GLFW_KEY_UP, GLFW_KEY_PAGE_UP, GLFW_KEY_PAGE_DOWN, GLFW_KEY_HOME, GLFW_KEY_END, GLFW_KEY_CAPS_LOCK, GLFW_KEY_SCROLL_LOCK, GLFW_KEY_NUM_LOCK, GLFW_KEY_PRINT_SCREEN, GLFW_KEY_PAUSE, GLFW_KEY_F1, GLFW_KEY_F2, GLFW_KEY_F3, GLFW_KEY_F4, GLFW_KEY_F5, GLFW_KEY_F6, GLFW_KEY_F7, GLFW_KEY_F8, GLFW_KEY_F9, GLFW_KEY_F10, GLFW_KEY_F11, GLFW_KEY_F12, GLFW_KEY_F13, GLFW_KEY_F14, GLFW_KEY_F15, GLFW_KEY_F16, GLFW_KEY_F17, GLFW_KEY_F18, GLFW_KEY_F19, GLFW_KEY_F20, GLFW_KEY_F21, GLFW_KEY_F22, GLFW_KEY_F23, GLFW_KEY_F24, GLFW_KEY_F25, GLFW_KEY_KP_0, GLFW_KEY_KP_1, GLFW_KEY_KP_2, GLFW_KEY_KP_3, GLFW_KEY_KP_4, GLFW_KEY_KP_5, GLFW_KEY_KP_6, GLFW_KEY_KP_7, GLFW_KEY_KP_8, GLFW_KEY_KP_9, GLFW_KEY_KP_DECIMAL, GLFW_KEY_KP_DIVIDE, GLFW_KEY_KP_MULTIPLY, GLFW_KEY_KP_SUBTRACT, GLFW_KEY_KP_ADD, GLFW_KEY_KP_ENTER, GLFW_KEY_KP_EQUAL, GLFW_KEY_LEFT_SHIFT, GLFW_KEY_LEFT_CONTROL, GLFW_KEY_LEFT_ALT, GLFW_KEY_LEFT_SUPER, GLFW_KEY_RIGHT_SHIFT, GLFW_KEY_RIGHT_CONTROL, GLFW_KEY_RIGHT_ALT, GLFW_KEY_RIGHT_SUPER, GLFW_KEY_MENU };

namespace Core
{

	InputManager::InputManager()
	{
		memset(PressTable, KS_UP, sizeof(PressTable));
		memset(StateTable, KS_UP, sizeof(StateTable));

		int q = GLFW_KEY_E;
	}

	InputManager::~InputManager()
	{
		for(int i=0;i<m_cursors.size();i++)
			glfwDestroyCursor(m_cursors[i]);
	}

	void InputManager::Initialize()
	{
		m_cursors.push_back(glfwCreateStandardCursor(GLFW_ARROW_CURSOR));
		m_cursors.push_back(glfwCreateStandardCursor(GLFW_IBEAM_CURSOR));
		m_cursors.push_back(glfwCreateStandardCursor(GLFW_CROSSHAIR_CURSOR));
		m_cursors.push_back(glfwCreateStandardCursor(GLFW_HAND_CURSOR));
		m_cursors.push_back(glfwCreateStandardCursor(GLFW_HRESIZE_CURSOR));
		m_cursors.push_back(glfwCreateStandardCursor(GLFW_VRESIZE_CURSOR));
	}

	int GetCurrentState(int previous, int current)
	{
		if (previous && !current)
			return KS_RELEASE;

		if (!previous && current)
			return KS_PRESS;

		return current;
	}

	void InputManager::Update()
	{
		GLFWwindow* pWindow = G_Window.Get();

		int Length = sizeof(KEYS) / sizeof(int);
		for (int i = 0; i < Length; i++)
		{
			int KEY = KEYS[i];
			int CURRENT_STATE = glfwGetKey(pWindow, KEY);
			StateTable[KEY] = GetCurrentState(PressTable[KEY], CURRENT_STATE);
			PressTable[KEY] = CURRENT_STATE;
		}

		int LEFT_MOUSE_STATE = glfwGetMouseButton(pWindow, GLFW_MOUSE_BUTTON_LEFT);
		StateTable[0] = GetCurrentState(PressTable[0], LEFT_MOUSE_STATE);
		PressTable[0] = LEFT_MOUSE_STATE;

		int RIGHT_MOUSESTATE = glfwGetMouseButton(pWindow, GLFW_MOUSE_BUTTON_RIGHT);
		StateTable[1] = GetCurrentState(PressTable[1], RIGHT_MOUSESTATE);
		PressTable[1] = RIGHT_MOUSESTATE;
	}

	int InputManager::GetKeyState(int Key)
	{
		return StateTable[Key];
	}

	int InputManager::GetLeftMouse()
	{
		return StateTable[0];
	}

	int InputManager::GetRightMouse()
	{
		return StateTable[1];
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

	void InputManager::SetCursorID(int Cursor)
	{
		glfwSetCursor(G_Window.Get(), m_cursors[Cursor]);
	}
}