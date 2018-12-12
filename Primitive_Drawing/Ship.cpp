#include "Ship.h"
#include <iostream>
#include "GraphicsHelper.h"
using namespace std;
using namespace glm;
Ship::Ship()
{
}
Ship::Ship(GLuint pID)
{
	distanceBetweenPoints = 0.1;
	x = y = z = 0;
	health = 1;
	programID = pID;
	init();
}
Ship::Ship(GLuint pID , GLfloat xa , GLfloat ya, GLfloat za )
{
	distanceBetweenPoints = 0.1;
	x = xa; y = ya; z = za;
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

	//this->texture1 = new Texture("\\textures\\Ship\\Left Wing.png", 0);
	this->texture1 = new Texture("full space ship.png", 0);

	this->texture2 = new Texture("body.png", 1);
	
	this->texture3 = new Texture("Right Wing.png", 2);

	//Left Wing
	//left bottom point
	verts.push_back(x - (distanceBetweenPoints * 3));
	verts.push_back(y);
	verts.push_back(z);

	//left top point
	verts.push_back(x - (distanceBetweenPoints*3));
	verts.push_back(y + (distanceBetweenPoints * 2));
	verts.push_back(z);
	//right Top point
	verts.push_back(x - (distanceBetweenPoints));
	verts.push_back(y + (distanceBetweenPoints * 2));
	verts.push_back(z);

	//right bottom point
	verts.push_back(x - (distanceBetweenPoints));
	verts.push_back(y);
	verts.push_back(z);
	//left bottom point
	verts.push_back(x - (distanceBetweenPoints * 3));
	verts.push_back(y);
	verts.push_back(z);

	/*//body
	//left bottom point
	verts.push_back(x - (distanceBetweenPoints*1.0));
	verts.push_back(y);
	verts.push_back(z-0.1);

	//left top point
	verts.push_back(x - (distanceBetweenPoints*1.0));
	verts.push_back(y + (distanceBetweenPoints * 5));
	verts.push_back(z - 0.1);
	//right Top point
	verts.push_back(x + (distanceBetweenPoints*1.0));
	verts.push_back(y + (distanceBetweenPoints * 5));
	verts.push_back(z - 0.1);

	//right bottom point
	verts.push_back(x + (distanceBetweenPoints * 1.0));
	verts.push_back(y);
	verts.push_back(z - 0.1);
	//left bottom point
	verts.push_back(x - (distanceBetweenPoints*1.0));
	verts.push_back(y);
	verts.push_back(z - 0.1);
	

	//Right Wing
	//left bottom point
	verts.push_back(x + (distanceBetweenPoints*0.74));
	verts.push_back(y);
	verts.push_back(z);

	//left top point
	verts.push_back(x + (distanceBetweenPoints*0.74));
	verts.push_back(y + (distanceBetweenPoints * 2));
	verts.push_back(z);
	//right Top point
	verts.push_back(x + (distanceBetweenPoints * 3));
	verts.push_back(y + (distanceBetweenPoints * 2));
	verts.push_back(z);

	//right bottom point
	verts.push_back(x + (distanceBetweenPoints * 3));
	verts.push_back(y);
	verts.push_back(z);
	//left bottom point
	verts.push_back(x + (distanceBetweenPoints*0.74));
	verts.push_back(y);
	verts.push_back(z);
	*/
	verts.push_back(0.0f);
	verts.push_back(1.0f);

	verts.push_back(0.0f);
	verts.push_back(0.0f);

	verts.push_back(1.0f);
	verts.push_back(0.0f);

	verts.push_back(1.0f);
	verts.push_back(1.0f);

	verts.push_back(0.0f);
	verts.push_back(1.0f);


	/*verts.push_back(0.0f);
	verts.push_back(1.0f);

	verts.push_back(0.0f);
	verts.push_back(0.0f);

	verts.push_back(1.0f);
	verts.push_back(0.0f);

	verts.push_back(1.0f);
	verts.push_back(1.0f);

	verts.push_back(0.0f);
	verts.push_back(1.0f);

	verts.push_back(0.0f);
	verts.push_back(1.0f);

	verts.push_back(0.0f);
	verts.push_back(0.0f);

	verts.push_back(1.0f);
	verts.push_back(0.0f);

	verts.push_back(1.0f);
	verts.push_back(1.0f);

	verts.push_back(0.0f);
	verts.push_back(1.0f);
	*/
	glGenBuffers(1, &vertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);

	ProjectionMatrix = mat4(1.0f);
	ViewMatrix = mat4(1.0f);
	ModelMatrix = mat4(1.0f);
	MVP_M = ModelMatrix * ViewMatrix * ProjectionMatrix;
	//mvpMatrixID = glGetUniformLocation(programID, "MVP");
}




void Ship::draw(GLuint mvpUniformMatrixID, glm::mat4 VP)
{
	MVP_M = ModelMatrix * ViewMatrix * ProjectionMatrix;
	glBufferData(GL_ARRAY_BUFFER, (this->verts.size() ) * sizeof(GLfloat), &verts[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 0, (void*) 0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 0, (void*)(sizeof(GLfloat) * 15));

	glUniformMatrix4fv(mvpUniformMatrixID, 1, GL_FALSE, &MVP_M[0][0]);

	texture1->Bind();
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDrawArrays(GL_TRIANGLES, 2, 3);

	//texture2->Bind();

	glDrawArrays(GL_TRIANGLES, 5, 3);
	glDrawArrays(GL_TRIANGLES, 7, 3);

	//texture3->Bind();

	glDrawArrays(GL_TRIANGLES, 10, 3);
	glDrawArrays(GL_TRIANGLES, 12, 3);
	
}

void Ship::update()
{
}

void Ship::shoot()
{
}

void Ship::HandleKeyboardInput(int key )
{
	GLfloat stepSize = 0.003;
	switch (key)
	{
	case GLFW_KEY_UP:
		if ((y+(distanceBetweenPoints*2)) < 1.0f)
		{
			y += stepSize;
		ModelMatrix = glm::translate(0.0f, stepSize, 0.0f)*ModelMatrix;
		}
		break;
	case GLFW_KEY_DOWN:
		if (y > -1.0f)
		{
			y -= stepSize;
			ModelMatrix = glm::translate(0.0f, -stepSize, 0.0f)*ModelMatrix;
		}
		break;
	case GLFW_KEY_RIGHT:
		if (x - (distanceBetweenPoints * 1) < 1.0f)
		{
			x+= stepSize;
			ModelMatrix = glm::translate(stepSize,0.0f, 0.0f)*ModelMatrix;
		}
		break;
	case GLFW_KEY_LEFT:
		if ((x - (distanceBetweenPoints * 3)) > -1.0f)
		{
			x -= stepSize;
			ModelMatrix = glm::translate(-stepSize, 0.0f, 0.0f)*ModelMatrix;
		}
		break;
	default:
		break;
	}
}

void Ship::cleanup()
{
}
	
Ship::~Ship()
{
}