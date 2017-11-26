#include "Scene.h"



Scene::Scene()
{
	//transform = new Transform();
	world = glm::mat4(1.0f);

	Model *model = new Model(MODEL_FILENAME);
	models.push_back(model);

	Model *model2 = new Model(*model);
	models.push_back(model2);

	//Model *model3 = new Model(*model);
	//models.push_back(model3);

	model->SetNode(model2);
	//model2->SetNode(model3);
}

void Scene::Render(Shader* shader)
{
	models[0]->Reset();
	models[0]->Translate(world, glm::vec3(10.0f, 0.0f, 0.0f));
	models[0]->Render(shader);
}

Scene::~Scene()
{
}
