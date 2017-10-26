#pragma once
#include "Headers.h"
#include <cstdio>

class Window
{
public:
	GLFWwindow* GLWindow;

	Window(int width, int height);
	bool Init();
	~Window();

private:
	int width, height;
};

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

