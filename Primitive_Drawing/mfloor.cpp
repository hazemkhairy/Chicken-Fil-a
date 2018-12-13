#include "mfloor.h"
#include <iostream>
#include "GraphicsHelper.h"
using namespace std;
using namespace glm;
mfloor::mfloor()
{
}
mfloor::mfloor(GLuint pID)
{
	x = y = z = 0;
	programID = pID;
	init();
}
mfloor::mfloor(GLuint pID, GLfloat xa, GLfloat ya, GLfloat za)
{
	x = xa; y = ya; z = za;
	programID = pID;
	init();
}
void mfloor::init()
{
	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);
	this->texture = new Texture("space.png", 0);
	//left bottom point
	verts.push_back(-1.6f);
	verts.push_back(-1.0f);
	verts.push_back(0.0f);

	//left top point
	verts.push_back(-1.6f);
	verts.push_back(1.0f);
	verts.push_back(-1.0f);
	//right bottom point
	verts.push_back(1.6f);
	verts.push_back(-1.0f);
	verts.push_back(0.0f);
	//right Top point
	verts.push_back(1.6f);
	verts.push_back(1.0f);
	verts.push_back(-1.0f);

	//UV

	verts.push_back(0.0f);
	verts.push_back(0.0f);

	verts.push_back(0.0f);
	verts.push_back(1.0f);

	verts.push_back(1.0f);
	verts.push_back(0.0f);

	verts.push_back(1.0f);
	verts.push_back(1.0f);


	
	glGenBuffers(1, &vertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);

	ModelMatrix = mat4(1.0f);
	//MVP_M = ModelMatrix * ViewMatrix * ProjectionMatrix;

}




void mfloor::draw(GLuint mvpUniformMatrixID, glm::mat4 VP)
{
	MVP_M = ModelMatrix * VP;
	glBufferData(GL_ARRAY_BUFFER, (this->verts.size()) * sizeof(GLfloat), &verts[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 3, (void*)0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 2, (void*)(sizeof(GLfloat) * 12));

	glUniformMatrix4fv(mvpUniformMatrixID, 1, GL_FALSE, &MVP_M[0][0]);
	texture->Bind();
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDrawArrays(GL_TRIANGLES, 1, 3);


}

void mfloor::update()
{
}





void mfloor::cleanup()
{
}

mfloor::~mfloor()
{
}