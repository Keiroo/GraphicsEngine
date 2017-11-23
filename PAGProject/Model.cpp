#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include "Model.h"

GLuint TextureFromFile(const char* path, std::string directory)
{
	unsigned char* data;
	std::string fileName = (std::string)path;
	fileName = directory + "/" + fileName;
	GLuint texture;
	GLint width, height, nrChannels;

	glGenTextures(1, &texture);
	stbi_set_flip_vertically_on_load(true);
	data = stbi_load(fileName.c_str(), &width, &height, &nrChannels, 0);
	if (!data)
	{
		fprintf(stderr, "Failed to load texture\n");
		return NULL;
	}

	GLenum format;
	if (nrChannels == 1)
		format = GL_RED;
	else if (nrChannels == 3)
		format = GL_RGB;
	else if (nrChannels == 4)
		format = GL_RGBA;

	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);

	stbi_image_free(data);
	return texture;
}

Model::Model(GLchar* path)
{
	//texture = new Texture();
	loadModel(path);
}

void Model::Draw(GLuint & programhandle)
{
	for (GLuint i = 0; i < meshes.size(); i++)
		meshes[i].Render(programhandle);
}

Model::~Model()
{
}

void Model::loadModel(std::string const &path)
{
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);
	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
	{
			std::string strerr = "Error: Assimp: " + (std::string)importer.GetErrorString();
			fprintf(stderr, strerr.c_str());
	}

	directory = path.substr(0, path.find_last_of('/'));

	processNode(scene->mRootNode, scene);
}

void Model::processNode(aiNode * node, const aiScene * scene)
{
	for (unsigned int i = 0; i < node->mNumMeshes; i++)
	{
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
		meshes.push_back(processMesh(mesh, scene));
	}
	for (unsigned int i = 0; i < node->mNumChildren; i++)
		processNode(node->mChildren[i], scene);
}

Mesh Model::processMesh(aiMesh * mesh, const aiScene * scene)
{
	std::vector<sVertex> vertices;
	std::vector<GLuint> indices;
	std::vector<sTexture> textures;

	// vertices
	for (GLuint i = 0; i < mesh->mNumVertices; i++)
	{
		sVertex vertex;
		glm::vec3 vec;

		// Position
		vec.x = mesh->mVertices[i].x;
		vec.y = mesh->mVertices[i].y;
		vec.z = mesh->mVertices[i].z;
		vertex.Position = vec;

		// Normals
		vec.x = mesh->mNormals[i].x;
		vec.y = mesh->mNormals[i].y;
		vec.z = mesh->mNormals[i].z;
		vertex.Normal = vec;

		// TexCoords
		if (mesh->mTextureCoords[0])
		{
			glm::vec2 vec2;
			vec2.x = mesh->mTextureCoords[0][i].x;
			vec2.y = mesh->mTextureCoords[0][i].y;
			vertex.TexCoords = vec2;
		}
		else
			vertex.TexCoords = glm::vec2(0.0f, 0.0f);

		// Tangent
		vec.x = mesh->mTangents[i].x;
		vec.y = mesh->mTangents[i].y;
		vec.z = mesh->mTangents[i].z;
		vertex.Tangent = vec;
		// Bitangent
		vec.x = mesh->mBitangents[i].x;
		vec.y = mesh->mBitangents[i].y;
		vec.z = mesh->mBitangents[i].z;
		vertex.Bitangent = vec;

		vertices.push_back(vertex);
	}

	// indices
	for (GLuint i = 0; i < mesh->mNumFaces; i++)
	{
		aiFace face = mesh->mFaces[i];
		for (GLuint j = 0; j < face.mNumIndices; j++)
			indices.push_back(face.mIndices[j]);
	}

	// materials	
	if (mesh->mMaterialIndex >= 0)
	{
		aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];

		std::vector<sTexture> diffuseMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
		textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());

		std::vector<sTexture> specularMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
		textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());

		std::vector<sTexture> normalMaps = loadMaterialTextures(material, aiTextureType_HEIGHT, "texture_normal");
		textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());

		std::vector<sTexture> heightMaps = loadMaterialTextures(material, aiTextureType_AMBIENT, "texture_height");
		textures.insert(textures.end(), heightMaps.begin(), heightMaps.end());
	}

	return Mesh(vertices, indices, textures);
}

std::vector<sTexture> Model::loadMaterialTextures(aiMaterial * material, aiTextureType type, std::string typeName)
{
	std::vector<sTexture> textures;

	for (GLuint i = 0; i < material->GetTextureCount(type); i++)
	{
		aiString str;
		bool skip = false;
		material->GetTexture(type, i, &str);

		for (GLuint j = 0; j < texturesLoaded.size(); j++)
		{
			if (std::strcmp(texturesLoaded[j].path.C_Str(), str.C_Str()) == 0)
			{
				textures.push_back(texturesLoaded[j]);
				skip = true;
				break;
			}
		}
		if (!skip)
		{
			sTexture texture;
			//texture.id = this->texture->TextureFromFile(str.C_Str(), directory);
			texture.id = TextureFromFile(str.C_Str(), directory);
			texture.type = typeName;
			texture.path = str;
			textures.push_back(texture);
			texturesLoaded.push_back(texture);
		}
	}
	return textures;
}
