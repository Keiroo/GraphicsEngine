#pragma once
#include "Headers.h"
#include "Model.h"
//#include "TestModel.h"
//#include "Transform.h"
#include <vector>


class Scene
{
public:
	Scene();
	void Render(Shader* shader);
	~Scene();

private:
	//Transform* transform;
	//Model* model;
	std::vector<Model*> models;	
	glm::mat4 world;
};

