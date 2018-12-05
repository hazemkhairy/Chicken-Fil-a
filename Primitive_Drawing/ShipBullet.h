#pragma once
#include "Bullet.h"
class ShipBullet : public Bullet {
public:
	ShipBullet();
	~ShipBullet();
	void draw();
	void update();
	void cleanup();
};

