#pragma once
#include "Headers.h"

#define TEXTURE_FILENAME "Textures/pikachuTexture.bmp"

class Texture
{
public:
	Texture();
	bool LoadTexture();
	void BindTexture();
	~Texture();

private:
	unsigned char* data;
	GLuint texture;
	GLint width, height, nrChannels;
};

