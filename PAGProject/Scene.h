#pragma once
#include "Headers.h"
#include "Model.h"
#include "TestModel.h"
#include "Transform.h"


class Scene
{
public:
	Scene();
	void Render(Shader* shader);
	~Scene();

private:
	Transform* transform;
	Model* model;
	TestModel* testModel;
	
};

