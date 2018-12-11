#pragma once
#include "Headers.h"
#include "Model.h"
#include <vector>
#include "DirectionalLight.h"
#include "SpotLight.h"
#include "PointLight.h"
#include "Material.h"
#include "Camera.h"
#include "Skybox.h"
#include "GrassGen.h"


class Scene
{
public:
	glm::vec3 pRotateAxis, pTranslateVec;
	GLfloat pRotateAngle, pScale;
	GLint modelPicked = -1;

	GLfloat TBtest, TBtest2, TBtest3, TBtest4;
	GLfloat fAlphaTest, fAlphaMultiplier;

	Material mMaterial, clearMaterial;
	DirectionalLight dirLight;
	PointLight pointLight;
	SpotLight spotLight;
	GrassGen *grassGen;

	Scene();
	void Render(Shader* shader, Camera *camera, float deltaTime);

	
	~Scene();

private:
	std::vector<Model*> models, lightModels;	
	glm::mat4 world;

	glm::vec3 lastRotateAxis, lastTranslateVec;
	GLfloat lastRotateAngle, lastScale;
	GLint lastModelPicked;

	Texture *texture;
	GLuint texID;
	Skybox *skybox;
	

	void SetMaterialAndLights();
	void UpdateLights(Shader *shader);
};

