#include "GameScene.h"
#include "BulletManager.h"
#include "AsteroidManager.h"
#include "GameUI.h"
#include "../Engine.h"

extern BulletManager bulletManager;
extern AsteroidManager asteroidManager;
extern GameUI gameUI;
extern Ship ship;

extern Core::World G_World;
extern Core::SoundManager G_SoundManager;

GameScene gameScene;

void GameScene::Initialize()
{
	std::cout << "game init\n";

	//World
	G_World.SetAmbientColor(Color(0.5f, 0.5f, 0.5f, 0.5f));
	background = new Core::Entity("background", vector2(0, 0), vector2(720, 720));
	background->Load();
	background->SetOrigin(vector2(0, 0));
	background->SetApplyLightType(0);

	//UI
	gameUI.Initialize();

	//Entities
	ship.Initialize();

	//Managers
	asteroidManager.Initialize();
	bulletManager.Initialize();
}

void GameScene::Update()
{
	background->Update();
	background->Draw();

	ship.Update();
	bulletManager.Update();
	asteroidManager.Update();

	gameUI.Update();
}