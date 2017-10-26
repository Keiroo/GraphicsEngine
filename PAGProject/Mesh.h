#pragma once
#include "Headers.h"

class Mesh
{
public:
	Mesh();
	void LoadBuffers();
	void Render(GLuint &programHandle);
	~Mesh();

private:
	GLuint VBO[3], VAO, EBO;

	GLfloat vertices[9] = { 0.0f,  0.5f, 0.0f,
							0.5f, -0.5f, 0.0f,
							-0.5f, -0.5f, 0.0f };

	GLfloat colors[9] = {	1.0f, 0.0f, 0.0f,
							0.0f, 1.0f, 0.0f,
							0.0f, 0.0f, 1.0f };

	GLfloat texCoords[6] = {	0.5f, 1.0f,
								1.0f, 0.0f,
								0.0f, 0.0f };

	GLuint indices[3] = { 0, 1, 2 };

};

