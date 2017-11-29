#include "Core.h"


Core::Core()
{
	window = new Window(SCREEN_WIDTH, SCREEN_HEIGHT);
	shader = new Shader();
	camera = new Camera();
}

bool Core::Start()
{
	if (!window->Init())
		return false;

	if (!shader->LoadShaders())
		return false;
	shader->ActivateShader();

	camera->LoadCamera(window->GLWindow, shader->programHandle);
	glfwSetCursorPosCallback(window->GLWindow, mouse_callback);

	scene = new Scene();
	tweakBar = new TweakBar();

	// set default trans for shader to work
	GLuint transformLoc;
	glm::mat4 trans = glm::mat4(1.0f);
	transformLoc = glGetUniformLocation(shader->programHandle, "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
	
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
		shader->ActivateShader();
		scene->Render(shader, deltaTime);
		tweakBar->Draw();

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
