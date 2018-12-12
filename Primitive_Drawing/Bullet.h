#pragma once
#include "Object.h"
class Bullet : public Object {

public:
	Bullet();
	void draw(GLuint mvpUniformMatrixID, glm::mat4 VP) ;
	void update();
	void cleanup();
	~Bullet();
};

