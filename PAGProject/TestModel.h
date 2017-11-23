#pragma once
#include "Headers.h"
#include "Mesh.h"
#include "Texture.h"
#include "Shader.h"
#include <vector>
#include <string>

using namespace std;

class TestModel
{
public:
	TestModel();
	void Render(Shader* shader);
	~TestModel();
private:
	Mesh* mesh;
	Texture* texture;

	vector<sVertex> vertices;
	vector<GLuint> indices;
	vector<sTexture> textures;

	void LoadVertices(sVertex* vertex);
};

