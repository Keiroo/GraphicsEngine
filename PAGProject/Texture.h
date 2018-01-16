#pragma once
#include "Headers.h"

class Texture
{
public:
	Texture();
	GLuint TextureFromFile(const char * path, const std::string & directory, bool gamma);
	void ActivateTexture(GLuint texture);
	~Texture();

private:
};

