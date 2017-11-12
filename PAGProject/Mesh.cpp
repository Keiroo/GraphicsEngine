#include "Mesh.h"

Mesh::Mesh(std::vector<sVertex> vertices, std::vector<GLuint> indices, std::vector<sTexture> textures)
{
	this->vertices = vertices;
	this->indices = indices;
	this->textures = textures;

	LoadBuffers();
}

void Mesh::LoadBuffers()
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &indices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(sVertex), &vertices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(sVertex), (GLvoid*)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(sVertex), (GLvoid*)offsetof(sVertex, Normal));

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(sVertex), (GLvoid*)offsetof(sVertex, TexCoords));

	//glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);
	//glBindBuffer(GL_ARRAY_BUFFER, VBO[2]);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(texCoords), texCoords, GL_STATIC_DRAW);

	glBindVertexArray(0);
}

//bool Mesh::LoadTextures(GLuint &programHandle)
//{
//	if (!scene->LoadTextures(programHandle))
//		return false;
//
//	return true;
//}

//void Mesh::Render(GLuint &programHandle, float deltaTime)
//{
//	angle += deltaTime;
//	if (angle > 360.0f)
//		angle -= 360.0f;
//
//	glUseProgram(programHandle);
//	glBindVertexArray(VAO);	
//
//	scene->Draw(programHandle, angle);
//}

void Mesh::Render(GLuint &programHandle)
{
	GLuint diffuseNr = 1, specularNr = 1;

	for (GLuint i = 0; i < textures.size(); i++)
	{
		glActiveTexture(GL_TEXTURE0 + i);
		std::string number, name = textures[i].type;

		if (name == "textureDiffuse")
			number = std::to_string(diffuseNr++);
		else if (name == "textureSpecular")
			number = std::to_string(specularNr++);

		glUniform1i(glGetUniformLocation(programHandle, (name + number).c_str()), i);
		glBindTexture(GL_TEXTURE_2D, textures[i].id);
	}

	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	glActiveTexture(GL_TEXTURE0);
}

Mesh::~Mesh()
{
}
