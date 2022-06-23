#pragma once
#include "../Engine.h"

class MenuScene
{
	Core::Sprite* background;
	Core::Button* playText;
public:
	void Initialize();

	void Update();
};

