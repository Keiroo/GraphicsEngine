#pragma once
#include "Headers.h"
#include <string>
#include <fstream>

class Shader
{
public:
	GLuint programHandle, CPProgramHandle, myProgramHandle;

	Shader();
	bool LoadShaders();	
	void setFloat(const std::string & name, float value);
	void setInt(const std::string & name, int value);
	void ActivateShader();
	void ActivateCPShader();
	~Shader();	

private:
	bool LoadShader(std::string filename, GLint shaderType, GLuint & programHandle);	
};

std::string LoadFromFile(std::string fileName);

