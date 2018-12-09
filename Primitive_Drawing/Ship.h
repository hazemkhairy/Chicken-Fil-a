#pragma once
#include "Character.h"
class Ship : public Character {
public:
	void init();
	Ship();
	Ship(GLuint);
	Ship(GLuint, float, float, float);
	void draw();
	void update();
	void shoot();
	void HandleKeyboardInput(int);
	void cleanup();
	~Ship();
};

