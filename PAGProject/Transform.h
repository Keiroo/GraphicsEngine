#pragma once
#include "Headers.h"

class Transform
{
public:
	Transform();
	void Scale(float x, float y, float z);
	void RotateLocal(float angle, float speed);
	void Translate(glm::vec3 direction);
	void Update(GLuint & programHandle);
	void Reset();
	~Transform();

private:
	glm::mat4 trans;
	GLuint transformLoc;

};

