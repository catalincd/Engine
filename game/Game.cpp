#include "Game.h"
#include "GameScene.h"
#include "StateManager.h"


Game GAME;

extern StateManager stateManager;

void Game::Initialize()
{
	stateManager.Initialize();
}

void Game::Update()
{
	stateManager.Update();
}