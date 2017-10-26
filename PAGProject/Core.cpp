#include "Core.h"


Core::Core()
{
	window = new Window(SCREEN_WIDTH, SCREEN_HEIGHT);
	mesh = new Mesh();
	shader = new Shader();
}

bool Core::Start()
{
	if (!window->Init())
	{
		return false;
	}	
	return true;
}

void Core::Update()
{
	while (!glfwWindowShouldClose(window->GLWindow))
	{
		processInput(window->GLWindow);
		glClear(GL_COLOR_BUFFER_BIT);


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
