#version 450

in vec3 position;
in vec3 color;
in vec2 texCoord;
out vec4 fragColor;

uniform sampler2D myTexture;

void main()
{
	fragColor = texture(myTexture, texCoord);
	//fragColor = texture(myTexture1, texCoord) * texture(myTexture2, texCoord);
	//fragColor = texture(myTexture1, texCoord) * vec4(color, 1.0f);
	

	//fragColor = vec4(color, 1.0f) * texture(myTexture1, texCoord);
	//fragColor = texture(myTexture1, texCoord) * texture(myTexture2, texCoord);

	//vec4 t0 = texture2D(myTexture1, texCoord.st);
	//vec4 t1 = texture2D(myTexture2, texCoord.st);
	//fragColor = mix(t0, t1, t1.a);
}