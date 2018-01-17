#version 450 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

out vec3 Normal;
out vec3 Position;

uniform mat4 wvp;
uniform mat4 transform;

void main()
{
    
    Position = vec3(transform * vec4(aPos, 1.0));
	Normal = mat3(transpose(inverse(transform))) * aNormal;

    gl_Position = wvp * vec4(Position, 1.0);
}