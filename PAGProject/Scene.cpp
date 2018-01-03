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

	/*Model *model2 = new Model(PATH_CUBE_GREEN);
	models.push_back(model2);

	Model *model3 = new Model(PATH_CUBE_BLUE);
	models.push_back(model3);

	model->SetNode(model2);
	model2->SetNode(model3);*/

	Model *model2 = new Model(*model);
	Model *model3 = new Model(*model);	
}

void Scene::Render(Shader* shader, Camera *camera, float deltaTime)
{
	models[0]->Reset();

	// Lights
	Transform *lightTrans;
	SetLights(shader, camera);






	/*if (lastModelPicked != modelPicked)
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

	models[0]->Render(shader);
	Model::modelsRendered = 0;*/


}

void Scene::SetLights(Shader* shader, Camera *camera)
{
	// Material
	material = new Material(32.0f);
	material->SetShininess(shader);

	// Directional light
	dirLight = new DirectionalLight(glm::vec3(-0.2f, -1.0f, -0.3f));
	dirLight->SetValues(glm::vec3(0.05f, 0.05f, 0.05f),
						glm::vec3(0.4f, 0.4f, 0.4f),
						glm::vec3(0.5f, 0.5f, 0.5f));
	dirLight->SetAll(shader);

	// Point light
	pointLight = new PointLight(glm::vec3(0.7f, 0.2f, 2.0f),
								1.0f,
								0.09f,
								0.032f);
	pointLight->SetValues(	glm::vec3(0.05f, 0.05f, 0.05f),
							glm::vec3(0.8f, 0.8f, 0.8f),
							glm::vec3(1.0f, 1.0f, 1.0f));
	pointLight->SetAll(shader);

	// Spot light
	spotLight = new SpotLight(	camera->getPos(),
								camera->getFront(),
								1.0f,
								0.09f,
								0.032f,
								glm::cos(glm::radians(12.5f)),
								glm::cos(glm::radians(15.0f)));
	spotLight->SetValues(	glm::vec3(0.0f, 0.0f, 0.0f),
							glm::vec3(1.0f, 1.0f, 1.0f),
							glm::vec3(1.0f, 1.0f, 1.0f));
	spotLight->SetAll(shader);
}

Scene::~Scene()
{
}
