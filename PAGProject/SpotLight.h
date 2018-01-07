#pragma once
#include "Headers.h"
#include "Shader.h"
#include "BaseLight.h"

class SpotLight : public BaseLight
{
public:
	glm::vec3 position, direction;
	float constant, linear, quadratic, cutOff, outercutOff;

	virtual void Update(Shader* shader);
	void Init(	glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, glm::vec3 position, glm::vec3 direction, 
				float constant, float linear, float quadratic, float cutOff, float outercutOff);
};

