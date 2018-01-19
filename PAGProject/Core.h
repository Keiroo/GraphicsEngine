#pragma once
#include "Headers.h"
#include "Shader.h"
#include "Window.h"
#include "Camera.h"
#include "Scene.h"
#include "TweakBar.h"
#include "ColorPick.h"
#include "Postprocess.h"

class Core
{
public:	
	Core();
	bool Start();
	void Update();
	~Core();


private:
	Shader* shader;	
	Window* window;
	Camera* camera;
	Scene* scene;
	TweakBar* tweakBar;
	ColorPick* colorPick;
	Postprocess *postprocess;

	float oldTime = 0.0f, newTime = 0.0f, deltaTime = 0.0f;	
};

void processInput(GLFWwindow *window, Camera* camera, ColorPick* colorPick, float deltaTime);
void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods);



