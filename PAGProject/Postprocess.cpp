#include "Postprocess.h"

Postprocess::Postprocess()
{
	hdr = true;
	exposure = 1.0f;
	quadVAO = 0;
	gamma = 2.2f;
	isGamma = true;
	stereo3d = false;
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

	glGenFramebuffers(2, stereoFBO);
	glGenTextures(2, stereoTexture);
	glGenRenderbuffers(2, stereoRBO);
	for (int i = 0; i < 2; i++)
	{
		glBindFramebuffer(GL_FRAMEBUFFER, stereoFBO[i]);

		glBindTexture(GL_TEXTURE_2D, stereoTexture[i]);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16F, SCREEN_WIDTH, SCREEN_HEIGHT, 0, GL_RGBA, GL_FLOAT, NULL);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glBindRenderbuffer(GL_RENDERBUFFER, stereoRBO[i]);
		glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, SCREEN_WIDTH, SCREEN_HEIGHT);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, stereoTexture[i], 0);
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, stereoRBO[i]);

		if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
			fprintf(stderr, "Framebuffer error!\n");
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

}

void Postprocess::BindFramebuffer()
{
	glBindFramebuffer(GL_FRAMEBUFFER, FBO);
}

void Postprocess::BindFramebufferLeft()
{
	glBindFramebuffer(GL_FRAMEBUFFER, stereoFBO[0]);
}

void Postprocess::BindFramebufferRight()
{
	glBindFramebuffer(GL_FRAMEBUFFER, stereoFBO[1]);
}

void Postprocess::RenderToQuad(Shader *shader, Camera *camera)
{
	BindFramebuffer();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	shader->Activate3DShader();
	shader->setInt("leftEyeTexture", 0);
	shader->setInt("leftEyeTexture", 1);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, stereoTexture[0]);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, stereoTexture[1]);
	RenderQuad();


	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	shader->ActivateHDRShader();
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, clrTexture);
	shader->setInt("hdr", hdr);
	shader->setFloat("exposure", exposure);
	shader->setInt("isGamma", isGamma);
	shader->setFloat("gamma", gamma);
	
	RenderQuad();
}


Postprocess::~Postprocess()
{
}

void Postprocess::RenderQuad()
{
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
