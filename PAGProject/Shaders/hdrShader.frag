#version 450 core
out vec4 FragColor;

in vec2 TexCoords;
in vec2 blurVec;

uniform sampler2D hdrBuffer;
uniform bool hdr;
uniform float exposure;
uniform float gamma;
uniform bool isGamma;
uniform bool isMotionBlur;

vec3 result;
vec3 hdrColor;

const int nSamples = 16;

void main()
{          
	// Motion blur
	if (isMotionBlur)
	{
		vec4 motionBlur = texture(hdrBuffer, TexCoords);

		for (int i = 1; i < nSamples; ++i)
		{
		// get offset in range [-0.5, 0.5]:
			vec2 offset = blurVec * (float(i) / float(nSamples - 1) - 0.5);
  
		// sample & add to result:
			motionBlur += texture(hdrBuffer, TexCoords + offset);
		}

		motionBlur /= float(nSamples);


		hdrColor = motionBlur.rgb;
	}
	else
	{
		hdrColor = texture(hdrBuffer, TexCoords).rgb;
	}

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
