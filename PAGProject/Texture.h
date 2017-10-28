#pragma once
#include "Headers.h"

#define TEXTURE_FILENAME "Textures/pikachuTexture.bmp"
#define TEXTURE_FILENAME_2 "Textures/brickTexture.jpg"

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

