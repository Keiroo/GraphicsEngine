#pragma once
#include <string>
#include <fstream>

class Shader
{
public:
	Shader();
	~Shader();

	std::string LoadFromFile(std::string fileName);

private:

};

