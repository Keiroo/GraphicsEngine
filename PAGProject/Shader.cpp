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

	lightProgramHandle = glCreateProgram();
	if (!LoadShader(LIGHT_VERTEX_SHADER_FILENAME, GL_VERTEX_SHADER, lightProgramHandle))
	{
		return false;
	}
	if (!LoadShader(LIGHT_FRAGMENT_SHADER_FILENAME, GL_FRAGMENT_SHADER, lightProgramHandle))
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

void Shader::ActivateLightShader()
{
	programHandle = lightProgramHandle;
	glUseProgram(programHandle);
}

void Shader::setFloat(const std::string &name, float value)
{
	glUniform1f(glGetUniformLocation(programHandle, name.c_str()), value);
}
void Shader::setInt(const std::string &name, int value)
{
	glUniform1i(glGetUniformLocation(programHandle, name.c_str()), value);
}
// ------------------------------------------------------------------------
void Shader::setVec2(const std::string &name, const glm::vec2 &value)
{
	glUniform2fv(glGetUniformLocation(programHandle, name.c_str()), 1, &value[0]);
}
void Shader::setVec2(const std::string &name, float x, float y)
{
	glUniform2f(glGetUniformLocation(programHandle, name.c_str()), x, y);
}
// ------------------------------------------------------------------------
void Shader::setVec3(const std::string &name, const glm::vec3 &value)
{
	glUniform3fv(glGetUniformLocation(programHandle, name.c_str()), 1, &value[0]);
}
void Shader::setVec3(const std::string &name, float x, float y, float z)
{
	glUniform3f(glGetUniformLocation(programHandle, name.c_str()), x, y, z);
}
// ------------------------------------------------------------------------
void Shader::setVec4(const std::string &name, const glm::vec4 &value)
{
	glUniform4fv(glGetUniformLocation(programHandle, name.c_str()), 1, &value[0]);
}
void Shader::setVec4(const std::string &name, float x, float y, float z, float w)
{
	glUniform4f(glGetUniformLocation(programHandle, name.c_str()), x, y, z, w);
}
// ------------------------------------------------------------------------
void Shader::setMat2(const std::string &name, const glm::mat2 &mat)
{
	glUniformMatrix2fv(glGetUniformLocation(programHandle, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
// ------------------------------------------------------------------------
void Shader::setMat3(const std::string &name, const glm::mat3 &mat)
{
	glUniformMatrix3fv(glGetUniformLocation(programHandle, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
// ------------------------------------------------------------------------
void Shader::setMat4(const std::string &name, const glm::mat4 &mat)
{
	glUniformMatrix4fv(glGetUniformLocation(programHandle, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

Shader::~Shader()
{
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