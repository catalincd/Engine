#include "Ship.h"
#include "BulletManager.h"

extern Core::InputManager G_Input;
extern Core::TimeManager G_TimeMananger;
extern BulletManager bulletManager;

void Ship::Initialize()
{
	entity = new Core::Entity("ship", vector2(240, 600), vector2(96, 96));
	entity->Load();
	entity->SetApplyLightType(0);
}


void Ship::Update()
{
	if (G_Input.GetKeyState(GLFW_KEY_LEFT) == KS_DOWN)
	{
		entity->AddToPosition(vector2(Core::UnitsPerSecond(-speed), 0));
	}

	if (G_Input.GetKeyState(GLFW_KEY_RIGHT) == KS_DOWN)
	{
		entity->AddToPosition(vector2(Core::UnitsPerSecond(speed), 0));
	}

	if (G_Input.GetKeyState(GLFW_KEY_SPACE) == KS_PRESS)
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

	entity->Update();
	entity->Draw();
}


