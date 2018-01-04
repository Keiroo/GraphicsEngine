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

	Model *model = new Model(MODEL_FILENAME);
	models.push_back(model);

	/*Model *model2 = new Model(PATH_CUBE_GREEN);
	models.push_back(model2);

	Model *model3 = new Model(PATH_CUBE_BLUE);
	models.push_back(model3);

	model->SetNode(model2);
	model2->SetNode(model3);*/

	Model *model2 = new Model(*model);
	models.push_back(model2);
	Model *model3 = new Model(*model);
	models.push_back(model3);
	SetLights();
}

void Scene::Render(Shader* shader, Camera *camera, float deltaTime)
{
	models[0]->Reset();

	shader->setVec3("viewPos", camera->getPos());
	shader->setVec3("emission", glm::vec3(1.0f, 1.0f, 1.0f));
	shader->setInt("material.diffuse", 0);
	shader->setInt("material.specular", 1);

	// Lights
	Transform *lightTrans;
	UpdateLights(shader);
	
	

	for (int i = 0; i < models.size(); i++)
	{
		models[i]->Reset();
		models[i]->Translate(glm::vec3(i * 10.0f, 0.0f, 0.0f));
		models[i]->Render(shader);
	}



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

void Scene::UpdateLights(Shader *shader)
{
	shader->ActivateLightShader();
	material->SetShininess(shader);
	dirLight->SetAll(shader);
	pointLight->SetAll(shader);
	spotLight->SetAll(shader);
}

void Scene::SetLights()
{
	// Material
	material = new Material(32.0f);

	// Directional light
	dirLight = new DirectionalLight(glm::vec3(-0.2f, -1.0f, -0.3f));
	dirLight->SetValues(glm::vec3(0.05f, 0.05f, 0.05f),
						glm::vec3(0.4f, 0.4f, 0.4f),
						glm::vec3(0.5f, 0.5f, 0.5f));
	
	// Point light
	pointLight = new PointLight(glm::vec3(0.7f, 0.2f, 2.0f),
								1.0f,
								0.09f,
								0.032f);
	pointLight->SetValues(	glm::vec3(0.05f, 0.05f, 0.05f),
							glm::vec3(0.8f, 0.8f, 0.8f),
							glm::vec3(1.0f, 1.0f, 1.0f));
	
	// Spot light
	spotLight = new SpotLight(	glm::vec3(1.5f, 1.0f, 1.5f),
								glm::vec3(-0.5f, 0.0f, -0.5f),
								1.0f,
								0.09f,
								0.032f,
								glm::cos(glm::radians(12.5f)),
								glm::cos(glm::radians(15.0f)));
	spotLight->SetValues(	glm::vec3(0.0f, 0.0f, 0.0f),
							glm::vec3(1.0f, 1.0f, 1.0f),
							glm::vec3(1.0f, 1.0f, 1.0f));
	
}

Scene::~Scene()
{
}
