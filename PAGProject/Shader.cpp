#include "Shader.h"


Shader::Shader()
{
}

bool Shader::LoadShaders()
{
	myProgramHandle = glCreateProgram();
	if (!LoadShader(VERTEX_SHADER_FILENAME, GL_VERTEX_SHADER, myProgramHandle))
	{
		return false;
	}
	if (!LoadShader(FRAGMENT_SHADER_FILENAME, GL_FRAGMENT_SHADER, myProgramHandle))
	{
		return false;
	}

	CPProgramHandle = glCreateProgram();
	if (!LoadShader(VERTEX_SHADER_FILENAME, GL_VERTEX_SHADER, CPProgramHandle))
	{
		return false;
	}
	if (!LoadShader(CP_FRAGMENT_SHADER_FILENAME, GL_FRAGMENT_SHADER, CPProgramHandle))
	{
		return false;
	}

	skyboxProgramHandle = glCreateProgram();
	if (!LoadShader(SKYBOX_VERTEX_SHADER_FILENAME, GL_VERTEX_SHADER, skyboxProgramHandle))
	{
		return false;
	}
	if (!LoadShader(SKYBOX_FRAGMENT_SHADER_FILENAME, GL_FRAGMENT_SHADER, skyboxProgramHandle))
	{
		return false;
	}

	refProgramHandle = glCreateProgram();
	if (!LoadShader(REF_VERTEX_SHADER_FILENAME, GL_VERTEX_SHADER, refProgramHandle))
	{
		return false;
	}
	if (!LoadShader(REF_FRAGMENT_SHADER_FILENAME, GL_FRAGMENT_SHADER, refProgramHandle))
	{
		return false;
	}

	programHandle = myProgramHandle;
	glUseProgram(programHandle);
	return true;
}

void Shader::ActivateShader()
{
	programHandle = myProgramHandle;
	glUseProgram(programHandle);
}

void Shader::ActivateCPShader()
{
	programHandle = CPProgramHandle;
	glUseProgram(programHandle);
}

void Shader::ActivateSkyboxShader()
{
	programHandle = skyboxProgramHandle;
	glUseProgram(programHandle);
}

void Shader::ActivateRefShader()
{
	programHandle = refProgramHandle;
	glUseProgram(programHandle);
}

bool Shader::LoadShader(std::string filename, GLint shaderType, GLuint& programHandle)
{
	GLint res;
	GLchar log[512];
	GLuint shaderObject;
	std::string shaderString;

	shaderObject = glCreateShader(shaderType);
	shaderString = LoadFromFile(filename);
	const GLchar* shaderCode = shaderString.c_str();
	const GLint shaderSize = shaderString.size();

	glShaderSource(shaderObject, 1, &shaderCode, &shaderSize);
	glCompileShader(shaderObject);
	glGetShaderiv(shaderObject, GL_COMPILE_STATUS, &res);
	if (!res)
	{
		glGetShaderInfoLog(shaderObject, 512, NULL, log);
		fprintf(stderr, "Failed to compile shader\n");
		fprintf(stderr, log);
		return false;
	}
	glAttachShader(programHandle, shaderObject);
	glLinkProgram(programHandle);
	
	glGetProgramiv(programHandle, GL_LINK_STATUS, &res);
	if (!res)
	{
		glGetProgramInfoLog(shaderObject, 512, NULL, log);
		fprintf(stderr, "Failed to link program\n");
		fprintf(stderr, log);
		return false;
	}
	glDeleteShader(shaderObject);

	return true;
}

Shader::~Shader()
{
}

std::string LoadFromFile(std::string filename)
{
	std::string text, line;
	std::ifstream file(filename);

	if (!file)
	{
		file.close();
		return NULL;
	}
	else
	{
		while (!file.eof())
		{
			getline(file, line);
			text.append(line + "\n");
		}
		file.close();
		return text;
	}
}