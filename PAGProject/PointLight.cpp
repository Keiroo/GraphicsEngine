#include "PointLight.h"


void PointLight::Update(Shader * shader)
{
	shader->setVec3("pointLight.position", position);
	shader->setVec3("pointLight.ambient", ambient);
	shader->setVec3("pointLight.diffuse", diffuse);
	shader->setVec3("pointLight.specular", specular);
	shader->setFloat("pointLight.constant", constant);
	shader->setFloat("pointLight.linear", linear);
	shader->setFloat("pointLight.quadratic", quadratic);
}

void PointLight::Init(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, glm::vec3 position, float constant, float linear, float quadratic)
{
	this->ambient = ambient;
	this->diffuse = diffuse;
	this->specular = specular;
	this->position = position;
	this->constant = constant;
	this->linear = linear;
	this->quadratic = quadratic;
}
