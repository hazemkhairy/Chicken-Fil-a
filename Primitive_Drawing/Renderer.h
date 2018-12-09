#include <gl/glew.h>
#include "shader.hpp"
#include"Ship.h"
#include"NormalChicken.h"
#include"BossChicken.h"
#include "FPCamera.h"
#pragma once

class Renderer
{
    GLuint programID;
	Ship * hazem;
	BossChicken* boss;
	NormalChicken * hazem2,*hazem3,*hazem4;
	FPCamera camera;
	
public:
    Renderer();
    ~Renderer();
    
    void Initialize();
    void Draw();
	void HandleKeyboardInput(int key);
	void Update();
    void Cleanup();
};
