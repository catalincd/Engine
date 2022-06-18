#pragma once
#include "../Engine.h"

class Ship
{
	const float speed = 400;
	const int timeBetweenShots = 150;
	int lastShot = 0;
	Core::Entity* entity;
public:

	void Initialize();

	void Update();
};

