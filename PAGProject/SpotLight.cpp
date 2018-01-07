#include "SpotLight.h"

void SpotLight::Update(Shader * shader)
{
	shader->setVec3("spotLight.position", position);
	shader->setVec3("spotLight.direction", direction);
	shader->setVec3("spotLight.ambient", ambient);
	shader->setVec3("spotLight.diffuse", diffuse);
	shader->setVec3("spotLight.specular", specular);
	shader->setFloat("spotLight.constant", constant);
	shader->setFloat("spotLight.linear", linear);
	shader->setFloat("spotLight.quadratic", quadratic);
	shader->setFloat("spotLight.cutOff", cutOff);
	shader->setFloat("spotLight.outerCutOff", outercutOff);
}

void SpotLight::Init(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, glm::vec3 position, glm::vec3 direction, float constant, float linear, float quadratic, float cutOff, float outercutOff)
{
	this->ambient = ambient;
	this->diffuse = diffuse;
	this->specular = specular;
	this->position = position;
	this->direction = direction;
	this->constant = constant;
	this->linear = linear;
	this->quadratic = quadratic;
	this->cutOff = cutOff;
	this->outercutOff = outercutOff;
}
