#pragma once
#include "Bullet.h"
class ShipBullet : public Bullet {
public:
	ShipBullet();
	ShipBullet::ShipBullet(GLuint pID, GLfloat x, GLfloat y, GLfloat z);
	~ShipBullet();

	void init();
	void draw();
	void update();
	void cleanup();
};

