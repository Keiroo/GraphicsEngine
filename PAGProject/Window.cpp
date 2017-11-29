#include "Window.h"


Window::Window(int width, int height)
{
	this->width = width;
	this->height = height;
}

bool Window::Init()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLWindow = glfwCreateWindow(width, height, "PAG Project", nullptr, nullptr);
	if (GLWindow == nullptr)
	{
		fprintf(stderr, "Failed to create GLFW window\n");
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(GLWindow);
	glfwSetFramebufferSizeCallback(GLWindow, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		fprintf(stderr, "Failed to initialize GLAD\n");
		return false;
	}

	TwInit(TW_OPENGL_CORE, NULL);
	TwWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);

	glViewport(0, 0, width, height);
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glfwSetInputMode(GLWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	return true;
}

Window::~Window()
{
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
	TwWindowSize(width, height);
}