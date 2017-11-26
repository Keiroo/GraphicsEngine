#pragma once
#include "Headers.h"

class Transform
{
public:
	Transform();
	void SetParent(glm::mat4 parent);
	glm::mat4 GetMatrix();
	void Scale(float x, float y, float z);
	void Rotate(float angle, glm::vec3 axis);
	void RotateLocal(float angle, float speed);
	void Translate(glm::vec3 direction);
	void Update(GLuint & programHandle);
	void Reset();
	~Transform();

private:
	glm::mat4 trans;
	GLuint transformLoc;

};

