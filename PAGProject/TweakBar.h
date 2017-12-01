#pragma once
#include"Headers.h"
#include "Scene.h"

class TweakBar
{
public:
	GLuint modelPicked;

	TweakBar(Scene* scene);
	void Draw();
	void ChangeModelPicked(GLuint modelID);
	~TweakBar();

private:
	TwBar* bar;
	Scene* scene;
	void CreateBar();	
};

static float TBRotateAngle;
static char TBRotateAxis;
static glm::vec3 TBTranslateVec;
static float TBScalef;

void TW_CALL TBAxisXButtonCallback(void *clientData);
void TW_CALL TBAxisYButtonCallback(void *clientData);
void TW_CALL TBAxisZButtonCallback(void *clientData);

