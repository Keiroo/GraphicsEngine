#include "Core.h"


Core::Core()
{
	window = new Window(SCREEN_WIDTH, SCREEN_HEIGHT);
	//mesh = new Mesh();
	//shader = new Shader();
	camera = new Camera();
}

bool Core::Start()
{
	if (!window->Init())
		return false;

	//mesh->LoadBuffers();
	//if (!shader->LoadShaders())
	//	return false;

	//if (!mesh->LoadTextures(shader->programHandle))
	//	return false;
	scene = new Scene();
	camera->LoadCamera(window->GLWindow, scene->programHandle);
	glfwSetCursorPosCallback(window->GLWindow, mouse_callback);
	
	
	return true;
}

void Core::Update()
{
	while (!glfwWindowShouldClose(window->GLWindow))
	{
		oldTime = newTime;
		newTime = (float)glfwGetTime();
		deltaTime = newTime - oldTime;

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		processInput(window->GLWindow, camera, deltaTime);	
		camera->UpdateCameraPos();
		//shader->ActivateShader();
		//mesh->Render(shader->programHandle, deltaTime);
		scene->Draw(deltaTime);

		glfwPollEvents();
		glfwSwapBuffers(window->GLWindow);
	}
}

Core::~Core()
{
}

void processInput(GLFWwindow *window, Camera* camera, float deltaTime)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera->CameraProcessInput(GLFW_KEY_W, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera->CameraProcessInput(GLFW_KEY_S, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera->CameraProcessInput(GLFW_KEY_A, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera->CameraProcessInput(GLFW_KEY_D, deltaTime);
}
