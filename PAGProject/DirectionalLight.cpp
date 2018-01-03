#include "DirectionalLight.h"



DirectionalLight::DirectionalLight(glm::vec3 direction) : BaseLight()
{
	dir = direction;
}

void DirectionalLight::SetValues(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular)
{
	BaseLight::SetValues(ambient, diffuse, specular);
}

void DirectionalLight::SetAll(Shader *shader)
{
	shader->setVec3("dirLight.direction", dir);
	shader->setVec3("dirLight.ambient", ambient);
	shader->setVec3("dirLight.diffuse", diffuse);
	shader->setVec3("dirLight.specular", specular);
}


DirectionalLight::~DirectionalLight()
{
}
