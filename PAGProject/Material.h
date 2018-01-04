#pragma once
#include "Headers.h"
#include "Shader.h"
class Material
{
public:
	Material(float specularMul);
	void SetShininess(Shader * shader);
	void SetDefaultSamplers(Shader *shader);
	~Material();

private:
	float specularMul;
};

