#pragma once
#include "Headers.h"
#include "Shader.h"
class Material
{
public:
	void Update(Shader* shader);
	void Init(std::string name, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float shininess);	

private:
	std::string name;
	glm::vec3 ambient, diffuse, specular;
	float shininess;
};

