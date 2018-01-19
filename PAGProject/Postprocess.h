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

	Postprocess();
	void GenerateFramebuffer(Shader *shader);
	void BindFramebuffer();
	void RenderToQuad(Shader * shader, Camera *camera);
	~Postprocess();

private:
	GLuint FBO, RBO, clrTexture, quadVAO, quadVBO;
	glm::mat4 prevWVP;

	GLfloat quadVertices[20] = {
		-1.0f,  1.0f, 0.0f,		0.0f, 1.0f,
		-1.0f, -1.0f, 0.0f,		0.0f, 0.0f,
		1.0f,  1.0f, 0.0f,		1.0f, 1.0f,
		1.0f, -1.0f, 0.0f,		1.0f, 0.0f,
	};

};

