#pragma once
#include "Headers.h"
#include "Mesh.h"
#include "Shader.h"
#include "Window.h"
#include "Texture.h"

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

};

void processInput(GLFWwindow *window);


