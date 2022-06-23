#include "BulletManager.h"
#include "AsteroidManager.h"
#include <Windows.h>

BulletManager bulletManager;
extern AsteroidManager asteroidManager;
extern Core::SoundManager G_SoundManager;

void BulletManager::Shoot(const vector2& pos)
{
	G_SoundManager.PlaySoundEffect("res/audio/shoot_new.wav");

	Core::Entity* newBullet = new Core::Entity("bullet", vector2(0, -50) + pos, vector2(16, 32));
	newBullet->Load();
	newBullet->SetCollisionRadius(8);
	newBullet->SetApplyLightType(1);
	bullets.push_back(newBullet);
}

void BulletManager::Initialize()
{
	G_SoundManager.LoadSound("res/audio/shoot_new.wav");
	G_SoundManager.LoadSound("res/audio/explosion.wav");
}

void BulletManager::Update()
{
	for (int i = 0;i < bullets.size();i++)
	{
		if (bullets[i]->GetPosition().y < -100)
		{
			bullets.erase(bullets.begin() + i);
			i--;
			continue;
		}

		int idx = asteroidManager.checkCollision(bullets[i]);
		if (idx != -1)
		{
			G_SoundManager.PlaySoundEffect("res/audio/explosion.wav");
			asteroidManager.remove(idx);
			bullets.erase(bullets.begin() + i);
			i--;
			continue;
		}

		bullets[i]->AddToPosition(vector2(0, Core::UnitsPerSecond(bulletSpeed) * stateManager.GetTimeScale()));

		bullets[i]->Update();
		bullets[i]->Draw();

	}
}