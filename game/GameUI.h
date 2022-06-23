#pragma once
#include "../Engine.h"

class GameUI
{
	Core::Text* fpsText;
	Core::Sprite* heartSprite;
public:

	void Initialize();

	void Update();
};

