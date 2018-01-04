#pragma once
#include "Headers.h"
#include "Model.h"
#include "Material.h"
#include "DirectionalLight.h"
#include "PointLight.h"
#include "SpotLight.h"
#include "Transform.h"
#include "Camera.h"
#include <vector>


class Scene
{
public:
	glm::vec3 pRotateAxis, pTranslateVec;
	GLfloat pRotateAngle, pScale;
	GLint modelPicked = -1;

	Scene();
	void Render(Shader* shader, Camera *camera, float deltaTime);
	~Scene();

private:
	std::vector<Model*> models;	
	glm::mat4 world;

	glm::vec3 lastRotateAxis, lastTranslateVec;
	GLfloat lastRotateAngle, lastScale;
	GLint lastModelPicked;

	Material *material;
	DirectionalLight *dirLight;
	PointLight *pointLight;
	SpotLight *spotLight;

	void SetLights();
	void UpdateLights(Shader * shader);
};

