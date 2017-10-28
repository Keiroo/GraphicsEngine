#include "Camera.h"

Camera::Camera()
{
}

void Camera::LoadCamera(GLFWwindow* window, GLuint& programHandle)
{
	world = glm::mat4(1.0f);
	view = glm::lookAt(	glm::vec3(1.5f, 0.0f, 1.5f),  
						glm::vec3(0.0f, 0.0f, 0.0f),  
						glm::vec3(0.0f, 1.0f, 0.0f)); 

	glfwGetWindowSize(window, &width, &height);
	projection = glm::perspective(45.0f, (float)width / (float)height, 0.001f, 50.0f);
	WVP = projection * view * world;
	wvpLoc = glGetUniformLocation(programHandle, "wvp");
	glUniformMatrix4fv(wvpLoc, 1, GL_FALSE, &WVP[0][0]);
}


Camera::~Camera()
{
}
