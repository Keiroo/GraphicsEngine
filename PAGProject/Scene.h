#pragma once
#include "Headers.h"
#include "Texture.h"
#include "Transform.h"
#include "Mesh.h"
#include "Shader.h"
#include "Model.h"

#define MAX_OBJECTS 10

class Model;

class Scene
{
public:
	GLuint programHandle;

	Scene();
	//bool LoadTextures(GLuint & programHandle, GLfloat deltaTime);
	void Draw(GLfloat angle);
	~Scene();

private:
	Model* model;
	Transform* transform;
	Shader* shader;

	GLfloat /*angle,*/ x, z;
	/*float speed[MAX_OBJECTS];
	Transform nodes[MAX_OBJECTS];*/
	glm::mat4 world;
	
};

