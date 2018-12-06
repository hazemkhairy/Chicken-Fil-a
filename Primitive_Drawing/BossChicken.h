#pragma once
#include "Chicken.h"
class BossChicken :
	public Chicken
{
public:
	BossChicken();
	BossChicken::BossChicken(GLuint pID, GLfloat x, GLfloat y, GLfloat z);
	~BossChicken();
	void init();
	void draw();
	void update();
	void shoot();
	void cleanup();
};

