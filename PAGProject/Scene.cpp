#include "Scene.h"



Scene::Scene()
{
	model = new Model(MODEL_FILENAME);
}

void Scene::Render(Shader* shader)
{
	model->Render(shader);
}

Scene::~Scene()
{
}
