#include "Camera.h"

Camera::Camera()
{
}

void Camera::LoadCamera(GLFWwindow* window, GLuint& programHandle)
{
	cameraPos = glm::vec3(1.5f, 0.0f, 1.5f);
	cameraFront = glm::vec3(-0.5f, 0.0f, -0.5f);
	cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	worldUp = cameraUp;

	world = glm::mat4(1.0f);
	view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

	glfwGetWindowSize(window, &width, &height);
	lastX = width / 2.0f;
	lastY = height / 2.0f;
	
	projection = glm::perspective(45.0f, (float)width / (float)height, 0.001f, 1000.0f);
	WVP = projection * view * world;
	wvpLoc = glGetUniformLocation(programHandle, "wvp");
	glUniformMatrix4fv(wvpLoc, 1, GL_FALSE, glm::value_ptr(WVP));

	thisCameraPos = cameraPos;
}

void Camera::UpdateCameraPos()
{
	view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	WVP = projection * view * world;
	glUniformMatrix4fv(wvpLoc, 1, GL_FALSE, glm::value_ptr(WVP));
}

glm::mat4 Camera::GetViewMatrix()
{
	return view;
}

glm::mat4 Camera::GetProjectionMatrix()
{
	return projection;
}

void Camera::CameraProcessInput(int key, float deltaTime)
{
	cameraSpeed = CAMERA_SPEED * deltaTime;
	if (key == GLFW_KEY_W)
		cameraPos += cameraSpeed * cameraFront;
	if (key == GLFW_KEY_S)
		cameraPos -= cameraSpeed * cameraFront;
	if (key == GLFW_KEY_A)
		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	if (key == GLFW_KEY_D)
		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;

	thisCameraPos = cameraPos;
}

Camera::~Camera()
{
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (!TwEventMousePosGLFW(xpos, ypos))
	{
		if (glfwGetInputMode(window, GLFW_CURSOR) == GLFW_CURSOR_DISABLED)
		{
			if (firstMouse)
			{
				lastX = xpos;
				lastY = ypos;
				firstMouse = false;
			}
			GLfloat xoffset = xpos - lastX;
			GLfloat yoffset = lastY - ypos;
			lastX = xpos;
			lastY = ypos;
			GLfloat sensitivity = 0.05f;
			xoffset *= sensitivity;
			yoffset *= sensitivity;
			yaw += xoffset;
			pitch += yoffset;
			if (pitch > 89.0f)
				pitch = 89.0f;
			if (pitch < -89.0f)
				pitch = -89.0f;
			glm::vec3 front;
			front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
			front.y = sin(glm::radians(pitch));
			front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
			cameraFront = glm::normalize(front);
			cameraRight = glm::normalize(glm::cross(cameraFront, worldUp));
			cameraUp = glm::normalize(glm::cross(cameraRight, cameraFront));
		}
	}	
}