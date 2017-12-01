#include "ColorPick.h"



ColorPick::ColorPick()
{
	glGenFramebuffers(1, &FBO);
	glBindFramebuffer(GL_FRAMEBUFFER, FBO);

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, SCREEN_WIDTH, SCREEN_HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
	

	glGenRenderbuffers(1, &RBO);
	glBindRenderbuffer(GL_RENDERBUFFER, RBO);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, SCREEN_WIDTH, SCREEN_HEIGHT);
	glBindRenderbuffer(GL_RENDERBUFFER, 0);

	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture, 0);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, RBO);

	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
	{
		fprintf(stderr, "Error: Framebuffer: Framebuffer is not complete.");
	}

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void ColorPick::PickModel(GLFWwindow* window)
{
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	unsigned char res[4];
	glReadPixels(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, res);
	int pickedID = res[0] + res[1] * 256 + res[2] * 256 * 256;

	if (pickedID == 0x00ffffff) 
	{
		modelPicked = -1;
	}
	else
	{
		modelPicked = pickedID;
	}




	/*GLint viewport[4];
	unsigned char res[4];

	glGetIntegerv(GL_VIEWPORT, viewport);

	glfwGetCursorPos(window, &x, &y);

	glReadPixels((GLint)x, viewport[3] - (GLint)y, 1, 1, GL_RGBA, GL_INT, &res);

	switch (res[0])
	{
	case 0: modelPicked = 0; break;
	case 1: modelPicked = 1; break;
	case 2: modelPicked = 2; break;
	case 3: modelPicked = 3; break;
	default: modelPicked = -1; break;
	}*/
}


ColorPick::~ColorPick()
{
}
