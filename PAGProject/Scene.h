#pragma once
#include "Headers.h"
#include "Model.h"
#include <vector>
#include "DirectionalLight.h"
#include "SpotLight.h"
#include "PointLight.h"
#include "Material.h"
#include "Camera.h"


class Scene
{
public:
	glm::vec3 pRotateAxis, pTranslateVec;
	GLfloat pRotateAngle, pScale;
	GLint modelPicked = -1;

	Material mMaterial, clearMaterial;
	DirectionalLight dirLight;
	PointLight pointLight;
	SpotLight spotLight;

	Scene();
	void Render(Shader* shader, Camera *camera, float deltaTime);
	
	~Scene();

private:
	std::vector<Model*> models, lightModels;	
	glm::mat4 world;

	glm::vec3 lastRotateAxis, lastTranslateVec;
	GLfloat lastRotateAngle, lastScale;
	GLint lastModelPicked;

	

	void SetMaterialAndLights();
	void UpdateLights(Shader *shader);
};

