#include "src/basic.h"
#include "src/display/window.h"
#include "src/shaders/shader.h"
#include "src/shaders/ShaderManager.h"
#include "src/renderer/renderer.h"


using namespace Core;

extern Renderer G_Renderer;
Shader* shader;
Sprite* sprite;
Sprite* sprite2;
Sprite* sprite3;
Window* window;
GLuint vertex_buffer, vertex_shader, fragment_shader;
GLint mvp_location, vpos_location, vcol_location;



void BasicUpdate()
{
    sprite->Draw();
    sprite2->Draw();
    sprite3->Draw();

    G_Renderer.Flush();
}



int main(void)
{
    window = new Window("Title", 1280, 720);
    
    
    sprite = new Sprite("res/textures/cox.png", vector2(10, 10), vector2(100, 100), Color(0xFF00FFFF), 0);
    sprite2 = new Sprite("res/textures/pop cola.jpg", vector2(10, 150), vector2(100, 100), Color(0xFFFFFFFF), 0);
    sprite3 = new Sprite("res/textures/pop cola.jpg", vector2(150, 150), vector2(200, 200), Color(0xFFFFFFFF), 0);

    G_Renderer.Init(window);

    window->AddFunction(BasicUpdate);

    window->Start();


    return 0;
}