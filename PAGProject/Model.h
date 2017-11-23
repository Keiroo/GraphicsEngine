#pragma once
#include "Headers.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include <string>
#include <vector>



class Model
{
public:
	std::vector<sTexture> textures_loaded;
	std::vector<Mesh> meshes;
	std::string directory;

	Model(std::string const &path, bool gamma = false);
	void Render(Shader* shader);
	~Model();

private:
	Texture* texture;
	void loadModel(std::string const &path);
	void processNode(aiNode *node, const aiScene *scene);
	Mesh processMesh(aiMesh *mesh, const aiScene *scene);
	std::vector<sTexture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
};

