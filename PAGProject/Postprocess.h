#pragma once
#include "Headers.h"
#include "Shader.h"
#include "Camera.h"

class Postprocess
{
public:
	bool hdr, isGamma;
	GLfloat exposure, gamma;
	bool stereo3d;

	Postprocess();
	void GenerateFramebuffer(Shader *shader);
	void BindFramebuffer();
	void BindFramebufferLeft();
	void BindFramebufferRight();
	void RenderToQuad(Shader * shader, Camera *camera);
	~Postprocess();

	

private:
	GLuint FBO, RBO, clrTexture, quadVAO, quadVBO;
	GLuint stereoFBO[2], stereoTexture[2], stereoRBO[2];

	GLfloat quadVertices[20] = {
		-1.0f,  1.0f, 0.0f,		0.0f, 1.0f,
		-1.0f, -1.0f, 0.0f,		0.0f, 0.0f,
		1.0f,  1.0f, 0.0f,		1.0f, 1.0f,
		1.0f, -1.0f, 0.0f,		1.0f, 0.0f,
	};
	void RenderQuad();
};

