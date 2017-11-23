#version 450 core

in vec2 texCoord;
out vec4 fragColor;

uniform sampler2D texture_diffuse1;
uniform sampler2D texture_diffuse2;
uniform sampler2D texture_diffuse3;
uniform sampler2D texture_specular1;
uniform sampler2D texture_specular2;

void main()
{
	fragColor = texture(texture_diffuse1, texCoord);
}