#include "NormalChicken.h"
#include <iostream>

using namespace std;
using namespace glm;
NormalChicken::NormalChicken()
{
}
NormalChicken::NormalChicken(GLuint pID, GLfloat xa, GLfloat ya, GLfloat za)
{
	x = xa, y = ya,z = za;
	health = 1;
	programID = pID;
	//cout << "gy b " << pID << " w fya " << programID << endl;
	init();
}

NormalChicken::~NormalChicken()
{
}

void NormalChicken::init()
{
	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);
	/*GLfloat verts[] = {
	0.0f,+1.0f,0.0f,
	-1.0f,-1.0f,0.0f,
	+1.0f,-1.0f,0.0f,
	};*/
	GLfloat nx, ny;
	/*//Point 1
	verts.push_back(x);
	verts.push_back(y);
	verts.push_back(0.0f);
	//Point 2
	nx = x - 0.1f;
	ny = y - 0.1f;
	verts.push_back(nx);
	verts.push_back(ny);
	verts.push_back(z);
	// point 3
	nx = x + 0.1f;
	ny = y + 0.1f;
	verts.push_back(nx);
	verts.push_back(ny);
	verts.push_back(0.0f);*/
	// texture
	this->texture = new Texture("chicken.png", 0);
	
	//p1
	verts.push_back(x);
	verts.push_back(y);
	verts.push_back(z);
	// uv 1
	verts.push_back(0.0f);
	verts.push_back(1.0f);
	// p2
	verts.push_back(x + 0.3f);
	verts.push_back(y);
	verts.push_back(0.0f);
	//uv 2
	verts.push_back(1.0f);
	verts.push_back(1.0f);
	//p3
	verts.push_back(x);
	verts.push_back(y + 0.3f);
	verts.push_back(0.0f);
	// UV 3
	verts.push_back(0.0f);
	verts.push_back(0.0f);
	//p4
	verts.push_back(x + 0.3f);
	verts.push_back(y + 0.3f);
	verts.push_back(0.0f);
	// UV 3
	verts.push_back(1.0f);
	verts.push_back(0.0f);
	glGenBuffers(1, &vertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
	ProjectionMatrix = mat4(1.0f);
	ViewMatrix = mat4(1.0f);
	ModelMatrix = glm::translate(0.0f, 0.0f, 0.0f);
	MVP_M = ModelMatrix * ViewMatrix*ProjectionMatrix;
	mvpMatrixID = glGetUniformLocation(this->programID, "MVP");

}
void NormalChicken::draw()
{
	glBufferData(GL_ARRAY_BUFFER, ( this->verts.size()) * sizeof(vec3), &verts[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 5, (void*)0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 5, (void*)12);

	glUniformMatrix4fv(mvpMatrixID, 1, GL_FALSE, &MVP_M[0][0]);
	texture->Bind();
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDrawArrays(GL_TRIANGLES, 1, 3);

}
void NormalChicken::update()
{
}

void NormalChicken::shoot()
{
}

void NormalChicken::cleanup()
{
}
