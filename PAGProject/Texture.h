#pragma once
#include "Headers.h"

class Texture
{
public:
	Texture();
	bool LoadAllTextures(GLuint& programHandle);
	
	void BindTextures();
	~Texture();

private:
	GLuint texture[2];
	GLint width, height, nrChannels;

	bool LoadTexture(GLuint &texture, char* filename);
};

