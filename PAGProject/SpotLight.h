#pragma once
#include "Headers.h"
#include "BaseLight.h"
#include "Shader.h"
class SpotLight : BaseLight
{
public:
	SpotLight(glm::vec3 position, glm::vec3 direction, float constant, float linear, float quadratic, float cutOff, float outerCutOff);
	void SetValues(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular);
	void SetAll(Shader * shader);
	~SpotLight();

private:
	glm::vec3 position, direction;
	float constant, linear, quadratic, cutOff, outerCutOff;
};

