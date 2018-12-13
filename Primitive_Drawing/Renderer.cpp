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
	// Set the background color to nearly black
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	// Create and compile our GLSL program from the shaders
	GLuint programID = LoadShaders( "VertexShader.vertexshader", "FragmentShader.fragmentshader" );
	//Shader ourShader("VertexShader.vertexshader", "FragmentShader.fragmentshader");
	ship = new Ship(programID, 0.0f, -0.6f ,0.0f);
	normalChicken = new NormalChicken(programID, 0.0f, 0.0f, 0.0f);
	boss = new BossChicken(programID, -0.0f, 0.0f, 0.0f);
	egg = new Egg(programID, -0.5f, -0.5f, 0.0f);
	floor = new mfloor(programID, 0.0f, 0.0f, 0.0f);
	camera = new FPCamera();
	//gun = new ShipBullet(programID, 0.5, 0.5, 0.0);
	glUseProgram(programID);
	mvpMatrixID = glGetUniformLocation(programID, "MVP");
}

void Renderer::Draw()
{
	glm::mat4 VP = camera->GetProjectionMatrix() * camera->GetViewMatrix();
		// Clear the screen
	   //glEnable(GL_DEPTH_TEST);
	   //glDepthFunc(GL_LESS); 
		glClear( GL_COLOR_BUFFER_BIT);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
			// START DRAW
		//gun->draw();
		//ship->draw(mvpMatrixID, VP);
		floor->draw(mvpMatrixID, VP);
		normalChicken->draw(mvpMatrixID, VP);
		//boss->draw(mvpMatrixID, VP);
		//egg->draw(mvpMatrixID, VP);	
		//gun->draw(mvpMatrixID, VP);
			// END DRAW
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);

}
void Renderer::HandleKeyboardInput(int key)
{
	ship->HandleKeyboardInput(key);
	switch (key)
	{
		//Moving forward
	case GLFW_KEY_W:
		camera->Walk(0.01);
		break;

		//Moving backword
	case GLFW_KEY_S:
		camera->Walk(-0.01);
		break;

		// Moving right
	case GLFW_KEY_D:
		camera->Strafe(0.01);
		break;

		// Moving left
	case GLFW_KEY_A:
		camera->Strafe(-0.01);
		break;

		// Moving up
	case GLFW_KEY_R:
		camera->Fly(0.01);
		break;

		// Moving down
	case GLFW_KEY_F:
		camera->Fly(-0.01);
		break;
	default:
		break;
	}
	//continue the remaining movements.
	camera->UpdateViewMatrix();
}
void Renderer::Update()
{
	normalChicken->update();
}
void Renderer::Cleanup()
{
	glDeleteProgram(programID);
}