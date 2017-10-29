#pragma once
#include "Headers.h"
#include "Mesh.h"
#include "Shader.h"
#include "Window.h"
#include "Texture.h"
#include "Camera.h"

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

class Core
{
public:
	Core();
	bool Start();
	void Update();
	~Core();


private:
	Mesh* mesh;
	Shader* shader;	
	Window* window;
	Texture* texture;
	Camera* camera;
	float oldTime = 0.0f, newTime = 0.0f, deltaTime = 0.0f;


};

void processInput(GLFWwindow *window, Camera* camera, float deltaTime);


