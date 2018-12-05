#pragma once
#include "Chicken.h"
class NormalChicken :
	public Chicken
{
public:
	NormalChicken();
	NormalChicken::NormalChicken(GLuint pID, GLfloat x, GLfloat y, GLfloat z);
	~NormalChicken();
	void init();
	void draw();
	void update();
	void shoot();
	void cleanup();
};

