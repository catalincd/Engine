#pragma once
#include "../Engine.h"
#include "Ship.h"

class Game
{
	Ship ship;
	Core::Entity* background;

public:
	void Initialize();

	void Update();
};