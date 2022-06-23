#include "Ship.h"
#include "BulletManager.h"
#include "AsteroidManager.h"
#include "StateManager.h"

extern Core::InputManager G_Input;
extern Core::TimeManager G_TimeMananger;
extern Core::SoundManager G_SoundManager;
extern BulletManager bulletManager;
extern AsteroidManager asteroidManager;
extern StateManager stateManager;

Ship ship;

void Ship::Initialize()
{
	entity = new Core::Entity("ship", vector2(240, 600), vector2(96, 96));
	entity->Load();
	entity->SetApplyLightType(0);
	entity->SetCollisionRadius(45);
}

void Ship::Reset()
{
	lives = 3;
}

void Ship::Update()
{
	if (G_Input.GetKeyState(GLFW_KEY_LEFT) == KS_DOWN)
	{
		entity->AddToPosition(vector2(Core::UnitsPerSecond(-speed) * stateManager.GetTimeScale(), 0));
	}

	if (G_Input.GetKeyState(GLFW_KEY_RIGHT) == KS_DOWN)
	{
		entity->AddToPosition(vector2(Core::UnitsPerSecond(speed) * stateManager.GetTimeScale(), 0));
	}

	if (G_Input.GetKeyState(GLFW_KEY_SPACE) == KS_PRESS && stateManager.GetTimeScale() > 0.05f)
	{
		if (Core::GetTime() - lastShot > timeBetweenShots)
		{
			lastShot = Core::GetTime();
			bulletManager.Shoot(entity->GetPosition());
		}
	}

	if (entity->GetPosition().x < 70)
	{
		entity->SetPosition(vector2(70, entity->GetPosition().y));
	}

	if (entity->GetPosition().x > 410)
	{
		entity->SetPosition(vector2(410, entity->GetPosition().y));
	}

	int asteroidId = asteroidManager.checkCollision(entity);
	if (asteroidId != -1)
	{
		asteroidManager.remove(asteroidId);
		G_SoundManager.PlaySoundEffect("res/audio/explosion.wav");
		lives--;
		if (!lives)
		{
			stateManager.SetTimeScale(0.0f);
			stateManager.State = 2;
			stateManager.gameOverTime = Core::GetTime();
		}
	}

	if (lives)
	{
		entity->Update();
		entity->Draw();
	}
	
}


int Ship::GetStartingLives() const
{
	return lives;
}