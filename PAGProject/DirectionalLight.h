#pragma once
#include "Headers.h"
#include "Material.h"
#include "BaseLight.h"

class DirectionalLight : public BaseLight
{
public:
	DirectionalLight(glm::vec3 direction);
	void SetValues(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular);
	void SetAll(Shader *shader);
	~DirectionalLight();

private:
	glm::vec3 dir;
};

