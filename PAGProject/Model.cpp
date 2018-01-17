#include "Model.h"
#include <algorithm>

GLuint Model::modelsRendered = 0;

Model::Model(std::string const & path, bool gamma)
{
	parent = NULL;
	texture = new Texture();
	loadModel(path);
}

void Model::Render(Shader* shader)
{
	transform.Update(shader->programHandle);
	modelsRendered++;
	if (shader->programHandle == shader->CPProgramHandle)
	{
		
		int r = (modelsRendered & 0x000000FF) >> 0;
		int g = (modelsRendered & 0x0000FF00) >> 8;
		int b = (modelsRendered & 0x00FF0000) >> 16;

		colorCodeLoc = glGetUniformLocation(shader->programHandle, "colorCode");
		glUniform4f(colorCodeLoc, r / 255.0f, g / 255.0f, b / 255.0f, 1.0f);
	}	

	for (GLuint i = 0; i < meshes.size(); i++)
		meshes[i].Render(shader);

	if (nodes.size() > 0)
		for each (Model* node in nodes)
			node->Render(shader);
}

void Model::RenderRef(Shader* shader, Skybox *skybox)
{
	transform.Update(shader->programHandle);
	modelsRendered++;
	
	for (GLuint i = 0; i < meshes.size(); i++)
		meshes[i].RenderRef(shader, skybox);
}

void Model::SetParent(Model* parent)
{
	this->parent = parent;
	if (std::find(parent->nodes.begin(), parent->nodes.end(), this) == parent->nodes.end())
		parent->SetNode(this);	
}

void Model::SetNode(Model* node)
{
	if (std::find(nodes.begin(), nodes.end(), node) == nodes.end())
		nodes.push_back(node);
	node->SetParent(this);
}

void Model::Reset()
{
	transform.Reset();
	for each (Model* node in nodes)
		node->Reset();
}

void Model::Scale(float x, float y, float z)
{
	if (parent == NULL)
		transform.SetParent(glm::mat4(1.0f));
	else
		transform.SetParent(parent->transform.GetMatrix());
	
	transform.Scale(x, y, z);

	if (nodes.size() > 0)
		for (short i = 0; i < nodes.size(); i++)
		{
			nodes[i]->Reset();
			nodes[i]->Scale(x, y, z);
		}
}

void Model::Rotate(float angle, glm::vec3 axis)
{
	if (parent == NULL)
		transform.SetParent(glm::mat4(1.0f));
	else
		transform.SetParent(parent->transform.GetMatrix());

	transform.Rotate(angle, axis);

	if (nodes.size() > 0)
		for (short i = 0; i < nodes.size(); i++)
		{
			nodes[i]->Reset();
			nodes[i]->Rotate(angle, axis);
		}
}

void Model::Translate(glm::vec3 direction)
{
	if (parent == NULL)
		transform.SetParent(glm::mat4(1.0f));
	else
		transform.SetParent(parent->transform.GetMatrix());

	transform.Translate(direction);

	if (nodes.size() > 0)
		for (short i = 0; i < nodes.size(); i++)
		{
			nodes[i]->Reset();
			nodes[i]->Translate(direction);
		}
			
}

Model::~Model()
{
}

void Model::loadModel(std::string const & path)
{
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);
	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
	{
		fprintf(stderr, importer.GetErrorString());
		return;
	}

	directory = path.substr(0, path.find_last_of('/'));

	processNode(scene->mRootNode, scene);
}

void Model::processNode(aiNode * node, const aiScene * scene)
{
	for (GLuint i = 0; i < node->mNumMeshes; i++)
	{
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
		meshes.push_back(processMesh(mesh, scene));
	}
	for (GLuint i = 0; i < node->mNumChildren; i++)
	{
		processNode(node->mChildren[i], scene);
	}
}

Mesh Model::processMesh(aiMesh * mesh, const aiScene * scene)
{
	std::vector<sVertex> vertices;
	std::vector<GLuint> indices;
	std::vector<sTexture> textures;


	for (unsigned int i = 0; i < mesh->mNumVertices; i++)
	{
		sVertex vertex;
		glm::vec3 vector;
		vector.x = mesh->mVertices[i].x;
		vector.y = mesh->mVertices[i].y;
		vector.z = mesh->mVertices[i].z;
		vertex.Position = vector;

		vector.x = mesh->mNormals[i].x;
		vector.y = mesh->mNormals[i].y;
		vector.z = mesh->mNormals[i].z;
		vertex.Normal = vector;

		if (mesh->mTextureCoords[0])
		{
			glm::vec2 vec;
			vec.x = mesh->mTextureCoords[0][i].x;
			vec.y = mesh->mTextureCoords[0][i].y;
			vertex.TexCoords = vec;
		}
		else
			vertex.TexCoords = glm::vec2(0.0f, 0.0f);

		vector.x = mesh->mTangents[i].x;
		vector.y = mesh->mTangents[i].y;
		vector.z = mesh->mTangents[i].z;
		vertex.Tangent = vector;
		vector.x = mesh->mBitangents[i].x;
		vector.y = mesh->mBitangents[i].y;
		vector.z = mesh->mBitangents[i].z;
		vertex.Bitangent = vector;

		vertices.push_back(vertex);
	}
	for (unsigned int i = 0; i < mesh->mNumFaces; i++)
	{
		aiFace face = mesh->mFaces[i];
		for (unsigned int j = 0; j < face.mNumIndices; j++)
			indices.push_back(face.mIndices[j]);
	}
	aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];

	std::vector<sTexture> diffuseMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
	textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
	std::vector<sTexture> specularMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
	textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
	std::vector<sTexture> normalMaps = loadMaterialTextures(material, aiTextureType_HEIGHT, "texture_normal");
	textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());
	std::vector<sTexture> heightMaps = loadMaterialTextures(material, aiTextureType_AMBIENT, "texture_height");
	textures.insert(textures.end(), heightMaps.begin(), heightMaps.end());

	return Mesh(vertices, indices, textures);
}

std::vector<sTexture> Model::loadMaterialTextures(aiMaterial * mat, aiTextureType type, std::string typeName)
{
	std::vector<sTexture> textures;
	for (unsigned int i = 0; i < mat->GetTextureCount(type); i++)
	{
		aiString str;
		mat->GetTexture(type, i, &str);
		bool skip = false;
		for (unsigned int j = 0; j < textures_loaded.size(); j++)
		{
			if (std::strcmp(textures_loaded[j].path.C_Str(), str.C_Str()) == 0)
			{
				textures.push_back(textures_loaded[j]);
				break;
			}
		}
		if (!skip)
		{
			sTexture texture;
			texture.id = this->texture->TextureFromFile(str.C_Str(), this->directory, false);
			texture.type = typeName;
			texture.path = str;
			textures.push_back(texture);
			textures_loaded.push_back(texture);
		}
	}
	return textures;
}