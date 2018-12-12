#pragma once
#include <gl/glew.h>
#include "shader.hpp"
#include "texture.h"
#include<GL\glfw3.h>
#include<stdio.h>
#include<vector>
#include "GraphicsHelper.h"
// Include GLM
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
using namespace glm;
using namespace std;
class Object
{
protected:

	GLuint vertexArrayID;
	GLuint vertexBufferID;
	GLuint normalsBufferID;
	GLuint mvpMatrixID;
	GLuint mMatrixID;

	GLuint AmbientLightID;
	GLuint LightPositionID;
	GLuint EyePositionID;


	glm::vec3 ambientLight;
	glm::vec3 lightPosition;

	glm::mat4 ProjectionMatrix;
	glm::mat4 ViewMatrix;
	glm::mat4 ModelMatrix;
	glm::mat4 MVP_M;

	GraphicsHelper * graphicsHelper;
	Texture * texture;
	float x, y, z;
	float speed;

	GLuint programID;

public:
	vector <GLfloat> verts;
	vector <GLfloat> normals;
	Object();
	~Object();
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void cleanup() = 0;
};