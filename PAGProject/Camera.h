#pragma once
#include "Headers.h"

class Camera
{
public:
	glm::vec3 thisCameraPos;

	Camera();
	void LoadCamera(GLFWwindow * window, GLuint & programHandle);
	void UpdateCameraPos();
	glm::mat4 GetViewMatrix();
	glm::mat4 GetProjectionMatrix();
	glm::mat4 GetWVPMatrix();
	glm::mat4 GetWorldMatrix();
	void CameraProcessInput(int key, float deltaTime);
	//void CameraMouseCallback(GLFWwindow * window, double xpos, double ypos);
	~Camera();

private:
	float cameraSpeed;
	glm::mat4 world, view, projection, WVP;
	GLint width, height;
	GLuint wvpLoc;

};

static glm::vec3 cameraPos, cameraFront, cameraUp, cameraRight, worldUp;
static bool firstMouse = true;
static GLfloat	yaw = -90.0f,
				pitch = 0.0f,
				lastX = SCREEN_WIDTH / 2.0f,
				lastY = SCREEN_HEIGHT / 2.0f,
				fov = 45.0f;

void mouse_callback(GLFWwindow* window, double xpos, double ypos);