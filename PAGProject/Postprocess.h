#pragma once
#include "Headers.h"
#include "Shader.h"
#include "Camera.h"

class Postprocess
{
public:
	bool hdr, isGamma;
	GLfloat exposure, gamma;

	bool motionBlur;
	GLint motionBlurFrames;

	Postprocess();
	void GenerateFramebuffer(Shader *shader);
	void BindFramebuffer();
	void RenderToQuad(Shader * shader);
	~Postprocess();

private:
	GLuint FBO, RBO, clrTexture, quadVAO, quadVBO;
	GLfloat quadVertices[20] = {
		-1.0f,  1.0f, 0.0f,		0.0f, 1.0f,
		-1.0f, -1.0f, 0.0f,		0.0f, 0.0f,
		1.0f,  1.0f, 0.0f,		1.0f, 1.0f,
		1.0f, -1.0f, 0.0f,		1.0f, 0.0f,
	};

};

