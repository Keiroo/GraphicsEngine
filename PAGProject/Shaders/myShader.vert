#version 450

layout (location = 0) in vec3 vertexPosition;
layout (location = 1) in vec3 vertexColor;
layout (location = 2) in vec2 vertexTexture;
out vec3 position;
out vec3 color;
out vec2 texCoord;

uniform mat4 wvp;

void main()
{
	gl_Position = wvp * vec4(vertexPosition, 1.0f);

	position = vertexPosition;
	color = vertexColor;
	texCoord = vertexTexture;
}