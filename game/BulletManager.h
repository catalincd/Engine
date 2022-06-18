#pragma once
#include "../Engine.h"

class BulletManager
{
	const float bulletSpeed = -500;
	std::vector<Core::Entity*> bullets;
public:

	void Shoot(const vector2& pos);

	void Update();
};

