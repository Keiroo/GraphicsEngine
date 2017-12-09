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
	void setVec2(const std::string & name, const glm::vec2 & value);
	void setVec2(const std::string & name, float x, float y);
	void setVec3(const std::string & name, const glm::vec3 & value);
	void setVec3(const std::string & name, float x, float y, float z);
	void setVec4(const std::string & name, const glm::vec4 & value);
	void setVec4(const std::string & name, float x, float y, float z, float w);
	void setMat2(const std::string & name, const glm::mat2 & mat);
	void setMat3(const std::string & name, const glm::mat3 & mat);
	void setMat4(const std::string & name, const glm::mat4 & mat);
	void ActivateShader();
	void ActivateCPShader();
	~Shader();	

private:
	bool LoadShader(std::string filename, GLint shaderType, GLuint & programHandle);	
};

std::string LoadFromFile(std::string fileName);

