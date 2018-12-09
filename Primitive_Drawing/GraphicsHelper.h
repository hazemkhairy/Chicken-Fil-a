#pragma once
#include <gl/glew.h>
#include "shader.hpp"
#include "texture.h"
#include<GL\glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
using namespace glm;
static class GraphicsHelper
{
public:
	GraphicsHelper();
	static mat4 getTranslate(float, float, float);
	static mat4 getScale(float, float, float);
	static mat4 getRotation(int , int , int ,float);
	~GraphicsHelper();
};

