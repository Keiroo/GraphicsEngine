#pragma once
#include "Headers.h"
//#include <glm/gtc/matrix_transform.hpp>

class Camera
{
public:
	Camera();
	void LoadCamera(GLFWwindow * window, GLuint & programHandle);
	~Camera();

private:
	glm::mat4 world, view, projection, WVP;
	GLint width, height;
	GLuint wvpLoc;
};

