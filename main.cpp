#include "src/basic.h"
#include "src/display/window.h"
#include "src/shaders/shader.h"
#include "src/buffers/buffers.h"
#include "src/shaders/ShaderManager.h"
#include "src/renderer/renderer.h"


using namespace Core;

extern Renderer G_Renderer;
Shader* shader;
Window* window;
GLuint vertex_buffer, vertex_shader, fragment_shader;
GLint mvp_location, vpos_location, vcol_location;



void BasicUpdate()
{
    /*
    int width, height;
    glfwGetFramebufferSize(window->Get(), &width, &height);
    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(shaderManager.GetShaderID("default"));
    shaderManager.SetOrtographicMatrix("default", 0.0f, 640.0f, 480.0f, 0.0f, 1.0f, -1.0f);

   
    

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0);
    */
}



int main(void)
{
    window = new Window("Title", 640, 480);
    G_Renderer.Init(window);
    

    GLfloat vertices[] =
    {
        0,0,
        0,200,
        200,0,
        0,200,
        200,0,
        200,200
    };

    GLushort indices[] =
    {
        0, 1, 2,
        3, 4, 5
    };

    VertexArray *vao = new VertexArray();
    VertexBuffer* vbo = new VertexBuffer(vertices, 2 * 6, 2);
    vbo->bind();
    IndexBuffer ibo(indices, 2 * 3);
    vao->AddBuffer(vbo, 0);
    vao->bind();
    ibo.bind();

    
    window->AddFunction(BasicUpdate);
    window->Start();

    ibo.unbind();
    vao->unbind();
       


    return 0;
}