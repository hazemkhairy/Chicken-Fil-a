#include "Egg.h"
#include "texture.h"
#include "stb_image.h"
#include <iostream>

using namespace std;
using namespace glm;

Egg::Egg()
{
}


Egg::~Egg()
{
}
Egg::Egg(GLuint pID, GLfloat xa, GLfloat ya, GLfloat za)
{
	x = xa, y = ya, z = za;
	programID = pID;
	
	init();
}

void Egg::init()
{

	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);
	this->texture = new Texture("white-egg.png", 0);
	/*verts.push_back(x);//0
	verts.push_back(y);//1
	verts.push_back(z);//2*/

	// Set the background color to blue
	glClearColor(0.0f, 0.0f, 0.4f, 1.0f);
	/*float x = 50;
	x = -0.50f;

	for (int i = 3; i < 303; i += 3)
	{
	verts.push_back(x);
	verts.push_back(sqrt(0.5f*0.5f - x * x));
	verts.push_back(-3);

	//verts[i] = x;
	//verts[i + 1] = sqrt(0.5f*0.5f - x * x);
	//verts[i + 2] = 0;
	x += 0.010f;
	}
	x = 0.50f;
	for (int i = 303; i < 603; i += 3)
	{
	verts.push_back(x);
	verts.push_back(-sqrt(0.5f*0.5f - x * x));
	verts.push_back(-3);
	x -= 0.010f;
	}*/
	verts.push_back(x);//0
	verts.push_back(y);
	verts.push_back(z);

	verts.push_back(1.0f);
	verts.push_back(1.0f); 

	verts.push_back(x + 0.1);//1
	verts.push_back(y);
	verts.push_back(z);

	verts.push_back(0.0f);
	verts.push_back(1.0f);

	verts.push_back(x);//2
	verts.push_back(y + 0.2);
	verts.push_back(z);

	verts.push_back(1.0f);
	verts.push_back(0.0f);

	verts.push_back(x + 0.1);//3
	verts.push_back(y + 0.2);
	verts.push_back(z);

	verts.push_back(0.0f);
	verts.push_back(0.0f);


	glGenBuffers(1, &vertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);


	ProjectionMatrix = mat4(1.0f);
	ViewMatrix = mat4(1.0f);
	ModelMatrix = glm::translate(0.5f, 0.0f, 0.0f);
	MVP_M = ModelMatrix * ViewMatrix*ProjectionMatrix;
	mvpMatrixID = glGetUniformLocation(programID, "MVP");
}

void Egg::draw()
{
	glBufferData(GL_ARRAY_BUFFER, verts.size() * sizeof(GLfloat), &verts[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 5, (void*)0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (char*)(3 * sizeof(float)));
	texture->Bind();
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDrawArrays(GL_TRIANGLES, 1, 3);
	glUniformMatrix4fv(mvpMatrixID, 1, GL_FALSE, &MVP_M[0][0]);
	//glDrawArrays(GL_TRIANGLE_FAN, 0, 200);
}

void Egg::update()
{
}


void Egg::cleanup()
{

}