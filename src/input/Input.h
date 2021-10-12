#pragma once
#include "../display/window.h"
#include "../GlobalController/GlobalController.h"

#define MAX_KEYS 512


#define KS_UP 0
#define KS_DOWN 1
#define KS_PRESS 2
#define KS_RELEASE 3

#define K_LMOUSE 0
#define K_RMOUSE 1

namespace Core
{
	class InputManager : public GlobalController
	{
		bool PressTable[MAX_KEYS];
		int StateTable[MAX_KEYS];

		std::vector<GLFWcursor*> m_cursors;
	public:
		InputManager();
		~InputManager();

		void Initialize();
		void Update();
		int GetKeyState(int Key);
		int GetLeftMouse();
		int GetRightMouse();
		vector2 GetCursorPosition();

		void SetCursor(int Cursor);
		void SetCursorID(int Cursor);
	};
}
