#pragma once
#include "Headers.h"
#include "Window.h"
#include "Camera.h"
#include "Scene.h"

class Core
{
public:
	Core();
	bool Start();
	void Update();
	~Core();


private:
	//Mesh* mesh;
	//Shader* shader;	
	Window* window;
	Camera* camera;
	//Transform* transform;
	Scene* scene;
	float oldTime = 0.0f, newTime = 0.0f, deltaTime = 0.0f;	
};

void processInput(GLFWwindow *window, Camera* camera, float deltaTime);



