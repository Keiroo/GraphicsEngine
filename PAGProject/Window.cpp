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

	glViewport(0, 0, width, height);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

	return true;
}

Window::~Window()
{
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}