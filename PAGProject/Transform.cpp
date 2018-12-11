#include "Transform.h"



Transform::Transform()
{
	trans = glm::mat4(1.0f);
}

void Transform::SetParent(glm::mat4 parent)
{
	trans = parent * trans;
}

glm::mat4 Transform::GetMatrix()
{
	return trans;
}

void Transform::Scale(float x, float y, float z)
{
	trans = glm::scale(trans, glm::vec3(x, y, z));
}

void Transform::Rotate(float angle, glm::vec3 axis)
{
	trans = glm::rotate(trans, glm::radians(angle), axis);
}

void Transform::RotateLocal(float angle, float speed)
{
	trans = glm::rotate(trans, speed * angle, glm::vec3(0.0f, 1.0f, 0.0f));
}

void Transform::Translate(glm::vec3 coords)
{
	trans = glm::translate(trans, coords);
}

void Transform::Update(GLuint& programHandle)
{
	transformLoc = glGetUniformLocation(programHandle, "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
}

void Transform::Reset()
{
	trans = glm::mat4(1.0f);
}

Transform::~Transform()
{
}
