#pragma once
#include "Headers.h"
#include "Shader.h"
#include "Texture.h"
#include "Camera.h"
#include <FreeImage.h>

class GrassGen
{
public:
	GLfloat fGrassPatchOffsetMin, fGrassPatchOffsetMax;
	GLint numGrassTriangles;
	GrassGen();
	void ResetTimer();
	void Render(Shader * shader, Camera * camera, float deltaTime, float fAlphaTest, float fAlphaMultiplier);
	
	~GrassGen();
private:
	GLuint grassVAO, grassVBO, grassTexture, grassSampler;
	std::vector<glm::vec3> grassVertices;
	clock_t tLastFrame;
	GLfloat fFrameInterval;

	Texture *texture;

	void GenVertices();
	void GenBuffers();
	int LoadTexture();
	void CreateFromData(BYTE * bData, int a_iWidth, int a_iHeight, int a_iBPP, GLenum format, bool bGenerateMipMaps);
};

