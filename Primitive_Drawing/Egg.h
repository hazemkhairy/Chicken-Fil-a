#pragma once
#include "Bullet.h"
class Egg : public Bullet {
public:
	Egg();
	Egg::Egg(GLuint pID, GLfloat x, GLfloat y, GLfloat z);
	~Egg();

	void init();
	void draw();
	void update();
	void cleanup();
};

