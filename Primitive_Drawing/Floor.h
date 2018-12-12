#pragma once
#include "Object.h"
class Floor : public Object
{
public:
	void init();
	void draw(GLuint mvpUniformMatrixID, glm::mat4 VP);
	Floor();
	void update();
	void cleanup();
	~Floor();
};

