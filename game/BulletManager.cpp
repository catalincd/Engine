#include "BulletManager.h"
#include "AsteroidManager.h"

BulletManager bulletManager;
extern AsteroidManager asteroidManager;

void BulletManager::Shoot(const vector2& pos)
{
	Core::Entity* newBullet = new Core::Entity("bullet", vector2(0, -50) + pos, vector2(16, 32));
	newBullet->Load();
	newBullet->SetCollisionRadius(8);
	newBullet->SetApplyLightType(1);
	bullets.push_back(newBullet);
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
			asteroidManager.remove(idx);
			bullets.erase(bullets.begin() + i);
			i--;
			continue;
		}

		bullets[i]->AddToPosition(vector2(0, Core::UnitsPerSecond(bulletSpeed)));

		bullets[i]->Update();
		bullets[i]->Draw();

	}
}