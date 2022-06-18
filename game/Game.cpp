#include "Game.h"
#include "BulletManager.h"
#include "AsteroidManager.h"

Game GAME;
extern BulletManager bulletManager;
extern AsteroidManager asteroidManager;

extern Core::World G_World;

void Game::Initialize()
{
	std::cout << "game init\n";

	G_World.SetAmbientColor(Color(0.5f, 0.5f, 0.5f, 0.5f));

	background = new Core::Entity("background", vector2(0, 0), vector2(720, 720));
	background->Load();
	background->SetOrigin(vector2(0, 0));
	background->SetApplyLightType(0);

	ship.Initialize();
	asteroidManager.Initialize();
	//bulletManager.Initialize();
}

void Game::Update()
{
	background->Update();
	background->Draw();

	ship.Update();
	bulletManager.Update();
	asteroidManager.Update();
}