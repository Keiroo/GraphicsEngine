#version 450 core
uniform sampler2D leftEyeTexture;
uniform sampler2D rightEyeTexture;
 
in vec2 TexCoords;
 
out vec4 vFragColour;
 
void main(void)
{
	vec4 leftFrag = texture(leftEyeTexture, TexCoords);
	leftFrag = vec4(1.0, leftFrag.g, leftFrag.b, 1.0); // Left eye is full red and actual green and blue
	
	vec4 rightFrag = texture(rightEyeTexture, TexCoords);
	rightFrag = vec4(rightFrag.r, 1.0, 1.0, 1.0); // Right eye is full green and blue and actual red
 
	// Multiply left and right components for final ourput colour
	vFragColour = vec4(leftFrag.rgb * rightFrag.rgb, 1.0); 
}
