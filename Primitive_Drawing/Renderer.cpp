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
	camera.GetViewMatrix() = glm::lookAt(
		glm::vec3(2, 5, 7),
		glm::vec3(0, 0, 0),
		glm::vec3(0, 1, 0)
	);
	// Use our shader
	/*// Projection matrix : 
	camera->SetPerspectiveProjection(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
	// View matrix : 
	camera->Reset(0.0, 1.0, 5.0,
		0, 0, 0,
		0, 1, 0);*/
	glClearColor(0.8f, 0.8f, 1.0f, 1.0f);
	// Create and compile our GLSL program from the shaders
	GLuint programID = LoadShaders( "VertexShader.vertexshader", "FragmentShader.fragmentshader" );
	//Shader ourShader("VertexShader.vertexshader", "FragmentShader.fragmentshader");
	ship = new Ship(programID, 0.0f, -0.6f ,0.0f);
	normalChicken = new NormalChicken(programID, 0.0f, 0.0f, 0.0f);
	boss = new BossChicken(programID, -0.9f, 0.0f, 0.0f);
	egg = new Egg(programID, -0.5f, -0.5f, 0.0f);
	floor = new Floor();
	camera = new FPCamera();
	//gun = new ShipBullet(programID, 0.5, 0.5, 0.0);
	//glUseProgram(programID);
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
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnableVertexAttribArray(0);
		//glDisable(GL_BLEND);
		//gun->draw();
		glEnableVertexAttribArray(1);
		glEnable(GL_BLEND);
		//ship->draw();
		normalChicken->draw(mvpMatrixID, VP);
		floor->draw(mvpMatrixID, VP);
		//boss->draw();
		//egg->draw();	
		//gun->draw();
		floor->draw(mvpMatrixID, VP);
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);

}
void Renderer::HandleKeyboardInput(int key)
{
	ship->HandleKeyboardInput(key);
	switch (key)
	{
		//Moving forward
	case GLFW_KEY_UP:
	case GLFW_KEY_W:
		camera->Walk(0.01);
		break;

		//Moving backword
	case GLFW_KEY_DOWN:
	case GLFW_KEY_S:
		camera->Walk(-0.01);
		break;

		// Moving right
	case GLFW_KEY_RIGHT:
	case GLFW_KEY_D:
		camera->Strafe(0.01);
		break;

		// Moving left
	case GLFW_KEY_LEFT:
	case GLFW_KEY_A:
		camera->Strafe(-0.01);
		break;

		// Moving up
	case GLFW_KEY_SPACE:
	case GLFW_KEY_R:
		camera->Fly(0.01);
		break;

		// Moving down
	case GLFW_KEY_LEFT_CONTROL:
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
	//normalChicken->update();
}
void Renderer::Cleanup()
{
	glDeleteProgram(programID);
}