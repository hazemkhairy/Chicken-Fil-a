#pragma once
#include "Chicken.h"
class NormalChicken :
	public Chicken
{
public:
	NormalChicken();
	NormalChicken(GLuint pID);
	~NormalChicken();
	void init();
	void draw();
	void update();
	void shoot();
	void cleanup();
};

