#include "Floor.h"



void Floor::init()
{
	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);

	verts.push_back(0.0f);
	verts.push_back(0.0f);
	verts.push_back(0.0f);

	verts.push_back(0.0f);
	verts.push_back(0.0f);
	verts.push_back(0.0f);

	verts.push_back(-1.0f);
	verts.push_back(0.0f);
	verts.push_back(0.0f);

	verts.push_back(1.0f);
	verts.push_back(0.0f);
	verts.push_back(0.0f);

	glGenBuffers(1, &vertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
	ProjectionMatrix = mat4(1.0f);
	ViewMatrix = mat4(1.0f);
	ModelMatrix = glm::translate(0.0f, 0.0f, 0.8f);
	MVP_M = ModelMatrix * ViewMatrix*ProjectionMatrix;
	//mvpMatrixID = glGetUniformLocation(programID, "MVP");

}

void Floor::draw(GLuint mvpUniformMatrixID, glm::mat4 VP)
{
	glBufferData(GL_ARRAY_BUFFER, (this->verts.size()) * sizeof(GLfloat), &verts[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 3, (void*)0);
	//glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 5, (void*)12);
	glUseProgram(programID);
	glUniformMatrix4fv(mvpUniformMatrixID, 1, GL_FALSE, &MVP_M[0][0]);
	//texture->Bind();
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDrawArrays(GL_TRIANGLES, 1, 3);

}

Floor::Floor()
{
	init();
}

void Floor::update()
{
	/*if (flag == 0 && time == 50) {
		MVP_M *= glm::translate(-0.005f, -0.01f, -1.0f);
		//MVP_M *= glm::rotate(45.0f, vec3(0.0f, 1.0f, 0.0f));
		flag = 1;
	}
	else if (flag == 1 && time == 100) {
		MVP_M *= glm::translate(0.005f, 0.01f, 1.0f);
		flag = 0;
		time = 0;
	}
	time++;*/
}

void Floor::cleanup()
{
}


Floor::~Floor()
{
}
