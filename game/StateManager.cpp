#include "StateManager.h"
#include "GameScene.h"
#include "MenuScene.h"
#include "GameUI.h"


extern GameScene gameScene;
extern MenuScene menuScene;
extern GameUI gameUI;

StateManager stateManager;

void StateManager::Initialize()
{
	gameOverSprite = new Core::Sprite("res/textures/gameover.png", vector2(240, 360), vector2(256, 64), Color(0xFFFFFFFF), 0);
	gameOverSprite->Load();
	gameOverSprite->SetOrigin(vector2(0.5f, 0.5f));

	gameOverOverlay = new Core::Sprite("res/textures/white.png", vector2(0, 0), vector2(480, 720), Color(0xAAAAAA88), 0);
	gameOverOverlay->Load();



	gameScene.Initialize();
	menuScene.Initialize();
}

void StateManager::Update()
{
	if (State == 0)
	{
		menuScene.Update();
	}
	if (State == 1)
	{
		gameScene.Update();
	}
	if (State == 2)
	{
		gameScene.Update();
		DrawGameOverOverlay();
	}
}

float StateManager::GetTimeScale() const
{
	return timeScale;
}

void StateManager::SetTimeScale(float scale)
{
	timeScale = scale;
}

void StateManager::DrawGameOverOverlay()
{
	if (Core::GetTime() - gameOverTime > gameOverDuration)
		State = 0;

	gameOverOverlay->Draw();
	gameOverSprite->Draw();
}
