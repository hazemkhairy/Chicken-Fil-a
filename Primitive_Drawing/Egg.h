#pragma once
#include "Bullet.h"
class Egg : public Bullet {
public:
	Egg();
	Egg::Egg(GLuint pID, GLfloat x, GLfloat y, GLfloat z);
	~Egg();

	void init();
	void draw(GLuint mvpUniformMatrixID, glm::mat4 VP);
	void update();
	void cleanup();
};

