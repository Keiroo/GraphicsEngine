#pragma once
#include "Headers.h"
#include <string>

class Texture
{
public:
	Texture();
	/*bool LoadAllTextures(GLuint& programHandle);
	void BindTextures(GLuint& programHandle, short texNumber);*/
	GLuint TextureFromFile(const char * path, std::string directory);
	~Texture();

private:
	//GLuint texture;
	GLint width, height, nrChannels;

	bool LoadTexture(GLuint &texture, char* filename);
	
};

