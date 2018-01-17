#pragma once
#include "Headers.h"
#include "Shader.h"
#include "Camera.h"
#include "Texture.h"
#include <vector>

using namespace std;

class Skybox
{
public:
	GLuint cubemapTexture;
	Skybox();
	void Render(Shader * shader, Camera *camera);
	void BindTexture();
	~Skybox();
	
private:
	vector<std::string> faces {
		"Textures/Skybox/posx.jpg",
		"Textures/Skybox/negx.jpg",
		"Textures/Skybox/posy.jpg",
		"Textures/Skybox/negy.jpg",
		"Textures/Skybox/posz.jpg",
		"Textures/Skybox/negz.jpg"
	};

	/*vector<std::string> faces {
	"Textures/Skybox2/right.jpg",
	"Textures/Skybox2/left.jpg",
	"Textures/Skybox2/top.jpg",
	"Textures/Skybox2/bottom.jpg",
	"Textures/Skybox2/back.jpg",
	"Textures/Skybox2/front.jpg"
	};	*/	

	GLfloat skyboxVertices[108] = {
		// positions          
		-1.0f,  1.0f, -1.0f,
		-1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,

		-1.0f, -1.0f,  1.0f,
		-1.0f, -1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f,  1.0f,
		-1.0f, -1.0f,  1.0f,

		1.0f, -1.0f, -1.0f,
		1.0f, -1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f,  1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,

		-1.0f, -1.0f,  1.0f,
		-1.0f,  1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f, -1.0f,  1.0f,
		-1.0f, -1.0f,  1.0f,

		-1.0f,  1.0f, -1.0f,
		1.0f,  1.0f, -1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		-1.0f,  1.0f,  1.0f,
		-1.0f,  1.0f, -1.0f,

		-1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f,  1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f,  1.0f,
		1.0f, -1.0f,  1.0f
	};
	GLuint skyboxVAO, skyboxVBO;

	Texture *texture;

	void LoadBuffers();
};

