#pragma once
#include "Headers.h"
#include "Transform.h"

#define MAX_OBJECTS 10

class Mesh
{
public:
	Mesh();
	void LoadBuffers();
	void Render(GLuint &programHandle, float deltaTime);
	~Mesh();

private:
	GLfloat x, z, angle;
	float speed[MAX_OBJECTS];
	GLuint VBO[3], VAO, EBO;
	Transform* transform;

	/*GLfloat vertices[9] = { 0.0f,  0.5f, 0.0f,
							0.5f, -0.5f, 0.0f,
							-0.5f, -0.5f, 0.0f };*/

	//glm::vec3 vertices[18] = {	glm::vec3(-0.5f, -0.5f,  0.5f), //basis
	//							glm::vec3(0.5f, -0.5f,  0.5f),
	//							glm::vec3(0.5f, -0.5f, -0.5f),
	//							glm::vec3(-0.5f, -0.5f,  0.5f),
	//							glm::vec3(0.5f, -0.5f, -0.5f),
	//							glm::vec3(-0.5f, -0.5f, -0.5f),
	//							glm::vec3(-0.5f, -0.5f, -0.5f), //left side
	//							glm::vec3(-0.5f, -0.5f,  0.5f),
	//							glm::vec3(0.0f,  0.5f,  0.0f),
	//							glm::vec3(0.5f, -0.5f,  0.5f), //right side
	//							glm::vec3(0.5f, -0.5f, -0.5f),
	//							glm::vec3(0.0f,  0.5f,  0.0f),
	//							glm::vec3(-0.5f, -0.5f,  0.5f), //front side
	//							glm::vec3(0.5f, -0.5f,  0.5f),
	//							glm::vec3(0.0f,  0.5f,  0.0f),
	//							glm::vec3(0.5f, -0.5f, -0.5f), //back side
	//							glm::vec3(-0.5f, -0.5f, -0.5f),
	//							glm::vec3(0.0f,  0.5f,  0.0f) };


	glm::vec3 vertices[8] = {	glm::vec3(1.0f, 1.0f, 1.0f),
								glm::vec3(-1.0f, 1.0f, 1.0f),
								glm::vec3(-1.0f, 1.0f, -1.0f),
								glm::vec3(1.0f, 1.0f, -1.0f),
								glm::vec3(1.0f, -1.0f, 1.0f),
								glm::vec3(-1.0f, -1.0f, 1.0f),
								glm::vec3(-1.0f, -1.0f, -1.0f),
								glm::vec3(1.0f, -1.0f, -1.0f) };


	GLfloat colors[9] = {	1.0f, 0.0f, 0.0f,
							0.0f, 1.0f, 0.0f,
							0.0f, 0.0f, 1.0f };

	GLfloat texCoords[6] = {	0.5f, 1.0f,
								1.0f, 0.0f,
								0.0f, 0.0f };

	/*GLuint indices[3] = { 0, 1, 2 };*/

	/*GLuint indices[18] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17 };*/

	GLuint indices[3 * 12] = {	0, 1, 2, 
								2, 3, 0, 
								4, 5, 6, 
								6, 7, 4, 
								4, 5, 1, 
								1, 0, 4, 
								7, 6, 2, 
								2, 3, 7, 
								5, 6, 2, 
								2, 1, 5, 
								7, 4, 0, 
								0, 3, 7 };


};

