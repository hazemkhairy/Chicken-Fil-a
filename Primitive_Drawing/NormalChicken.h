#pragma once
#include "Chicken.h"
class NormalChicken :
	public Chicken
{
public:
	NormalChicken();
	~NormalChicken();
	void draw();
	void update();
	void shoot();
};

