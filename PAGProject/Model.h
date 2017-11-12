#pragma once
#include "Headers.h"
#include "Mesh.h"
#include "Texture.h"

#include <vector>
#include <string>

struct sTexture;
class Mesh;

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

