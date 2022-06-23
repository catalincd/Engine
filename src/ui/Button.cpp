#include "Button.h"
#include "../Input/Input.h"
#include "../basic.h"

extern Core::InputManager G_Input;

namespace Core
{
	void Button::DrawButton()
	{
		Sprite::Draw();
		Update();
	}

	void Button::Update()
	{
		vector2 p = G_Input.GetCursorPosition();
		bool isCursorInButton = (isPointInTriangle(p, topLeft, topRight, bottomRight) || isPointInTriangle(p, bottomRight, bottomLeft, topLeft));

		isPressed = false;
		isReleased = false;

		if (isCursorInButton)
		{
			G_Input.SetCursorID(3);

			isPressed = (G_Input.GetLeftMouse() == KS_PRESS);
			isReleased = (G_Input.GetLeftMouse() == KS_RELEASE);
		}
	}

	bool Button::Pressed()
	{
		return isPressed;
	}

	bool Button::Released()
	{
		return isReleased;
	}
}