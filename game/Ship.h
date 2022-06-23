#pragma once
#include "../Engine.h"

class Ship
{
	const float speed = 400;
	const int timeBetweenShots = 120;
	int lastShot = 0;
	int lives = 3;
	Core::Entity* entity;
public:

	void Initialize();

	void Update();

	void Reset();

	int GetStartingLives() const;
};

