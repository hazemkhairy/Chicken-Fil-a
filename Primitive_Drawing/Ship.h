#pragma once
#include "Character.h"
class Ship : public Character {
public:
	Ship();
	~Ship();
	void draw();
	void update();
	void shoot();
	void HandleKeyboardInput(int);
};

