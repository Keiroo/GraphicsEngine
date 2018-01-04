#include "Mesh.h"



Mesh::Mesh(std::vector<sVertex> vertices, std::vector<unsigned int> indices, std::vector<sTexture> textures)
{
	this->vertices = vertices;
	this->indices = indices;
	this->textures = textures;

	LoadBuffers();
}

void Mesh::LoadBuffers()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(sVertex), &vertices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int),
		&indices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(sVertex), (void*)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(sVertex), (void*)offsetof(sVertex, Normal));

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(sVertex), (void*)offsetof(sVertex, TexCoords));

	glBindVertexArray(0);
}


void Mesh::Render(Shader* shader)
{
	GLuint diffuseNr = 1, specularNr = 1, normalNr = 1, heightNr = 1;

	shader->setInt("material.diffuse", 0);
	shader->setInt("material.specular", 1);
	shader->setFloat("material.shininess", 32.0f);

	for (GLuint i = 0; i < textures.size(); i++)
	{
		glActiveTexture(GL_TEXTURE0 + i);

		std::string number, name = textures[i].type, res;
		//if (name == "texture_diffuse")
		//{
		//	number = std::to_string(diffuseNr++);
		//	res = "material.diffuse";
		//}			
		//else if (name == "texture_specular")
		//{
		//	number = std::to_string(specularNr++);
		//	res = "material.specular";
		//}			
		//else if (name == "texture_normal")
		//	number = std::to_string(normalNr++);
		//else if (name == "texture_height")
		//	number = std::to_string(heightNr++);



		///*glUniform1i(glGetUniformLocation(shader->programHandle, (name + number).c_str()), i);*/
		//glUniform1i(glGetUniformLocation(shader->programHandle, res.c_str()), i);
		//glBindTexture(GL_TEXTURE_2D, textures[i].id);

		//if (name == "texture_diffuse")
		//{
		//	number = std::to_string(diffuseNr++);
		//	res = "material.diffuse";
		//	const GLchar* resChar = res.c_str();
		//	glUniform1i(glGetUniformLocation(shader->lightProgramHandle, resChar), i);
		//	glBindTexture(GL_TEXTURE_2D, textures[i].id);
		//}

		if (name == "texture_diffuse" && diffuseNr == 1)
		{
			number = std::to_string(diffuseNr++);
			res = name;
			const GLchar* resChar = "material.diffuse";
			glUniform1i(glGetUniformLocation(shader->programHandle, resChar), i);
			glBindTexture(GL_TEXTURE_2D, textures[i].id);
		}

		if (name == "texture_specular" && specularNr == 1)
		{
			number = std::to_string(specularNr++);
			res = name;
			const GLchar* resChar = "material.specular";
			glUniform1i(glGetUniformLocation(shader->programHandle, resChar), i);
			glBindTexture(GL_TEXTURE_2D, textures[i].id);
		}
	}

	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	glActiveTexture(GL_TEXTURE0);
}

Mesh::~Mesh()
{
}
