#include "Shader.h"


Shader::Shader()
{
}

Shader::~Shader()
{
}


std::string Shader::LoadFromFile(std::string fileName)
{
	std::string text, line;
	std::ifstream file(fileName);

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