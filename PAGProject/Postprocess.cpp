#include "Postprocess.h"

Postprocess::Postprocess()
{
	hdr = true;
	exposure = 1.0f;
	quadVAO = 0;
}

void Postprocess::GenerateFramebuffer(Shader *shader)
{
	glGenFramebuffers(1, &FBO);
	glGenTextures(1, &clrTexture);
	glGenRenderbuffers(1, &RBO);

	glBindTexture(GL_TEXTURE_2D, clrTexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16F, SCREEN_WIDTH, SCREEN_HEIGHT, 0, GL_RGBA, GL_FLOAT, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBindRenderbuffer(GL_RENDERBUFFER, RBO);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, SCREEN_WIDTH, SCREEN_HEIGHT);

	glBindFramebuffer(GL_FRAMEBUFFER, FBO);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, clrTexture, 0);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, RBO);

	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		fprintf(stderr, "Framebuffer error!\n");
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	shader->ActivateHDRShader();
	shader->setInt("hdrBuffer", 0);
	shader->ActivateShader();
}

void Postprocess::BindFramebuffer()
{
	glBindFramebuffer(GL_FRAMEBUFFER, FBO);
}

void Postprocess::RenderToQuad(Shader *shader)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	shader->ActivateHDRShader();
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, clrTexture);
	shader->setInt("hdr", hdr);
	shader->setFloat("exposure", exposure);

	if (quadVAO == 0)
	{
		glGenVertexArrays(1, &quadVAO);
		glGenBuffers(1, &quadVBO);
		glBindVertexArray(quadVAO);
		glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	}
	glBindVertexArray(quadVAO);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glBindVertexArray(0);
}


Postprocess::~Postprocess()
{
}
