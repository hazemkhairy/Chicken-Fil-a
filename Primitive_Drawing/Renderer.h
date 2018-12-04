#include <gl/glew.h>
#include "shader.hpp"
#pragma once

class Renderer
{
    GLuint programID;
    
public:
    Renderer();
    ~Renderer();
    
    void Initialize();
    void Draw();
    void Cleanup();
};
