#include "Scene.h"



Scene::Scene()
{
	model = new Model(MODEL_FILENAME);
	//testModel = new TestModel();
}

void Scene::Render(Shader* shader)
{
	model->Render(shader);
	//testModel->Render(shader);
}

Scene::~Scene()
{
}
