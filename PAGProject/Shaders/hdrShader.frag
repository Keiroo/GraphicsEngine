#version 450 core
out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D hdrBuffer;
uniform bool hdr;
uniform float exposure;
uniform float gamma;
uniform bool isGamma;

void main()
{             
    vec3 hdrColor = texture(hdrBuffer, TexCoords).rgb;
    if(hdr)
    {
        vec3 result = vec3(1.0) - exp(-hdrColor * exposure);

		if(isGamma)
		{
			result = pow(result, vec3(1.0 / gamma));
		}
        FragColor = vec4(result, 1.0);
    }
    else
    {
		if(isGamma)
		{
			vec3 result = pow(hdrColor, vec3(1.0 / gamma));
			FragColor = vec4(result, 1.0);
		}
		else
		{
			FragColor = vec4(hdrColor, 1.0);
		}
        
    }
}
