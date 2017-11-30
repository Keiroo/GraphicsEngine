#include "TweakBar.h"



TweakBar::TweakBar(Scene* scene)
{
	this->scene = scene;
	TBRotateAngle = 0.0f;
	TBRotateStep = 1.0f;
	TBRotateAxis = 'Y';
	CreateBar();
}

void TweakBar::Draw()
{
	this->scene->pRotateAngle = TBRotateAngle;
	switch (TBRotateAxis)
	{
	case 'X':
		this->scene->pRotateAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		break;
	case 'Y':
		this->scene->pRotateAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		break;
	case 'Z':
		this->scene->pRotateAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		break;
	default:
		this->scene->pRotateAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		break;
	}

	TwDraw();
}

void TweakBar::ChangeModelPicked(GLuint modelID)
{
	modelPicked = modelID;
}

TweakBar::~TweakBar()
{
}

void TweakBar::CreateBar()
{
	bar = TwNewBar("Transform");
	TwDefine("Transform iconified=true");
	TwAddVarRO(bar, "Model Picked", TW_TYPE_INT32, &modelPicked, NULL);
	TwAddVarRO(bar, "Angle", TW_TYPE_FLOAT, &scene->pRotateAngle, "group=Rotate");
	TwAddButton(bar, "Increase", IncreaseButtonCallback, NULL, "group=Rotate");
	TwAddButton(bar, "Decrease", DecreaseButtonCallback, NULL, "group=Rotate");
	TwAddSeparator(bar, "Sep1", "group=Rotate");
	TwAddVarRO(bar, "Angle", TW_TYPE_CHAR, &TBRotateAxis, "group=Rotate");
	TwAddButton(bar, "Axis X", TBAxisXButtonCallback, NULL, "group=Rotate");
	TwAddButton(bar, "Axis Y", TBAxisYButtonCallback, NULL, "group=Rotate");
	TwAddButton(bar, "Axis Z", TBAxisZButtonCallback, NULL, "group=Rotate");



}

void TW_CALL TBAxisXButtonCallback(void *clientData)
{
	TBRotateAngle = 0.0f;
	TBRotateAxis = 'X';
}
void TW_CALL TBAxisYButtonCallback(void *clientData)
{
	TBRotateAngle = 0.0f;
	TBRotateAxis = 'Y';
}
void TW_CALL TBAxisZButtonCallback(void *clientData)
{
	TBRotateAngle = 0.0f;
	TBRotateAxis = 'Z';
}

void TW_CALL IncreaseButtonCallback(void *clientData)
{
	if (TBRotateAngle >= 360.0f - TBRotateStep)
		TBRotateAngle = 0.0f;

	TBRotateAngle += TBRotateStep;
}

void TW_CALL DecreaseButtonCallback(void *clientData)
{
	if (TBRotateAngle <= 0.0f + TBRotateStep)
		TBRotateAngle = 360.0f;

	TBRotateAngle -= TBRotateStep;
}
