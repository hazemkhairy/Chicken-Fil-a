#pragma once
#include "Character.h"

class Ship : public Character {
public:
	void init();
	Ship();
	Ship(GLuint);
	Ship(GLuint, GLfloat, GLfloat, GLfloat);
	GLfloat distanceBetweenPoints;
	Texture *texture1;
	Texture *texture2;
	Texture *texture3;
	void draw();
	void update();
	void shoot();
	void HandleKeyboardInput(int);
	void cleanup();
	~Ship();
};

