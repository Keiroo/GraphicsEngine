#include "TestModel.h"



TestModel::TestModel()
{
	texture = new Texture();
	sVertex* vertex = new sVertex;
	sTexture* tex = new sTexture;

	LoadVertices(vertex);

	for (GLuint i = 0; i < 4; i++)
	{
		indices.push_back(i);
	}

	tex->id = texture->TextureFromFile("lavaTexture.jpg", "Textures", false);
	tex->type = "texture_diffuse";
	tex->path = "lavaTexture.jpg";
	textures.push_back(*tex);

	mesh = new Mesh(vertices, indices, textures);
}

void TestModel::Render(Shader * shader)
{
	mesh->Render(shader);
}


TestModel::~TestModel()
{
}


void TestModel::LoadVertices(sVertex* vertex)
{
	vertex = new sVertex;
	vertex->Position = glm::vec3(0.0f, 0.0f, 0.0f);
	vertex->TexCoords = glm::vec2(0.0f, 0.0f);
	vertex->Normal = glm::vec3(0.0f, 0.0f, 0.0f);
	vertex->Tangent = glm::vec3(0.0f, 0.0f, 0.0f);
	vertex->Bitangent = glm::vec3(0.0f, 0.0f, 0.0f);
	vertices.push_back(*vertex);

	vertex = new sVertex;
	vertex->Position = glm::vec3(1.0f, 0.0f, 0.0f);
	vertex->TexCoords = glm::vec2(1.0f, 0.0f);
	vertex->Normal = glm::vec3(1.0f, 0.0f, 0.0f);
	vertex->Tangent = glm::vec3(0.0f, 0.0f, 0.0f);
	vertex->Bitangent = glm::vec3(0.0f, 0.0f, 0.0f);
	vertices.push_back(*vertex);

	vertex = new sVertex;
	vertex->Position = glm::vec3(1.0f, 0.0f, 1.0f);
	vertex->TexCoords = glm::vec2(1.0f, 1.0f);
	vertex->Normal = glm::vec3(1.0f, 0.0f, 1.0f);
	vertex->Tangent = glm::vec3(0.0f, 0.0f, 0.0f);
	vertex->Bitangent = glm::vec3(0.0f, 0.0f, 0.0f);
	vertices.push_back(*vertex);

	vertex = new sVertex;
	vertex->Position = glm::vec3(0.0f, 0.0f, 1.0f);
	vertex->TexCoords = glm::vec2(0.0f, 1.0f);
	vertex->Normal = glm::vec3(0.0f, 0.0f, 1.0f);
	vertex->Tangent = glm::vec3(0.0f, 0.0f, 0.0f);
	vertex->Bitangent = glm::vec3(0.0f, 0.0f, 0.0f);
	vertices.push_back(*vertex);
}