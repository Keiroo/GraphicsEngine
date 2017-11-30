#pragma once
#include "Headers.h"

class ColorPick
{
public:
	GLuint FBO, RBO, texture, modelPicked;
	ColorPick();
	void PickModel(GLFWwindow* window);
	~ColorPick();

private:
	double x, y;
};

