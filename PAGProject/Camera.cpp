#include "Camera.h"

Camera::Camera()
{
}

void Camera::LoadCamera(GLFWwindow* window, GLuint& programHandle)
{
	world = glm::mat4(1.0f);
	view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

	glfwGetWindowSize(window, &width, &height);
	projection = glm::perspective(45.0f, (float)width / (float)height, 0.001f, 50.0f);
	WVP = projection * view * world;
	wvpLoc = glGetUniformLocation(programHandle, "wvp");
	glUniformMatrix4fv(wvpLoc, 1, GL_FALSE, &WVP[0][0]);
}

void Camera::UpdateCameraPos()
{
	view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	WVP = projection * view * world;
	glUniformMatrix4fv(wvpLoc, 1, GL_FALSE, &WVP[0][0]);
}

void Camera::CameraProcessInput(int key, float deltaTime)
{
	cameraSpeed = 2.0f * deltaTime;
	if (key == GLFW_KEY_W)
		cameraPos += cameraSpeed * cameraFront;
	if (key == GLFW_KEY_S)
		cameraPos -= cameraSpeed * cameraFront;
	if (key == GLFW_KEY_A)
		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	if (key == GLFW_KEY_D)
		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
}


Camera::~Camera()
{
}

