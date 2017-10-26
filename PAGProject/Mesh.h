#pragma once
#include "Headers.h"

class Mesh
{
public:
	Mesh();
	void LoadBuffers();
	void Render();
	~Mesh();

private:
	GLuint VBO, VAO, EBO;

	GLfloat vertices[9] = {	-0.5f, -0.5f, 0.0f,
							0.5f, -0.5f, 0.0f,
							0.0f,  0.5f, 0.0f };

	GLuint indices[3] = { 0, 1, 2 };

};

