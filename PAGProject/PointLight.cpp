#include "PointLight.h"



PointLight::PointLight(glm::vec3 position, float constant, float linear, float quadratic) : BaseLight()
{
	this->position = position;
	this->constant = constant;
	this->linear = linear;
	this->quadratic = quadratic;
}

void PointLight::SetValues(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular)
{
	BaseLight::SetValues(ambient, diffuse, specular);
}

void PointLight::SetAll(Shader *shader)
{
	shader->setVec3("dirLight.position", position);
	shader->setVec3("dirLight.ambient", ambient);
	shader->setVec3("dirLight.diffuse", diffuse);
	shader->setVec3("dirLight.specular", specular);
	shader->setFloat("dirLight.constant", constant);
	shader->setFloat("dirLight.linear", linear);
	shader->setFloat("dirLight.quadratic", quadratic);
}

PointLight::~PointLight()
{
}
