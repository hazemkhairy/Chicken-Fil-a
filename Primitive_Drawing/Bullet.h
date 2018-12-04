#pragma once
#include "Object.h"
class Bullet : public Object {

public:
	Bullet();
	void draw() ;
	void update();
	void cleanup();
	~Bullet();
};

