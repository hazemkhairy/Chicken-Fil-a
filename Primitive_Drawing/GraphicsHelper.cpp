#include "GraphicsHelper.h"



GraphicsHelper::GraphicsHelper()
{
}

mat4 GraphicsHelper::getTranslate(float dx , float dy , float dz)
{
	return translate(dx, dy, dz);
}


mat4 GraphicsHelper::getScale(float dx, float dy, float dz)
{
	return scale(dx, dy, dz);
}

mat4 GraphicsHelper::getRotation(int ox , int oy , int oz , float angle)
{
	return rotate(angle, vec3(ox, oy, oz));
}

GraphicsHelper::~GraphicsHelper()
{
}
