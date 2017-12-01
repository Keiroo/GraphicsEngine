#include "Scene.h"



Scene::Scene()
{
	pRotateAngle = 0.0f;
	pRotateAxis = glm::vec3(1.0f, 0.0f, 0.0f);
	world = glm::mat4(1.0f);

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
	if (modelPicked == NULL)
	{
		models[0]->Reset();
		models[0]->Rotate(world, pRotateAngle, pRotateAxis);
		models[0]->Translate(world, glm::vec3(30.0f, 0.0f, 0.0f));
		models[0]->Render(shader);
		Model::modelsRendered = 0;
	}
	else
	{
		models[0]->Reset();
		models[0]->Rotate(world, pRotateAngle, pRotateAxis);
		models[0]->Translate(world, glm::vec3(30.0f, 0.0f, 0.0f));
		models[0]->Render(shader);
		Model::modelsRendered = 0;
	}

	//models[0]->Reset();
	//models[0]->Rotate(world, pRotateAngle, pRotateAxis);
	//models[0]->Translate(world, glm::vec3(30.0f, 0.0f, 0.0f));
	//models[0]->Render(shader);
	//Model::modelsRendered = 0;
}

Scene::~Scene()
{
}
