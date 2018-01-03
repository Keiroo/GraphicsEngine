#pragma once
#include "Headers.h"
#include "Shader.h"

class Camera
{
public:

	Camera();
	void LoadCamera(GLFWwindow * window, Shader * shader);
	void UpdateCameraPos(Shader * shader);
	void CameraProcessInput(int key, float deltaTime);
	glm::vec3 getPos();
	glm::vec3 getFront();
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