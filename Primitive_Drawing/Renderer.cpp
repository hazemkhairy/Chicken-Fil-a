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
	// Set the background color
	glClearColor(1.0f, 0.6f, 1.0f, 1.0f);
	camera.GetViewMatrix() = glm::lookAt(
			glm::vec3(2,5,7),
			glm::vec3(0,0,0),
			glm::vec3(0,1,0)
		);
	//glEnable(GL_DEPTH_TEST);
	//glDepthFunc(GL_LESS); 
	// Create and compile our GLSL program from the shaders
	GLuint programID = LoadShaders( "VertexShader.vertexshader", "FragmentShader.fragmentshader" );
	//hazem = new Ship(programID);
	//hazem2 = new NormalChicken(programID, 0.0f, 0.0f, 0.0f);
	//glUseProgram(programID);
	//programID = LoadShaders("VertexShader.vertexshader", "FragmentShader.fragmentshader");
	//hazem3 = new NormalChicken(programID, 0.5f, 0.0f, 0.0f);
	hazem = new Ship(programID, 0, -0.6f, 0);
	glUseProgram(programID);
	//glDeleteProgram(programID);
	//boss = new BossChicken(programID, -0.9f, 0.0f, 0.0f);
	//ehh = new Egg(programID, -0.5f, -0.5f, 0.0f);
	gun = new ShipBullet(programID, -0.2f,-0.7f, 0.0f);
	// Use our shader
	//glUseProgram(programiD);
	//glDeleteProgram(programiD);

}

void Renderer::Draw()
{
		// Clear the screen
		glClear( GL_COLOR_BUFFER_BIT);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnableVertexAttribArray(0);
		//gun->draw();
		glEnable(GL_BLEND);
		glEnableVertexAttribArray(1);

		glUseProgram(programID);
		//hazem->draw();
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		//hazem2->draw();
		//hazem3->draw();
		//hazem4->draw();
		//boss->draw();
		//ehh->draw();
		gun->draw();

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);

}
void Renderer::HandleKeyboardInput(int key)
{
	hazem->HandleKeyboardInput(key);
}
void Renderer::Update() 
{
	hazem2->update();
	hazem3->update();
	//hazem4->update();
}
void Renderer::Cleanup()
{
    glDeleteProgram(programID);
}