


#include "game/Game.h"

using namespace Core;

extern Window G_Window;
extern ShaderManager G_ShaderManager;
extern FontManager G_FontManager;
extern SpriteRenderer G_SpriteRenderer;
extern Renderer G_Renderer;
extern TextRenderer G_TextRenderer;
extern TimeManager G_TimeManager;
extern InputManager G_Input;
extern Gui G_Gui;
extern Game GAME;

Sprite* sprite;
Sprite* sprite2;
Button* sprite3;
Entity** entities;
Text** text;

int frames = 0;
int avgFps = 0;

int x = 0;

int NUM = 1;
int eNUM = 100;

void BasicUpdate()
{
    G_Input.Update();
    G_Input.SetCursorID(0);

    if (G_Input.GetLeftMouse() == KS_PRESS)
        std::cout << "MOUSE PRESS " << (x++) << std::endl;

    

    sprite2->SetAngle(90 * glfwGetTime());
    
    

    int fps = GetFPSRate();

    
    avgFps = int(float(avgFps * frames + fps) / float(frames + 1));
    frames++;

 
   
    G_Renderer.Update();
    
   
    for (int i = 0; i < NUM; i++)
    {
        text[i]->SetText("FPS: " + std::to_string(GetFPSRate()));
		text[i]->Draw();
    }

	GAME.Update();
}


int main(void)
{
    G_Window.Initialize("Space Shooter", 480, 720);
    G_ShaderManager.LoadShaders();

    G_SpriteRenderer.Initialize();
    G_Renderer.Initialize();
    G_TextRenderer.Initialize();
    G_Input.Initialize();

    
    entities = new Entity * [eNUM];

    for (int i = 0; i < eNUM; i++)
    {
        entities[i] = new Entity("barril", vector2((i / 4) * 200, (i % 4) * 200), vector2(200, 200));
        entities[i]->Load();
        entities[i]->SetApplyLightType(0);
    }
    

    ///remove this in the future
    sprite = new Sprite("res/textures/pop.jpg", vector2(10, 50), vector2(100, 100), Color(0xFF00FFFF), 0);
    sprite2 = new Sprite("res/textures/hull/h1.png", vector2(320, 240), vector2(300, 300), Color(0xFF00FFFF), 45);
    sprite3 = new Button("res/textures/pop.jpg", vector2(320, 240), vector2(300, 300), Color(0xFFFFFFFF), 0);

    sprite->Load();
    sprite2->Load();
    sprite3->Load();

    sprite2->SetOrigin(vector2(0.5f));
    sprite3->SetAngle(45);
    
    G_FontManager.Initialize();
    text = new Text*[NUM];

    for (int i = 0; i < NUM; i++)
    {
        text[i] = new Text("Dummy Text", vector2((i / 30) * 200, (i % 30) * 50));
        text[i]->SetScale(0.25);
        text[i]->SetOrigin(vector2(0.0f));
    }
   

    G_Window.AddFunction(BasicUpdate);
	GAME.Initialize();


   
    G_Window.Start();


    return 0;
}