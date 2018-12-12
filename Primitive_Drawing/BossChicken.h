#pragma once
#include "Chicken.h"
#include "Shader.h"
class BossChicken :
	public Chicken
{
public:
	BossChicken();
	BossChicken::BossChicken(GLuint pId, GLfloat x, GLfloat y, GLfloat z);
	~BossChicken();
	void init();
	void draw(GLuint mvpUniformMatrixID, glm::mat4 VP);
	void update();
	void shoot();
	void cleanup();
};

