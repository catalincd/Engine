#pragma once
#include "../basic.h"
#include "window.h"


namespace Core
{
	class Screen
	{
		vector2 Resolution;
	public:

		
		vector2 GetScreenSize() const;
		void SetScreenSize(vector2 v);
	};
}