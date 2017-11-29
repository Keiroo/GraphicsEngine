#pragma once
#include "Headers.h"
#include "Shader.h"
#include "Window.h"
#include "Camera.h"
#include "Scene.h"
#include "TweakBar.h"

class Core
{
public:
	Core();
	bool Start();
	void Update();
	~Core();


private:
	Shader* shader;	
	Window* window;
	Camera* camera;
	Scene* scene;
	TweakBar* tweakBar;

	float oldTime = 0.0f, newTime = 0.0f, deltaTime = 0.0f;	
};

void processInput(GLFWwindow *window, Camera* camera, float deltaTime);



