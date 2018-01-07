#include "DirectionalLight.h"


void DirectionalLight::Update(Shader * shader)
{
	shader->setVec3("dirLight.direction", direction);
	shader->setVec3("dirLight.ambient", ambient);
	shader->setVec3("dirLight.diffuse", diffuse);
	shader->setVec3("dirLight.specular", specular);
}

void DirectionalLight::Init(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, glm::vec3 direction)
{
	this->ambient = ambient;
	this->diffuse = diffuse;
	this->specular = specular;
	this->direction = direction;
}
