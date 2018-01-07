#pragma once
#include "Headers.h"
#include "Shader.h"
#include "BaseLight.h"

class PointLight : public BaseLight
{
public:
	glm::vec3 position;
	float constant, linear, quadratic;

	virtual void Update(Shader *shader);
	void Init(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, glm::vec3 position, float constant, float linear, float quadratic);

};

