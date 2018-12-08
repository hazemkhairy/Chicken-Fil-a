#include <gl/glew.h>
#include "shader.hpp"
#include"Ship.h"
#include"NormalChicken.h"
#include"BossChicken.h"
#include "FPCamera.h"
#include "Egg.h"
#include "ShipBullet.h"
#pragma once

class Renderer
{
    GLuint programID;
	Ship * hazem;
	BossChicken* boss;
	NormalChicken * hazem2,*hazem3,*hazem4;
	Egg * ehh;
	ShipBullet*gun;
	FPCamera camera;
	
public:
    Renderer();
    ~Renderer();
    
    void Initialize();
    void Draw();
	void Update();
    void Cleanup();
};
