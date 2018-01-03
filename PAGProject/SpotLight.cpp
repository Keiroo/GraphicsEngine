#include "SpotLight.h"



SpotLight::SpotLight(glm::vec3 position, glm::vec3 direction, float constant, float linear, float quadratic, float cutOff, float outerCutOff) : BaseLight()
{
	this->position = position;
	this->direction = direction;
	this->constant = constant;
	this->linear = linear;
	this->quadratic = quadratic;
	this->cutOff = cutOff;
	this->outerCutOff = outerCutOff;
}

void SpotLight::SetValues(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular)
{
	BaseLight::SetValues(ambient, diffuse, specular);
}

void SpotLight::SetAll(Shader *shader)
{
	shader->setVec3("dirLight.position", position);
	shader->setVec3("dirLight.ambient", ambient);
	shader->setVec3("dirLight.diffuse", diffuse);
	shader->setVec3("dirLight.specular", specular);
	shader->setFloat("dirLight.constant", constant);
	shader->setFloat("dirLight.linear", linear);
	shader->setFloat("dirLight.quadratic", quadratic);
	shader->setFloat("dirLight.cutOff", cutOff);
	shader->setFloat("dirLight.outerCutOff", outerCutOff);
}


SpotLight::~SpotLight()
{
}
