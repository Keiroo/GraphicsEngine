#pragma once
#include "Headers.h"


class BaseLight
{
public:
	BaseLight();
	void SetValues(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular);
	~BaseLight();

protected:
	glm::vec3 ambient, diffuse, specular;
};

