#include "GameUI.h"
#include "Ship.h"

GameUI gameUI;
extern Ship ship;

void GameUI::Initialize()
{
	fpsText = new Core::Text("", vector2(4, 0));
	fpsText->SetScale(0.25);
	fpsText->SetOrigin(vector2(0.0f));

	heartSprite = new Core::Sprite("res/textures/heart.png", vector2(200, 200), vector2(64, 64), Color(0xFFFFFFFF), 0);
	heartSprite->Load();
}

void GameUI::Update()
{
	fpsText->SetText("FPS: " + std::to_string(Core::GetFPSRate()));
	fpsText->Draw();

	int lives = ship.GetStartingLives();
	for (int i = 0; i < lives; i++)
	{
		heartSprite->Draw(vector2(444 - i * 36, 2), vector2(32, 32), Color(0xFFFFFFFF), 0);
	}

	//heartSprite->Draw();
}