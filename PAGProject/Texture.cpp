#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include "Texture.h"

Texture::Texture()
{
}

bool Texture::LoadAllTextures(GLuint& programHandle)
{
	glGenTextures(3, texture);
	if (!LoadTexture(texture[0], TEXTURE0_FILENAME))
	{
		return false;
	}

	if (!LoadTexture(texture[1], TEXTURE1_FILENAME))
	{
		return false;
	}

	if (!LoadTexture(texture[2], TEXTURE2_FILENAME))
	{
		return false;
	}

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glUniform1i(glGetUniformLocation(programHandle, "myTexture"), 0);
	return true;
}

void Texture::BindTextures(GLuint& programHandle, short texNumber)
{
	switch (texNumber)
	{
	case 0:
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		break;

	case 1:
		glBindTexture(GL_TEXTURE_2D, texture[1]);
		break;

	case 2:
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		break;

	default:
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		break;
	}
}

bool Texture::LoadTexture(GLuint &texture, char* filename)
{
	unsigned char* data;
	GLfloat borderColor[] = { 1.0f, 1.0f, 0.0f, 1.0f };

	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
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

Texture::~Texture()
{
}
