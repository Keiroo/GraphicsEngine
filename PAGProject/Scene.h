#pragma once
#include "Headers.h"
#include "Texture.h"
#include "Transform.h"

#define MAX_OBJECTS 10

class Scene
{
public:
	Scene();
	bool LoadTextures(GLuint & programHandle);
	void Draw(GLuint & programHandle, GLfloat angle);
	~Scene();

private:
	GLfloat x, z;
	float speed[MAX_OBJECTS];

	Texture* texture;
	Transform nodes[MAX_OBJECTS];
	glm::mat4 world;
	
};

