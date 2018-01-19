#version 450 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoords;

uniform mat4 prevWVP;
uniform vec3 currPos;

out vec2 TexCoords;
out vec2 blurVec;

void main()
{
	vec4 previous = prevWVP * vec4(currPos, 1.0);
	previous.xyz /= previous.w;
	previous.xy = previous.xy * 0.5 + 0.5;

	blurVec = previous.xy - aTexCoords;
	
    TexCoords = aTexCoords;
    gl_Position = vec4(aPos, 1.0);
}