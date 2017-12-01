#include "Scene.h"



Scene::Scene()
{
	lastRotateAngle = pRotateAngle = 0.0f;
	lastRotateAxis = pRotateAxis = glm::vec3(1.0f, 0.0f, 0.0f);
	lastScale = pScale = 1.0f;
	lastTranslateVec = glm::vec3(30.0f, 0.0f, 0.0f);
	pTranslateVec = glm::vec3(0.0f, 0.0f, 0.0f);
	world = glm::mat4(1.0f);

	lastModelPicked = modelPicked;

	Model *model = new Model(PATH_CUBE_RED);
	models.push_back(model);

	Model *model2 = new Model(PATH_CUBE_GREEN);
	models.push_back(model2);

	Model *model3 = new Model(PATH_CUBE_BLUE);
	models.push_back(model3);

	model->SetNode(model2);
	model2->SetNode(model3);
}

void Scene::Render(Shader* shader, float deltaTime)
{
	models[0]->Reset();

	if (lastModelPicked != modelPicked)
	{
		lastScale = pScale;
		lastRotateAngle = pRotateAngle;
		lastRotateAxis = pRotateAxis;
		lastTranslateVec = pTranslateVec;
		lastModelPicked = modelPicked;
	}

	models[0]->Scale(lastScale, lastScale, lastScale);
	models[0]->Rotate(lastRotateAngle, lastRotateAxis);
	models[0]->Translate(lastTranslateVec);


	if (modelPicked >= 1)
	{
		models[modelPicked - 1]->Scale(pScale, pScale, pScale);
		models[modelPicked - 1]->Rotate(pRotateAngle, pRotateAxis);
		models[modelPicked - 1]->Translate(pTranslateVec);
	}
	//else
	//{
	//	models[0]->Reset();
	//	models[0]->Scale(pScale, pScale, pScale);
	//	models[0]->Rotate(pRotateAngle, pRotateAxis);
	//	models[0]->Translate(pTranslateVec);
	//}

	models[0]->Render(shader);
	Model::modelsRendered = 0;

	//models[0]->Reset();
	//models[0]->Rotate(world, pRotateAngle, pRotateAxis);
	//models[0]->Translate(world, glm::vec3(30.0f, 0.0f, 0.0f));
	//models[0]->Render(shader);
	//Model::modelsRendered = 0;
}

Scene::~Scene()
{
}
