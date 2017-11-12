#version 450

in vec3 position;
in vec3 color;
in vec2 texCoord;
out vec4 fragColor;

//uniform sampler2D myTexture;
uniform sampler2D textureDiffuse1;
uniform sampler2D textureDiffuse2;
uniform sampler2D textureDiffuse3;
uniform sampler2D textureSpecular1;
uniform sampler2D textureSpecular2;


void main()
{
	fragColor = texture(textureDiffuse1, texCoord) * texture(textureDiffuse2, texCoord) * texture(textureDiffuse3, texCoord)
				* texture(textureSpecular1, texCoord) * texture(textureSpecular2, texCoord);

	//fragColor = texture(myTexture, texCoord);
	//fragColor = texture(myTexture1, texCoord) * texture(myTexture2, texCoord);
	//fragColor = texture(myTexture1, texCoord) * vec4(color, 1.0f);
	

	//fragColor = vec4(color, 1.0f) * texture(myTexture1, texCoord);
	//fragColor = texture(myTexture1, texCoord) * texture(myTexture2, texCoord);

	//vec4 t0 = texture2D(myTexture1, texCoord.st);
	//vec4 t1 = texture2D(myTexture2, texCoord.st);
	//fragColor = mix(t0, t1, t1.a);
}