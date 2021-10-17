#include "Screen.h"

Core::Screen G_Screen;

namespace Core
{
	vector2 Screen::GetScreenSize() const
	{
		return Resolution;
	}

	void Screen::SetScreenSize(vector2 v)
	{
		Resolution = v;
	}
}