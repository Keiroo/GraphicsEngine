#include "TweakBar.h"



TweakBar::TweakBar(Scene* scene)
{
	this->scene = scene;
	TBRotateAngle = 0.0f;
	TBRotateAxis = 'Y';
	TBTranslateVec = glm::vec3(0.0f, 0.0f, 0.0f);
	TBScalef = 1.0f;

	modelPicked = 1;

	this->direction = this->scene->dirLight.direction;

	CreateBar();
}

void TweakBar::Draw()
{
	this->scene->pRotateAngle = TBRotateAngle;
	this->scene->pTranslateVec = TBTranslateVec;
	this->scene->pScale = TBScalef;
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

	this->scene->dirLight.direction = this->direction;

	TwDraw();
}

void TweakBar::ChangeModelPicked(GLuint modelID)
{
	modelPicked = modelID;
	scene->modelPicked = modelID;
}

TweakBar::~TweakBar()
{
}

void TweakBar::CreateBar()
{
	bar = TwNewBar("Transform");
	//TwDefine("Transform iconified=true");
	TwAddVarRO(bar, "Model Picked", TW_TYPE_INT32, &modelPicked, NULL);

	//Scale
	TwAddVarRW(bar, "ScaleValue", TW_TYPE_FLOAT, &TBScalef, "group=Scale min=1 step=0.1 label='Scale'");

	//Rotate
	TwAddVarRW(bar, "Angle", TW_TYPE_FLOAT, &TBRotateAngle, "group=Rotate min=0 max=360 step=1");
	TwAddSeparator(bar, "Sep1", "group=Rotate");
	TwAddVarRO(bar, "Axis", TW_TYPE_CHAR, &TBRotateAxis, "group=Rotate");
	TwAddButton(bar, "AxisX", TBAxisXButtonCallback, NULL, "group=Rotate label='X'");
	TwAddButton(bar, "AxisY", TBAxisYButtonCallback, NULL, "group=Rotate label='Y'");
	TwAddButton(bar, "AxisZ", TBAxisZButtonCallback, NULL, "group=Rotate label='Z'");

	//Translate
	TwAddVarRW(bar, "TranslateX", TW_TYPE_FLOAT, &TBTranslateVec.x, "group=Translate min=0 step=1 label='X'");
	TwAddVarRW(bar, "TranslateY", TW_TYPE_FLOAT, &TBTranslateVec.y, "group=Translate min=0 step=1 label='Y'");
	TwAddVarRW(bar, "TranslateZ", TW_TYPE_FLOAT, &TBTranslateVec.z, "group=Translate min=0 step=1 label='Z'");

	TwDefine(" Transform iconified=true ");


	bar2 = TwNewBar("DirectionalLight");
	TwAddVarRW(bar2, "Direction", TW_TYPE_DIR3F, &direction, "");
	TwDefine(" DirectionalLight iconified=true ");

	testbar = TwNewBar("Test");
	TwAddVarRW(testbar, "1", TW_TYPE_FLOAT, &scene->TBtest, "step=0.1");
	TwAddVarRW(testbar, "2", TW_TYPE_FLOAT, &scene->TBtest2, "step=0.1");
	TwAddVarRW(testbar, "3", TW_TYPE_FLOAT, &scene->TBtest3, "step=0.1");
	TwAddVarRW(testbar, "Other", TW_TYPE_FLOAT, &scene->TBtest4, "step=0.1");
	TwDefine(" Test iconified=true ");


	grassBar = TwNewBar("Zad6");
	TwAddVarRW(grassBar, "AlphaTest", TW_TYPE_FLOAT, &scene->fAlphaTest, "group=Grass step=0.01");
	TwAddVarRW(grassBar, "AlphaMultiplier", TW_TYPE_FLOAT, &scene->fAlphaMultiplier, "group=Grass step=0.01");

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