#include "src/basic.h"
#include "src/display/window.h"
#include "src/shaders/shader.h"
#include "src/shaders/ShaderManager.h"
#include "src/text/FontManager.h"
#include "src/renderer/renderer.h"
#include "src/time/TimeManager.h"
#include "src/utils/utilString.h"
#include "src/text/Font.h"
#include "src/text/Text.h"
#include "src/text/TextRenderer.h"

using namespace Core;

extern ShaderManager G_ShaderManager;
extern FontManager G_FontManager;
extern Renderer G_Renderer;
extern TextRenderer G_TextRenderer;
extern TimeManager G_TimeManager;

Sprite* sprite;
Sprite* sprite2;
Sprite* sprite3;
Window* window;
Text* text;



void BasicUpdate()
{
    sprite->Draw();
    sprite2->Draw();
    //sprite3->Draw();

    sprite2->SetAngle(90 * glfwGetTime());
    
    //std::cout << GetFPSRate() << std::endl;

    

    G_Renderer.Flush();



    text->Draw();
}


int main(void)
{
    window = new Window("Title", 1280, 720);
   
    G_ShaderManager.LoadShaders();
    G_Renderer.Initialize(window);
    G_TextRenderer.Initialize(window);

    ///remove this in the future
    sprite = new Sprite("res/textures/cox.png", vector2(10, 10), vector2(100, 100), Color(0xFF00FFFF), 0);
    sprite2 = new Sprite("res/textures/pop cola.jpg", vector2(320, 240), vector2(300, 300), Color(0xFF00FF00), 45);
    sprite3 = new Sprite("res/textures/cox.png", vector2(320, 240), vector2(300, 300), Color(0xFF00FF00), 0);
    sprite2->SetOrigin(vector2(0.5f));
    
    G_FontManager.Initialize();
    text = new Text("fuck OpenGL", vector2(100,100));

    window->AddFunction(BasicUpdate);
    ///endof remove

   
    window->Start();


    return 0;
}