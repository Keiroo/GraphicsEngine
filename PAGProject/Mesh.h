#pragma once
#include "Headers.h"
#include "Scene.h"

class Mesh
{
public:
	Mesh();
	void LoadBuffers();
	bool LoadTextures(GLuint & programHandle);
	void Render(GLuint &programHandle, float deltaTime);
	~Mesh();

private:
	GLfloat angle;	
	GLuint VBO[3], VAO, EBO;
	Scene* scene;
	


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


	glm::vec3 oldvertices[8] = {	
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(-1.0f, 1.0f, 1.0f),
		glm::vec3(-1.0f, 1.0f, -1.0f),
		glm::vec3(1.0f, 1.0f, -1.0f),
		glm::vec3(1.0f, -1.0f, 1.0f),
		glm::vec3(-1.0f, -1.0f, 1.0f),
		glm::vec3(-1.0f, -1.0f, -1.0f),
		glm::vec3(1.0f, -1.0f, -1.0f), 	
	};


	glm::vec3 vertices[3 * 12] = {
		glm::vec3(1.0f, 1.0f, 1.0f), 
		glm::vec3(-1.0f, 1.0f, 1.0f),
		glm::vec3(-1.0f, 1.0f, -1.0f),

		glm::vec3(-1.0f, 1.0f, -1.0f),
		glm::vec3(1.0f, 1.0f, -1.0f),
		glm::vec3(1.0f, 1.0f, 1.0f),

		glm::vec3(1.0f, -1.0f, -1.0f),
		glm::vec3(-1.0f, -1.0f, -1.0f),
		glm::vec3(-1.0f, -1.0f, 1.0f),

		glm::vec3(-1.0f, -1.0f, 1.0f),
		glm::vec3(1.0f, -1.0f, 1.0f),
		glm::vec3(1.0f, 1.0f, -1.0f),

		glm::vec3(1.0f, -1.0f, 1.0f),
		glm::vec3(-1.0f, -1.0f, 1.0f),
		glm::vec3(-1.0f, 1.0f, 1.0f),

		glm::vec3(-1.0f, 1.0f, 1.0f),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(1.0f, -1.0f, 1.0f),

		glm::vec3(-1.0f, -1.0f, -1.0f),
		glm::vec3(1.0f, -1.0f, -1.0f),
		glm::vec3(1.0f, 1.0f, -1.0f),

		glm::vec3(1.0f, 1.0f, -1.0f),
		glm::vec3(-1.0f, 1.0f, -1.0f),
		glm::vec3(-1.0f, -1.0f, -1.0f),

		glm::vec3(-1.0f, -1.0f, 1.0f),
		glm::vec3(-1.0f, -1.0f, -1.0f),
		glm::vec3(-1.0f, 1.0f, -1.0f),

		glm::vec3(-1.0f, 1.0f, -1.0f),
		glm::vec3(-1.0f, 1.0f, 1.0f),
		glm::vec3(-1.0f, -1.0f, 1.0f),

		glm::vec3(1.0f, -1.0f, -1.0f),
		glm::vec3(1.0f, -1.0f, 1.0f),
		glm::vec3(1.0f, 1.0f, 1.0f),

		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(1.0f, 1.0f, -1.0f),
		glm::vec3(1.0f, -1.0f, -1.0f)
	};



	GLfloat colors[9] = {	
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f 
	};

	GLfloat texCoords[12 * 6] = {
		1.0f, 0.0f,	0.0f, 0.0f,	0.0f, 1.0f,	0.0f, 1.0f,	1.0f, 1.0f,	1.0f, 0.0f,
		1.0f, 0.0f,	0.0f, 0.0f,	0.0f, 1.0f,	0.0f, 1.0f,	1.0f, 1.0f,	1.0f, 0.0f,
		1.0f, 0.0f,	0.0f, 0.0f,	0.0f, 1.0f,	0.0f, 1.0f,	1.0f, 1.0f,	1.0f, 0.0f,
		1.0f, 0.0f,	0.0f, 0.0f,	0.0f, 1.0f,	0.0f, 1.0f,	1.0f, 1.0f,	1.0f, 0.0f,
		1.0f, 0.0f,	0.0f, 0.0f,	0.0f, 1.0f,	0.0f, 1.0f,	1.0f, 1.0f,	1.0f, 0.0f,
		1.0f, 0.0f,	0.0f, 0.0f,	0.0f, 1.0f,	0.0f, 1.0f,	1.0f, 1.0f,	1.0f, 0.0f
	};

	/*GLuint indices[3] = { 0, 1, 2 };*/

	/*GLuint indices[18] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17 };*/

	GLuint indices[3 * 12] = {	0, 1, 2, 
								2, 3, 0, 
								7, 6, 5,
								5, 4, 7,
								4, 5, 1, 
								1, 0, 4, 
								6, 7, 3,
								3, 2, 6,
								5, 6, 2, 
								2, 1, 5, 
								7, 4, 0, 
								0, 3, 7 };

};

