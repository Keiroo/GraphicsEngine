#pragma once
#include "Headers.h"
#include <vector>

using namespace std;

class Texture
{
public:
	Texture();
	GLuint TextureFromFile(const char * path, const std::string & directory, bool gamma);
	void ActivateTexture(GLuint texture);
	GLuint loadCubemap(vector<string> faces);
	~Texture();

private:
};

