#include <gl/glew.h>
#include "shader.hpp"
#include"Ship.h"
#include"NormalChicken.h"
#pragma once

class Renderer
{
    GLuint programID;
	Ship * hazem;
	NormalChicken * hazem2,*hazem3,*hazem4;
public:
    Renderer();
    ~Renderer();
    
    void Initialize();
    void Draw();
    void Cleanup();
};
