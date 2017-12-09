#version 450 core

layout (location = 0) in vec3 vertexPosition;
layout (location = 2) in vec2 vertexTexture;
out vec2 texCoord;

//uniform mat4 wvp;
uniform mat4 transform;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	//gl_Position = wvp * transform * vec4(vertexPosition, 1.0f);
	gl_Position = projection * view * transform * vec4(vertexPosition, 1.0f);






	texCoord = vertexTexture;
}