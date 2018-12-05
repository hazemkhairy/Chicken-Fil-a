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
	//glEnable(GL_DEPTH_TEST);
	//glDepthFunc(GL_LESS); 
	// Create and compile our GLSL program from the shaders
	GLuint programID = LoadShaders( "VertexShader.vertexshader", "FragmentShader.fragmentshader" );
	//hazem = new Ship(programID);
	hazem2 = new NormalChicken(programID, 0.0f, 0.0f, 0.0f);
	hazem3 = new NormalChicken(programID, 0.5f, 0.0f, 0.0f);
	hazem4 = new NormalChicken(programID, -0.5f, 0.0f, 0.0f);
	// Use our shader
	glUseProgram(programID);
}

void Renderer::Draw()
{
	//cout << "the ship : ";
	//for (int i = 0; i < hazem->verts.size(); i++)
	//	cout << hazem->verts[i] << ' ';
	//cout << "\nthe chicken : ";
	//for (int i = 0; i < hazem2->verts.size(); i++)
		//cout << hazem2->verts[i] << ' ';
		// Clear the screen
		glClear( GL_COLOR_BUFFER_BIT);
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);

		glUseProgram(programID);
		//hazem->draw();
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		hazem2->draw();
		hazem3->draw();
		hazem4->draw();
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);

}

void Renderer::Cleanup()
{
    glDeleteProgram(programID);
}