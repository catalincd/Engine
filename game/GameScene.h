#pragma once
#include "../Engine.h"
#include "Ship.h"

class GameScene
{
	Core::Entity* background;

public:
	void Initialize();

	void Update();
};

