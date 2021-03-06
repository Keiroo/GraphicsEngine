#pragma once
#include"Headers.h"
#include "Scene.h"
#include "Postprocess.h"

class TweakBar
{
public:
	GLuint modelPicked;
	glm::vec3 direction;

	TweakBar(Scene* scene, Postprocess *postprocess);
	void Draw();
	void ChangeModelPicked(GLuint modelID);
	~TweakBar();

private:
	TwBar *bar, *bar2, *testbar, *grassBar;
	Scene* scene;
	Postprocess *postprocess;

	void CreateBar();	
};

static float TBRotateAngle;
static char TBRotateAxis;
static glm::vec3 TBTranslateVec;
static float TBScalef;

void TW_CALL TBAxisXButtonCallback(void *clientData);
void TW_CALL TBAxisYButtonCallback(void *clientData);
void TW_CALL TBAxisZButtonCallback(void *clientData);

