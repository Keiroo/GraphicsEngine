#include "Material.h"



Material::Material(float specularMul)
{
	this->specularMul = specularMul;
}

void Material::SetShininess(Shader *shader)
{
	shader->setFloat("material.shininess", specularMul);
}


Material::~Material()
{
}
