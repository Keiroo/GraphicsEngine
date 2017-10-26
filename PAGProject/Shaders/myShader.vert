#version 450

layout (location = 0) in vec3 vertexPosition;
layout (location = 1) in vec3 vertexColor;
layout (location = 2) in vec2 vertexTexture;
out vec3 color;
out vec2 texCoord;

void main()
{
	gl_Position = vec4(vertexPosition, 1.0f);
	color = vertexColor;
	texCoord = vertexTexture;
}