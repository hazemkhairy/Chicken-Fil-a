#include "Renderer.h"
#include <iostream>
using namespace std;
Renderer::Renderer()
{
    
}

Renderer::~Renderer()
{
    Cleanup();
}

void Renderer::Initialize()
{
	// Set the background color to white
	glClearColor(1.0f, 0.9f, 1.0f, 1.0f);
	// Create and compile our GLSL program from the shaders
	GLuint programID = LoadShaders( "VertexShader.vertexshader", "FragmentShader.fragmentshader" );
	cout << "i am in renderer "<< programID<<endl;
	hazem = new Ship(programID);
	hazem2 = new NormalChicken(programID);
	// Use our shader
	glUseProgram(programID);
}

void Renderer::Draw()
{
		// Clear the screen
		glClear( GL_COLOR_BUFFER_BIT );
		glEnableVertexAttribArray(0);
		glUseProgram(programID);
		hazem->draw();
		hazem2->draw();
		glDisableVertexAttribArray(0);
}

void Renderer::Cleanup()
{
    glDeleteProgram(programID);
}