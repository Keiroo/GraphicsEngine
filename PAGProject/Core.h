#pragma once
#include "Headers.h"
#include "Mesh.h"
#include "Shader.h"
#include "Window.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

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

};

void processInput(GLFWwindow *window);


