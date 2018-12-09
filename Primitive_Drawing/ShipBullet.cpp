#include "ShipBullet.h"



ShipBullet::ShipBullet()
{
}
ShipBullet::ShipBullet(GLuint pID, GLfloat xa, GLfloat ya, GLfloat za)
{
	x = xa, y = ya, z = za;
	programID = pID;
	
	init();
}

ShipBullet::~ShipBullet()
{
}
void ShipBullet::init()
{

	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);
	//this->texture = new Texture("white-egg.png", 0);

	// Set the background color to blue
	glClearColor(0.0f, 0.0f, 0.4f, 1.0f);

	verts.push_back(x);//0
	verts.push_back(y);
	verts.push_back(z);

	verts.push_back(x + 0.01f);//1
	verts.push_back(y+0.01f);
	verts.push_back(z);

	verts.push_back(x-0.02f);//2
	verts.push_back(y + 0.02f);
	verts.push_back(z);

	verts.push_back(x + 0.01f);//3
	verts.push_back(y + 0.03f);
	verts.push_back(z);

	verts.push_back(x -0.02f);//4
	verts.push_back(y + 0.04f);
	verts.push_back(z);

	verts.push_back(x + 0.01f);//5
	verts.push_back(y + 0.05f);
	verts.push_back(z);


	verts.push_back(x-0.02f);//6
	verts.push_back(y + 0.06f);
	verts.push_back(z);

	verts.push_back(x);//7
	verts.push_back(y + 0.07f);
	verts.push_back(z);


	glGenBuffers(1, &vertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);

	ProjectionMatrix = mat4(1.0f);
	ViewMatrix = mat4(1.0f);
	ModelMatrix = glm::translate(0.5f, 0.0f, 0.0f);
	MVP_M = ModelMatrix * ViewMatrix*ProjectionMatrix;
	mvpMatrixID = glGetUniformLocation(programID, "MVP");
}

void ShipBullet::draw()
{
	glBufferData(GL_ARRAY_BUFFER, verts.size() * sizeof(GLfloat), &verts[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 3, (void*)0);
	//glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (char*)(3 * sizeof(float)));
	//texture->Bind();
	glLineWidth(3);
	glDrawArrays(GL_LINE_STRIP, 0, 8);
	//glDrawArrays(GL_TRIANGLES, 1, 3);
	glUniformMatrix4fv(mvpMatrixID, 1, GL_FALSE, &MVP_M[0][0]);
}

void ShipBullet::update()
{
}

void ShipBullet::cleanup()
{

}
