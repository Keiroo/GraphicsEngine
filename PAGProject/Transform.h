#pragma once
#include "Headers.h"

class Transform
{
public:
	Transform();
	void RotateLocal(GLuint& programHandle, float deltaTime);
	~Transform();

private:
	glm::mat4 trans;
	GLuint transformLoc;

};

