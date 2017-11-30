#version 450 core

out vec4 fragColor;

uniform int colorCode;

void main()
{
	fragColor = vec4(colorCode/255.0f, 0.0f, 0.0f, 0.0f);
};