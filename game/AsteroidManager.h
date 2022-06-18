#pragma once
#include "../Engine.h"

class AsteroidManager
{
	std::vector<Core::Entity*> asteroids;
	int lastAdded = 0;
	int stride = 800;
	float speed = 120;

	int getPositionX()
	{
		return int(float(rand()) / float(RAND_MAX) * 420) + 30;
	}

	int getRandomAngle()
	{
		return int(float(rand()) / float(RAND_MAX) * 360);
	}

	float getRandomScaleFactor()
	{
		return (float(rand()) / float(RAND_MAX) * 0.4 + 0.8);
	}

public:
	void Initialize()
	{

	}

	void Update()
	{
		stride = 800 - (int(float(Core::min(Core::GetTime(), 5000)) / 5000) * 300);
		speed = 120 * (float(Core::min(Core::GetTime(), 5000) / 5000) + 1.0f);

		if (Core::GetTime() - lastAdded > stride)
		{
			lastAdded = Core::GetTime();
			vector2 size = vector2(64, 64) * getRandomScaleFactor();
			Core::Entity* asteroid = new Core::Entity("asteroid64", vector2(getPositionX(), -30), size);
			asteroid->Load();
			asteroid->SetCollisionRadius(Core::magnitude(size) * 0.5f * 0.8f);
			asteroid->SetApplyLightType(0);
			asteroid->SetAngle(getRandomAngle());
			asteroids.push_back(asteroid);
		}

		float currentSpeed = Core::UnitsPerSecond(speed);
		for (int i = 0;i < asteroids.size();i++)
		{
			asteroids[i]->AddToPosition(vector2(0, currentSpeed));
			asteroids[i]->Update();
			asteroids[i]->Draw();
		}
	}

	int checkCollision(Core::Entity* other)
	{
		for (int i = 0;i < asteroids.size();i++)
		{
			if (asteroids[i]->IsColliding(*other))
			{
				return i;
			}
		}

		return -1;
	}

	void remove(int idx)
	{
		asteroids.erase(asteroids.begin() + idx);
	}
};

