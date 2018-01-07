#pragma once
#include "Headers.h"
#include "BaseLight.h"
#include "Shader.h"

class DirectionalLight : public BaseLight
{
public:
	glm::vec3 direction;

	virtual void Update(Shader * shader);
	void Init(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, glm::vec3 direction);
};

