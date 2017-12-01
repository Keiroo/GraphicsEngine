#pragma once
#include "Headers.h"
#include "Model.h"
#include <vector>


class Scene
{
public:
	glm::vec3 pRotateAxis, pTranslateVec;
	GLfloat pRotateAngle;
	GLint modelPicked = -1;

	Scene();
	void Render(Shader* shader, float deltaTime);
	~Scene();

private:
	std::vector<Model*> models;	
	glm::mat4 world;

	GLfloat angle;
};

