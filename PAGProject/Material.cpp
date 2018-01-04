#include "Material.h"



Material::Material(float specularMul)
{
	this->specularMul = specularMul;
}

void Material::SetShininess(Shader *shader)
{
	shader->setFloat("material.shininess", specularMul);
}

void Material::SetDefaultSamplers(Shader *shader)
{
	shader->setInt("material.diffuse", 0);
	shader->setInt("material.specular", 0);
}

Material::~Material()
{
}
