#include "Material.h"

void Material::Init(std::string name, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float shininess)
{
	this->name = name;
	this->ambient = ambient;
	this->diffuse = diffuse;
	this->specular = specular;
	this->shininess = shininess;
}

void Material::Update(Shader * shader)
{
	shader->setFloat("mMaterial.shininess", shininess);
	shader->setVec3("mMaterial.ambient", ambient);
	shader->setVec3("mMaterial.diffuse", diffuse);
	shader->setVec3("mMaterial.specular", specular);
}
