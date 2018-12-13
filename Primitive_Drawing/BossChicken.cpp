#include "BossChicken.h"


using namespace std;
using namespace glm;
BossChicken::BossChicken()
{
}

BossChicken::BossChicken(GLuint pId, GLfloat x, GLfloat y, GLfloat z)
{
	this->x = x, this->y = y, this->z = z;
	this->programID = pId;
	health = 1;
	//cout << "gy b " << pID << " w fya " << programID << endl;
	init();
}
void BossChicken::init()
{
	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);
	/*GLfloat verts[] = {
	0.0f,+1.0f,0.0f,
	-1.0f,-1.0f,0.0f,
	+1.0f,-1.0f,0.0f,
	};*/
	// texture
	this->texture = new Texture("Bosschicken2.png", 0);
	//p1
	verts.push_back(x);
	verts.push_back(y);
	verts.push_back(z);
	// uv 1
	verts.push_back(0.0f);
	verts.push_back(1.0f);
	// p2
	verts.push_back(x + 0.9f);
	verts.push_back(y);
	verts.push_back(z);
	//uv 2
	verts.push_back(1.0f);
	verts.push_back(1.0f);
	//p3
	verts.push_back(x);
	verts.push_back(y + 0.9f);
	verts.push_back(z);
	// UV 3
	verts.push_back(0.0f);
	verts.push_back(0.0f);
	//p4
	verts.push_back(x + 0.9f);
	verts.push_back(y + 0.9f);
	verts.push_back(z);
	// UV 3
	verts.push_back(1.0f);
	verts.push_back(0.0f);
	//Shader ourShader("VertexShader.vertexshader", "FragmentShader.fragmentshader");
	glGenBuffers(1, &vertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
	ProjectionMatrix = mat4(1.0f);
	ViewMatrix = mat4(1.0f);
	ModelMatrix = glm::translate(0.0f, 0.0f, 0.0f);
	//ourShader.use();
	//mvpMatrixID = glGetUniformLocation(this->programID, "MVP");

}


void BossChicken::draw(GLuint mvpUniformMatrixID, glm::mat4 VP)
{
	glBufferData(GL_ARRAY_BUFFER, (this->verts.size()) * sizeof(GLfloat), &verts[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 5, (void*)0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 5, (void*)12);
	MVP_M = ModelMatrix * VP ;

	glUniformMatrix4fv(mvpUniformMatrixID, 1, GL_FALSE, &MVP_M[0][0]);
	texture->Bind();
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDrawArrays(GL_TRIANGLES, 1, 3);
}

void BossChicken::update()
{
}

void BossChicken::shoot()
{
}

void BossChicken::cleanup()
{

}
BossChicken::~BossChicken()
{
}