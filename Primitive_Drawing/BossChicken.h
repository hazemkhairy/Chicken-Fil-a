#pragma once
#include "Chicken.h"
class BossChicken :
	public Chicken
{
public:
	BossChicken();
	~BossChicken();
	void draw();
	void update();
	void shoot();
	void cleanup();
};

