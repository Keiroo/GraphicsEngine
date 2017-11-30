#pragma once
#include "Headers.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "Transform.h"
#include <string>
#include <vector>



class Model
{
public:
	std::vector<sTexture> textures_loaded;
	std::vector<Mesh> meshes;
	std::vector<Model*> nodes;
	std::string directory;
	static GLuint modelsRendered;

	Model(std::string const &path, bool gamma = false);
	void Render(Shader* shader);
	void SetNode(Model * node);
	void Reset();
	void Scale(glm::mat4 parent, float x, float y, float z);
	void Rotate(glm::mat4 parent, float angle, glm::vec3 axis);
	void Translate(glm::mat4 parent, glm::vec3 direction);
	~Model();

private:
	Texture* texture;
	Transform transform;
	GLuint colorCodeLoc;

	void loadModel(std::string const &path);
	void processNode(aiNode *node, const aiScene *scene);
	Mesh processMesh(aiMesh *mesh, const aiScene *scene);
	std::vector<sTexture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
};

