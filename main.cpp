#include "src/basic.h"
#include "src/display/window.h"
#include "src/shaders/shader.h"
#include "src/shaders/ShaderManager.h"
#include "src/text/FontManager.h"
#include "src/Renderer/SpriteRenderer.h"
#include "src/Renderer/Renderer.h"
#include "src/time/TimeManager.h"
#include "src/utils/utilString.h"
#include "src/text/Font.h"
#include "src/text/Text.h"
#include "src/text/TextRenderer.h"
#include "src/Input/Input.h"
#include "src/GlobalController/GlobalController.h"
#include "src/UI/Button.h"

using namespace Core;

extern Window G_Window;
extern ShaderManager G_ShaderManager;
extern FontManager G_FontManager;
extern SpriteRenderer G_SpriteRenderer;
extern Renderer G_Renderer;
extern TextRenderer G_TextRenderer;
extern TimeManager G_TimeManager;
extern InputManager G_Input;

Sprite* sprite;
Sprite* sprite2;
Button* sprite3;
Entity** entities;
Text** text;

int frames = 0;
int avgFps = 0;

int x = 0;

int NUM = 100;
int eNUM = 500;

void BasicUpdate()
{
    G_Input.Update();
    G_Input.SetCursorID(0);

    if (G_Input.GetLeftMouse() == KS_PRESS)
        std::cout << "MOUSE PRESS " << (x++) << std::endl;

    sprite->Draw();
    sprite2->Draw();   
    sprite3->Draw();

    sprite2->SetAngle(90 * glfwGetTime());
    
    

    int fps = GetFPSRate();

    
    avgFps = int(float(avgFps * frames + fps) / float(frames + 1));
    frames++;

    
    
    
    if (sprite3->Pressed())
    {
        std::cout << "SPRITE 3 PRESSED! \n";
        sprite3->SetColor(0xFFFFFF77);
    }
    else sprite3->SetColor(0xFFFFFFFF);
   
    G_Renderer.Update();
    G_SpriteRenderer.Flush();

   
   


    for (int i = 0; i < eNUM; i++)
    {
        entities[i]->Update();
        entities[i]->Draw();
    }
    
    for (int i = 1; i < NUM; i++)
    {
        text[i]->SetText("FPS: " + std::to_string(avgFps));
        text[i]->Draw();
    }
}


int main(void)
{
    G_Window.Initialize("Title", 1280, 720);
    G_ShaderManager.LoadShaders();

    G_SpriteRenderer.Initialize();
    G_Renderer.Initialize();
    G_TextRenderer.Initialize();
    G_Input.Initialize();

    
    entities = new Entity * [eNUM];

    for (int i = 0; i < eNUM; i++)
    {
        entities[i] = new Entity("ian.png", vector2((i / 15) * 100, (i % 15) * 100), vector2(100, 100));
        entities[i]->Load();
    }
    

    ///remove this in the future
    sprite = new Sprite("res/textures/pop.jpg", vector2(10, 10), vector2(100, 100), Color(0xFF00FFFF), 0);
    sprite2 = new Sprite("res/textures/hull/h1.png", vector2(320, 240), vector2(300, 300), Color(0xFF00FFFF), 45);
    sprite3 = new Button("res/textures/pop.jpg", vector2(320, 240), vector2(300, 300), Color(0xFFFFFFFF), 0);

    sprite->Load();
    sprite2->Load();
    sprite3->Load();

    sprite2->SetOrigin(vector2(0.5f));
    sprite3->SetAngle(45);
    
    G_FontManager.Initialize();
    text = new Text*[NUM];

    for (int i = 1; i < NUM; i++)
    {
        text[i] = new Text("Dummy Text", vector2((i / 30) * 200, (i % 30) * 50));
        text[i]->SetScale(0.25);
        text[i]->SetOrigin(vector2(0.0f));
    }
   

    G_Window.AddFunction(BasicUpdate);
    ///endof remove

   
    G_Window.Start();


    return 0;
}