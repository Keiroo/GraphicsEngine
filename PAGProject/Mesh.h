#pragma once
#include "Headers.h"
#include "Shader.h"
#include <string>
#include <vector>

struct sVertex {
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
	glm::vec3 Tangent;
	glm::vec3 Bitangent;
};


struct sTexture {
	unsigned int id;
	std::string type;
	aiString path;
};

class Mesh
{
public:
	std::vector<sVertex> vertices;
	std::vector<unsigned int> indices;
	std::vector<sTexture> textures;

	Mesh(std::vector<sVertex> vertices, std::vector<unsigned int> indices, std::vector<sTexture> textures);
	void Render(Shader* shader);
	~Mesh();

private:
	GLuint VBO, VAO, EBO;
	void LoadBuffers();


};

