#pragma once
#include "Headers.h"
#include "Scene.h"
#include <string>
#include <vector>

struct sVertex {
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
};

struct sTexture {
	GLuint id;
	std::string type;
	aiString path;
};

class Mesh
{
public:
	GLuint VAO;
	std::vector<sVertex> vertices;
	std::vector<GLuint> indices;
	std::vector<sTexture> textures;

	Mesh(std::vector<sVertex> vertices, std::vector<GLuint> indices, std::vector<sTexture> textures);
	
	bool LoadTextures(GLuint & programHandle);
	/*void Render(GLuint &programHandle, float deltaTime);*/
	void Render(GLuint & programHandle);
	~Mesh();

private:
	GLfloat angle;
	GLuint VBO, EBO;
	Scene* scene;

	void LoadBuffers();

	/*glm::vec3 vertices[3 * 12] = {
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
*/
};

