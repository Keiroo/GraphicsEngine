#version 450 core

layout (location = 0) in vec3 vertexPosition;
layout (location = 1) in vec3 vertexNormal;
layout (location = 2) in vec2 vertexTexture;

out vec3 FragPos;
out vec3 Normal;
out vec2 texCoord;

//uniform mat4 wvp;
uniform mat4 transform;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	FragPos = vec3(transform * vec4(vertexPosition, 1.0));
    Normal = mat3(transpose(inverse(transform))) * vertexNormal;  
	texCoord = vertexTexture;


	gl_Position = projection * view * transform * vec4(vertexPosition, 1.0f);	
}