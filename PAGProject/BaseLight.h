#pragma once
#include "Headers.h"
#include "Shader.h"

class BaseLight
{
public:
	glm::vec3 ambient, diffuse, specular;
	virtual void Update(Shader *shader) = 0;	
};

