#pragma once
#include "../display/window.h"

namespace Core
{
	class InputManager
	{
		std::vector<GLFWcursor*> m_cursors;
	public:
		InputManager();
		~InputManager();


		int GetKeyState(int Key);
		int GetLeftMouse();
		int GetRightMouse();
		vector2 GetCursorPosition();

		void SetCursor(int Cursor);
	};
}