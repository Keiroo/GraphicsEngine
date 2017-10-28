#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include "Texture.h"



Texture::Texture()
{
}

bool Texture::LoadAllTextures(GLuint& programHandle)
{
	glGenTextures(2, texture);
	if (!LoadTexture(texture[0], TEXTURE_FILENAME))
	{
		return false;
	}	
	if (!LoadTexture(texture[1], TEXTURE_FILENAME_2))
	{
		return false;
	}

	glUniform1i(glGetUniformLocation(programHandle, "myTexture1"), 0);
	glUniform1i(glGetUniformLocation(programHandle, "myTexture2"), 1);

	return true;
}

bool Texture::LoadTexture(GLuint &texture, char* filename)
{
	unsigned char* data;

	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	stbi_set_flip_vertically_on_load(true);
	data = stbi_load(filename, &width, &height, &nrChannels, 0);
	if (!data)
	{
		fprintf(stderr, "Failed to load texture\n");
		return false;
	}

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);
	stbi_image_free(data);

	return true;
}

void Texture::BindTextures()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
}

Texture::~Texture()
{
}
