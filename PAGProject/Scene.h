#pragma once
#include "Headers.h"
#include "Texture.h"
#include "Transform.h"
#include "Mesh.h"
#include "Shader.h"

#define MAX_OBJECTS 10

class Scene
{
public:
	GLuint programHandle;

	Scene();
	bool LoadTextures(GLuint & programHandle);
	void Draw(GLuint & programHandle, GLfloat angle);
	~Scene();

private:
	Texture* texture;
	Mesh* mesh;

	GLfloat x, z;
	float speed[MAX_OBJECTS];
	Transform nodes[MAX_OBJECTS];
	glm::mat4 world;
	
};

