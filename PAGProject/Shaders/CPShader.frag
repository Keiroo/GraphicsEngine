#version 450 core

out vec4 fragColor;

uniform vec4 colorCode;

void main()
{
	fragColor = colorCode;
};