#pragma once
#include "Element.h"
#include "Sprite.h"

namespace Core
{
	class Button : public Sprite
	{
		bool isPressed = false;
		bool isReleased = false;


	public:
		using Sprite::Sprite;

		void Draw();
		void Update();

		bool Pressed();
		bool Released();
	};
}