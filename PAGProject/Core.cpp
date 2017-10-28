#include "Core.h"


Core::Core()
{
	window = new Window(SCREEN_WIDTH, SCREEN_HEIGHT);
	mesh = new Mesh();
	shader = new Shader();
	texture = new Texture();
	camera = new Camera();
}

bool Core::Start()
{
	if (!window->Init())
		return false;

	mesh->LoadBuffers();
	if (!shader->LoadShaders())
		return false;

	if (!texture->LoadAllTextures(shader->programHandle))
		return false;

	camera->LoadCamera(window->GLWindow, shader->programHandle);

	return true;
}

void Core::Update()
{
	while (!glfwWindowShouldClose(window->GLWindow))
	{
		processInput(window->GLWindow);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		shader->ActivateShader();
		mesh->Render(shader->programHandle);
		texture->BindTextures();
		
		glfwPollEvents();
		glfwSwapBuffers(window->GLWindow);
	}
}

Core::~Core()
{
}

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}
