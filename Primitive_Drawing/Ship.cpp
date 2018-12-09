#include "Ship.h"
#include <iostream>
using namespace std;
using namespace glm;
Ship::Ship(GLuint pID)
{
	x = y = z = 0;
	health = 1;
	programID = pID;
	init();
}

void Ship::init()
{
	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);
	/*GLfloat verts[] = {
		0.0f,+1.0f,0.0f,
		-1.0f,-1.0f,0.0f,
		+1.0f,-1.0f,0.0f,
	};*/
	//point 1
	verts.push_back(0.0f);
	verts.push_back(+1.0f);
	verts.push_back(0.0f);
	
	// p2
	verts.push_back(-1.0f);
	verts.push_back(-1.0f);
	verts.push_back(0.0f);
	
	//P3
	verts.push_back(+1.0f);
	verts.push_back(-1.0f);
	verts.push_back(0.0f);
	

	glGenBuffers(1, &vertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);

	ProjectionMatrix = mat4(1.0f);
	ViewMatrix = mat4(1.0f);
	ModelMatrix = mat4(1.0f);
	MVP_M = ModelMatrix * ViewMatrix * ProjectionMatrix;
	mvpMatrixID = glGetUniformLocation(programID, "MVP");
}

Ship::Ship()
{
}

Ship::Ship(GLuint i , float j , float k , float h)
{
	x = i, y = j , z=k;
	health = h;
	
}

Ship::~Ship()
{
}

void Ship::draw()
{
	glBufferData(GL_ARRAY_BUFFER, (this->verts.size() ) * sizeof(GLfloat), &verts[0], GL_STATIC_DRAW);
	cout << &MVP_M << endl;
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 3, (void*) 0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 2, (void*) (sizeof(GLfloat)*15) );

	glUniformMatrix4fv(mvpMatrixID, 1, GL_FALSE, &MVP_M[0][0]);

	glDrawArrays(GL_TRIANGLES, 0, 3);

}

void Ship::update()
{
}

void Ship::shoot()
{
}

void Ship::HandleKeyboardInput(int)
{
}

void Ship::cleanup()
{
}
	