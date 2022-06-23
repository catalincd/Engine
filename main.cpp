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


void DefaultUpdate()
{
    G_Input.Update();
    G_Input.SetCursorID(0);
    G_Renderer.Update();//Not totally necessary
	GAME.Update();
    G_SpriteRenderer.Flush();
}


int main(void)
{
    G_Window.Initialize("Space Shooter", 480, 720);
    G_ShaderManager.LoadShaders();
    G_SpriteRenderer.Initialize();
    G_Renderer.Initialize();
    G_TextRenderer.Initialize();
    G_Input.Initialize();
    G_FontManager.Initialize();

    GAME.Initialize();

    G_Window.AddFunction(DefaultUpdate);
    G_Window.Start();


    return 0;
}