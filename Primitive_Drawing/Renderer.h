#include <gl/glew.h>
#include "shader.hpp"
#include"Ship.h"
#include"NormalChicken.h"
#pragma once

class Renderer
{
    GLuint programID;
	Ship * hazem; NormalChicken * hazem2;
public:
    Renderer();
    ~Renderer();
    
    void Initialize();
    void Draw();
    void Cleanup();
};
