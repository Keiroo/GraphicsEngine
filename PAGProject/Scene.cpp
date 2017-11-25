#include "Scene.h"



Scene::Scene()
{
	transform = new Transform();
	model = new Model(MODEL_FILENAME);
	//testModel = new TestModel();
}

void Scene::Render(Shader* shader)
{
	for (int i = -10; i < 10; i++)
	{
		for (int j = -10; j < 10; j++)
		{
			for (int k = -10; k < 10; k++)
			{
				transform->Reset();
				transform->Translate(glm::vec3((float)(i * 10), (float)(j * 10), (float)(k * 10)));
				model->Render(shader);
			}
		}
	}	
	//testModel->Render(shader);
}

Scene::~Scene()
{
}
