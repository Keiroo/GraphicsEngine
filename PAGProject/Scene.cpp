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

	texture = new Texture();
	models.push_back(new Model(PLANE_FILENAME));
	texID = texture->TextureFromFile("terrain2.jpg", "Textures", false);
	//texID = texture->TextureFromFile("grass.png", "Textures", false);

	skybox = new Skybox();

	grassGen = new GrassGen();
	fAlphaTest = 0.25f;
	fAlphaMultiplier = 1.50f;

	models.push_back(new Model(WOMANROCK_FILENAME));
	TBtest = TBtest2 = TBtest3 = 0.0f;
	TBtest4 = 1.0f;

	models.push_back(new Model(OLAV_FILENAME));
	models.push_back(new Model(TEMPLAR_FILENAME));

	//lightModels.push_back(new Model(PATH_CUBE_BLUE));
	//lightModels.push_back(new Model(PATH_CUBE_GREEN));
	//lightModels.push_back(new Model(PATH_CUBE_RED));

	SetMaterialAndLights();
}

void Scene::Render(Shader* shader, Camera *camera, float deltaTime)
{
	UpdateLights(shader);
	shader->setVec3("viewPos", cameraPos);
	shader->setFloat("material.shininess", 32.0f);	

	/* Light models
	lightModels[0]->Reset();
	lightModels[0]->Translate(pointLight.position);
	lightModels[0]->Scale(0.05f, 0.05f, 0.05f);
	lightModels[0]->Render(shader);

	lightModels[1]->Reset();
	lightModels[1]->Translate(spotLight.position);
	lightModels[1]->Scale(0.05f, 0.05f, 0.05f);
	lightModels[1]->Render(shader);

	lightModels[2]->Reset();
	lightModels[2]->Translate(glm::vec3(100.0f, 50.0f, 100.0f));
	lightModels[2]->Scale(1.0f, 1.0f, 1.0f);
	lightModels[2]->Render(shader);*/

	clearMaterial.Update(shader);

	// Plane
	models[0]->Reset();
	texture->ActivateTexture(texID);
	//models[0]->Render(shader);
	
	// Sculpture in the wall
	models[1]->Reset();
	models[1]->Scale(2.0f, 2.0f, 2.0f);
	models[1]->Rotate(-90.0f, glm::vec3(1.0f, 0.0f, 0.0f));
	models[1]->Rotate(2.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	models[1]->Translate(glm::vec3(-45.8f, 40.9f, 5.9f));
	models[1]->Render(shader);

	// Ruins
	models[2]->Reset();
	models[2]->Scale(12.0f, 12.0f, 12.0f);
	models[2]->Rotate(31.0f, glm::vec3(1.0f, 0.0f, 0.0f));
	models[2]->Rotate(-87.0f, glm::vec3(0.0f, 0.0f, 1.0f));
	models[2]->Translate(glm::vec3(1.8f, 0.0f, 0.8f));
	models[2]->Render(shader);


	// Knight
	shader->ActivateRefShader();
	shader->setInt("skybox", 0);
	shader->setVec3("cameraPos", camera->thisCameraPos);
	models[3]->Reset();
	models[3]->Scale(0.2f, 0.2f, 0.2f);
	models[3]->Rotate(-130.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	models[3]->Translate(glm::vec3(-341.6f, 2.2f, -391.5f));
	shader->setMat4("model", models[3]->transform.GetMatrix());
	shader->setMat4("view", camera->GetViewMatrix());
	shader->setMat4("projection", camera->GetProjectionMatrix());
	models[3]->RenderRef(shader, skybox);
	shader->ActivateShader();


	// Grass
	grassGen->transform->Reset();
	grassGen->transform->Rotate(TBtest4, glm::vec3(0.0f, 1.0f, 0.0f));
	grassGen->transform->Translate(glm::vec3(TBtest, TBtest2, TBtest3));
	grassGen->Render(shader, camera, deltaTime, fAlphaTest, fAlphaMultiplier);

	// Skybox
	skybox->Render(shader, camera);
	
	/*int count = 1;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			models[count]->Reset();
			models[count]->Translate(glm::vec3(i * 10.0f, 0.0f, j * 10.0f));

			if (count % 2 == 0) mMaterial.Update(shader);
			else clearMaterial.Update(shader);

			models[count]->Render(shader);
			count++;
		}
	}*/

	//models[0]->Translate(glm::vec3(10.0f, 0.0f, 0.0f));
	//dsadasd

	/*models[0]->Render(shader);*/
	Model::modelsRendered = 0;
/*
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
	}*/
	//else
	//{
	//	models[0]->Reset();
	//	models[0]->Scale(pScale, pScale, pScale);
	//	models[0]->Rotate(pRotateAngle, pRotateAxis);
	//	models[0]->Translate(pTranslateVec);
	//}

	//models[0]->Reset();
	//models[0]->Rotate(world, pRotateAngle, pRotateAxis);
	//models[0]->Translate(world, glm::vec3(30.0f, 0.0f, 0.0f));
	//models[0]->Render(shader);
	//Model::modelsRendered = 0;
}

void Scene::SetMaterialAndLights()
{
	clearMaterial.Init("Clear", glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), 0.0f);
	mMaterial.Init("Chrome", glm::vec3(0.25f, 0.25f, 0.25f), glm::vec3(0.4f, 0.4f, 0.4f), glm::vec3(0.774597f, 0.774597f, 0.774597f), 0.6f);

	dirLight.Init(glm::vec3(0.1f, 0.1f, 0.1f), glm::vec3(0.7f, 0.7f, 0.7f), glm::vec3(0.9f, 0.9f, 0.9f), glm::vec3(-0.5f, -1.0f, -0.5f));
	
	pointLight.Init(glm::vec3(0.1f, 0.1f, 0.1f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec3(0.0f, -10.0f, 0.0f), 0.1f, 0.1f, 0.1f);
	spotLight.Init(glm::vec3(0.1f, 0.1f, 0.1f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec3(0.1f, -10.0f, 0.1f), glm::vec3(0.1f, -0.1f, 0.1f),
		0.1f, 0.1f, 0.1f, glm::cos(glm::radians(0.0f)), glm::cos(glm::radians(0.0f)));


	
	//dirLight.Init(glm::vec3(0.3f, 0.3f, 0.3f), glm::vec3(0.3f, 0.3f, 0.3f), glm::vec3(0.45f, 0.4f, 0.4f), glm::vec3(-0.5f, -1.0f, -0.5f));
	//pointLight.Init(glm::vec3(0.1f, 0.1f, 1.0f), glm::vec3(0.1f, 0.1f, 1.0f), glm::vec3(0.9f, 1.0f, 0.9f), glm::vec3(20.0f, 1.0f, 30.0f), 1.0f, 0.09f, 0.032f);
	//spotLight.Init(	glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.8f, 0.8f, 1.0f), glm::vec3(0.9f, 1.0f, 0.9f), glm::vec3(15.0f, 5.0f, 8.0f), glm::vec3(0.0f, -1.0f, 0.0f),
	//				1.0f, 0.022f, 0.0019f, glm::cos(glm::radians(15.0f)), glm::cos(glm::radians(20.0f)));
}

void Scene::UpdateLights(Shader *shader)
{	
	//dirLight.diffuse = glm::vec3(1.0f, sin(glfwGetTime()), sin(glfwGetTime()));
	dirLight.Update(shader);

	//pointLight.position = glm::vec3(sin(glfwGetTime() * 1.5f) * 7.0f + 20.0f, 3.0f, 32.0f);
	pointLight.Update(shader);


	//spotLight.direction = glm::vec3(sin(-glfwGetTime() *0.8f), -1.0f, sin(-glfwGetTime() *0.8f));
	//spotLight.diffuse = glm::vec3(sin(glfwGetTime()) * 0.5f, 1.0f, sin(glfwGetTime()) * 0.5f);
	spotLight.Update(shader);
}


Scene::~Scene()
{
}
