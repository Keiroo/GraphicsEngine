#pragma once
#include "Headers.h"
#include "BaseLight.h"
#include "Shader.h"
class PointLight : BaseLight
{
public:
	PointLight(glm::vec3 position, float constant, float linear, float quadratic);
	void SetValues(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular);
	void SetAll(Shader * shader);
	~PointLight();

private:
	glm::vec3 position;
	float constant, linear, quadratic;
};

