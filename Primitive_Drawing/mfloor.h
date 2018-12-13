#pragma once
#include "Object.h"
class mfloor :
	public Object
{
public:
	mfloor(GLuint pID, GLfloat xa, GLfloat ya, GLfloat za);
	mfloor();
	mfloor(GLuint pID);
	~mfloor();
	void init();
	void draw(GLuint mvpUniformMatrixID, glm::mat4 VP);
	void update();
	void cleanup();
};

