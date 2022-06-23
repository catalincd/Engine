#pragma once
#include "../Engine.h"

//0 - MENU
//1 - GAME
//2 - PAUSE
//3 - GAMEOVER

class StateManager
{
	float timeScale = 1.0f;
	int gameOverDuration = 3000;
	Core::Sprite* gameOverSprite;
	Core::Sprite* gameOverOverlay;
	
public:
	int State = 0;
	int gameOverTime;

	void Initialize();

	void Update();

	float GetTimeScale() const;
	void SetTimeScale(float scale);
	void DrawGameOverOverlay();
};

