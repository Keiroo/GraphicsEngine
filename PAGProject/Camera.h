#pragma once
#include "Headers.h"
//#include <glm/gtc/matrix_transform.hpp>

class Camera
{
public:
	Camera();
	void LoadCamera(GLFWwindow * window, GLuint & programHandle);
	void UpdateCameraPos();
	void CameraProcessInput(int key, float deltaTime);
	~Camera();

private:
	float cameraSpeed;
	glm::mat4 world, view, projection, WVP;
	GLint width, height;
	GLuint wvpLoc;

	glm::vec3 cameraPos = glm::vec3(1.5f, 0.0f, 1.5f);
	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
};

