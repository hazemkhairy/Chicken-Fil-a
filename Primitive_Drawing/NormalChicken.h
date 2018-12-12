#pragma once
#include "Chicken.h"
class NormalChicken :
	public Chicken
{
	bool flag = 0;
	int time = 0;
public:
	NormalChicken();
	NormalChicken::NormalChicken(GLuint pID, GLfloat x, GLfloat y, GLfloat z);
	~NormalChicken();
	void init();
	void draw(GLuint mvpUniformMatrixID, glm::mat4 VP);
	void update();
	void shoot();
	void cleanup();
};

