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

};

void processInput(GLFWwindow *window);


