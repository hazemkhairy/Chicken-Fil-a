#include "NormalChicken.h"


using namespace glm;
NormalChicken::NormalChicken()
{
}
NormalChicken::NormalChicken(GLuint pID)
{
	x = y = z = 0;
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
	verts.push_back(0.0f);
	verts.push_back(+1.0f);
	verts.push_back(0.0f);
	verts.push_back(-1.0f);
	verts.push_back(-1.0f);
	verts.push_back(0.0f);
	verts.push_back(+1.0f);
	verts.push_back(-1.0f);
	verts.push_back(0.0f);
	glGenBuffers(1, &vertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);

	glBufferData(GL_ARRAY_BUFFER, verts.size() * sizeof(verts), &verts[0], GL_STATIC_DRAW);
	ProjectionMatrix = mat4(1.0f);
	ViewMatrix = mat4(1.0f);
	ModelMatrix = glm::translate(0.5f, 0.0f, 0.0f);
	MVP_M = ModelMatrix * ViewMatrix*ProjectionMatrix;
	mvpMatrixID = glGetUniformLocation(programID, "MVP");
}
void NormalChicken::draw()
{
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 0, (void*)0);
	glUniformMatrix4fv(mvpMatrixID, 1, GL_FALSE, &MVP_M[0][0]);

	glDrawArrays(GL_TRIANGLES, 0, 3);

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
