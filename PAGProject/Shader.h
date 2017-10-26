#pragma once
#include "Headers.h"
#include <string>
#include <fstream>

#define VERTEX_SHADER_FILENAME "Shaders/myShader.vert"
#define FRAGMENT_SHADER_FILENAME "Shaders/myShader.frag"

class Shader
{
public:
	GLuint programHandle;

	Shader();
	bool LoadShaders();	
	void ActivateShader();
	~Shader();	

private:
	bool LoadShader(std::string filename, GLint shaderType, GLuint & programHandle);
	
};

std::string LoadFromFile(std::string fileName);

