#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include "Texture.h"



Texture::Texture()
{
}

bool Texture::LoadTexture()
{
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	stbi_set_flip_vertically_on_load(true);
	data = stbi_load(TEXTURE_FILENAME, &width, &height, &nrChannels, 0);
	if (!data)
	{
		fprintf(stderr, "Failed to load texture\n");
		return false;
	}

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	stbi_image_free(data);

	return true;
}

void Texture::BindTexture()
{
	glBindTexture(GL_TEXTURE_2D, texture);
}


Texture::~Texture()
{
}
