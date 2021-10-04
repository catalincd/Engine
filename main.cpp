#include "src/basic.h"
#include "src/display/window.h"
#include "src/shaders/shader.h"
#include "src/buffers/buffers.h"
#include "src/shaders/ShaderManager.h"
#include "src/renderer/renderer.h"


using namespace Core;

extern Renderer G_Renderer;
Shader* shader;
Sprite* sprite;
Window* window;
GLuint vertex_buffer, vertex_shader, fragment_shader;
GLint mvp_location, vpos_location, vcol_location;



void BasicUpdate()
{
    G_Renderer.SubmitSprite(sprite);

    G_Renderer.Flush();
}



int main(void)
{
    window = new Window("Title", 640, 480);
    G_Renderer.Init(window);
    
    sprite = new Sprite("res/textures/pop cola.jpg", vector2(10, 10), vector2(100, 100), Color(0xFFFFFFFF), 0);

    window->AddFunction(BasicUpdate);

    window->Start();


    return 0;
}