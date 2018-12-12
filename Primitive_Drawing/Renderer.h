#include <gl/glew.h>
#include "shader.hpp"
#include"Ship.h"
#include"NormalChicken.h"
#include"BossChicken.h"
#include "FPCamera.h"
#include "Egg.h"
#include "ShipBullet.h"
#include "Shader.h"
#include "Floor.h"
#pragma once

class Renderer
{
    GLuint programID;
	GLuint mvpMatrixID;
	Ship * ship;
	BossChicken* boss;
	NormalChicken * normalChicken;
	Egg * egg;
	ShipBullet* gun;
	Floor* floor;
	FPCamera* camera;
	
public:
    Renderer();
    ~Renderer();
    
    void Initialize();
    void Draw();
	void HandleKeyboardInput(int key);
	void Update();
    void Cleanup();
};
