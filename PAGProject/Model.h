#pragma once
#include "Headers.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Mesh.h"
#include "Texture.h"

#include <vector>
#include <string>

class Model
{
public:
	Model(GLchar* path);
	void Draw(GLuint& programhandle);
	~Model();

private:
	Texture* texture;
	std::vector<Mesh> meshes;
	std::vector<sTexture> texturesLoaded;
	std::string directory;

	void loadModel(std::string path);
	void processNode(aiNode* node, const aiScene* scene);
	Mesh processMesh(aiMesh* mesh, const aiScene* scene);
	std::vector<sTexture> loadMaterialTextures(aiMaterial* material, aiTextureType type, std::string typeName);
};

