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
	//hazem = new Ship(programID);
	GLuint programID = LoadShaders( "VertexShader.vertexshader", "FragmentShader.fragmentshader" );
	//hazem2 = new NormalChicken(programID, 0.0f, 0.0f, 0.0f);
	//glUseProgram(programID);
	//programID = LoadShaders("VertexShader.vertexshader", "FragmentShader.fragmentshader");
	//hazem3 = new NormalChicken(programID, 0.5f, 0.0f, 0.0f);
	hazem = new Ship(programID, 0, -0.6f, 0);
	glUseProgram(programID);
	//glDeleteProgram(programID);
	//boss = new BossChicken(programID, -0.9f, 0.0f, 0.0f);
	//ehh = new Egg(programID, -0.5f, -0.5f, 0.0f);
	//glUseProgram(programID);
	//GLuint programiD = LoadShaders("VertexShader - Copy.vertexshader", "FragmentShader - Copy.fragmentshader");
	//gun = new ShipBullet(programiD, 0.5f, -0.5f, 0.0f);
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
		hazem->draw();
		//hazem2->draw();
		//hazem->draw();
		//hazem4->draw();
		//boss->draw();
		//hazem3->draw();
		//ehh->draw();

		glDisable(GL_BLEND);
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);

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