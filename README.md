# C++ OpenGL Engine using GLFW3 and GLAD

## Used Libraries
- GLFW3
- GLAD
- stb_image

## Features
- Custom Shader Support
- Dynamic Lighting
- Entity Rendering with Diffuse Maps and Normal Maps
- Batched Rendering
- Sprite Rendering
- Text Rendering with BMFont Support
- Sound Management
- Input Management
- Time Management
- Event Management
- Window Management

## Base Classes
- World
-- Entity
-- Light

- UI
-- Sprite
-- Button
-- Text

- Singletons
-- G_Window
-- G_Renderer
-- G_SpriteRenderer
-- G_TextRenderer
-- G_FontManager
-- G_Input
-- G_SoundManager

## Basic Usage
The Game class has an Initialize() and Update() function which is where execution begins. 

```c++
class Game
{
    Core::Sprite* sampleSprite;
public:
    void Initialize()
    {
        sampleSprite = new Sprite("sprite.png", vector2(100, 100), vector2(32,32), Color(0xFFFFFFFF), 0);
        sampleSprite->Load();
    }

    void Update()
    {
        sampleSprite->Draw();
    }
};
```
