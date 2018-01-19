#version 450 core
out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D hdrBuffer;
uniform bool hdr;
uniform float exposure;
uniform float gamma;
uniform bool isGamma;
uniform bool isMotionBlur;

vec3 result;

void main()
{             
    vec3 hdrColor = texture(hdrBuffer, TexCoords).rgb;


    if(hdr)
    {
        result = vec3(1.0) - exp(-hdrColor * exposure);

		if(isGamma)
		{
			result = pow(result, vec3(1.0 / gamma));
		}
    }
    else
    {
		if(isGamma)
		{
			result = pow(hdrColor, vec3(1.0 / gamma));
		}
		else
		{
			result = hdrColor;
		}   
    }




	FragColor = vec4(result, 1.0);
}
