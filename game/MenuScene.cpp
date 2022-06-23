#include "MenuScene.h"
#include "../Engine.h"
#include "StateManager.h"
#include "Ship.h"
#include "AsteroidManager.h"

extern StateManager stateManager;
extern Ship ship;
extern AsteroidManager asteroidManager;

MenuScene menuScene;

void MenuScene::Initialize()
{
	background = new Core::Sprite("res/entities/diffuse/background.png", vector2(0, 0), vector2(720, 720), Color(0xFFFFFFFF), 0);
	background->Load();
	
	playText = new Core::Button("res/textures/play.png", vector2(240, 360), vector2(128, 64), Color(0xFFFFFFFF), 0);
	playText->Load();
	playText->SetOrigin(vector2(0.5f, 0.5f));
}

void MenuScene::Update()
{
	background->Draw();

	playText->DrawButton();

	if (playText->Pressed())
	{
		stateManager.State = 1;
		stateManager.SetTimeScale(1.0f);

		asteroidManager.RemoveAll();
		ship.Reset();
	}
}