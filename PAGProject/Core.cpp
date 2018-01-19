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
	glfwSetMouseButtonCallback(window->GLWindow, mouseButtonCallback);

	scene = new Scene();

	postprocess = new Postprocess();
	postprocess->GenerateFramebuffer(shader);

	tweakBar = new TweakBar(scene, postprocess);
	colorPick = new ColorPick();

	// set default trans for shader to work
	GLuint transformLoc;
	glm::mat4 trans = glm::mat4(1.0f);
	transformLoc = glGetUniformLocation(shader->programHandle, "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));

	// Postprocessing
	
	
	return true;
}

void Core::Update()
{
	while (!glfwWindowShouldClose(window->GLWindow))
	{
		oldTime = newTime;
		newTime = (float)glfwGetTime();
		deltaTime = newTime - oldTime;

		processInput(window->GLWindow, camera, colorPick, deltaTime);		

		// Draw CP scene to texture
		if (glfwGetInputMode(window->GLWindow, GLFW_CURSOR) == GLFW_CURSOR_DISABLED)
		{
			if (glfwGetMouseButton(window->GLWindow, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
			{
				glBindFramebuffer(GL_FRAMEBUFFER, colorPick->FBO);
				glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				shader->ActivateCPShader();
				camera->UpdateCameraPos();
				scene->Render(shader, camera, deltaTime);
				glFlush();
				glFinish();
				colorPick->PickModel(window->GLWindow);
				glBindFramebuffer(GL_FRAMEBUFFER, 0);
			}
		}		

		// Draw full scene
		postprocess->BindFramebuffer();
		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		shader->ActivateShader();
		camera->UpdateCameraPos();
		scene->Render(shader, camera, deltaTime);
		glBindFramebuffer(GL_FRAMEBUFFER, 0);

		postprocess->RenderToQuad(shader);


		// TweakBar
		tweakBar->ChangeModelPicked(colorPick->modelPicked);
		tweakBar->Draw();

		glfwSwapBuffers(window->GLWindow);
		glfwPollEvents();		
	}
}

Core::~Core()
{
}

void processInput(GLFWwindow *window, Camera* camera, ColorPick* colorPick, float deltaTime)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_TAB) == GLFW_PRESS)
	{
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);		
	}		

	if (glfwGetKey(window, GLFW_KEY_GRAVE_ACCENT) == GLFW_PRESS)
	{
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}

	if (glfwGetInputMode(window, GLFW_CURSOR) == GLFW_CURSOR_DISABLED)
	{
		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
			camera->CameraProcessInput(GLFW_KEY_W, deltaTime);
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
			camera->CameraProcessInput(GLFW_KEY_S, deltaTime);
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
			camera->CameraProcessInput(GLFW_KEY_A, deltaTime);
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
			camera->CameraProcessInput(GLFW_KEY_D, deltaTime);
	}
}

void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods)
{
	if (!TwEventMouseButtonGLFW(button, action))
	{
	}
}
