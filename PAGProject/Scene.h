#pragma once
#include "Headers.h"
#include "Model.h"
#include "TestModel.h"


class Scene
{
public:
	Scene();
	void Render(Shader* shader);
	~Scene();

private:
	Model* model;
	TestModel* testModel;
	
};

