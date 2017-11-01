#include "Transform.h"



Transform::Transform()
{
	trans = glm::mat4(1.0f);
}

void Transform::RotateLocal(GLuint& programHandle, float deltaTime)
{
	trans = glm::rotate(trans, deltaTime * glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));

	transformLoc = glGetUniformLocation(programHandle, "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
}


Transform::~Transform()
{
}
