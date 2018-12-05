#pragma once
#include <gl/glew.h>
#include "shader.hpp"
#include "texture.h"
#include<GL\glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
using namespace glm;
class GraphicsHelper
{
public:
	GraphicsHelper();
	mat4 getTranslate(float, float, float);
	mat4 getScale(float, float, float);
	mat4 getRotation(int , int , int ,float);
	~GraphicsHelper();
};

