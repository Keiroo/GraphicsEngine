#include "GrassGen.h"



GrassGen::GrassGen()
{
	GenVertices();
	GenBuffers();
	//texture = new Texture();
	//grassTexture = texture->TextureFromFile("grass.png", "Textures", false);
	LoadTexture();
}

void GrassGen::ResetTimer()
{
	tLastFrame = clock();
	fFrameInterval = 0.0f;
}

void GrassGen::Render(Shader *shader, Camera *camera, float deltaTime, float fAlphaTest, float fAlphaMultiplier)
{
	clock_t tCur = clock();
	fFrameInterval = float(tCur - tLastFrame) / float(CLOCKS_PER_SEC);
	tLastFrame = tCur;



	shader->ActivateGrassShader();
	// GeometryShader uniforms
	shader->setMat4("matrices.projMatrix", camera->GetProjectionMatrix());
	shader->setMat4("matrices.viewMatrix", camera->GetViewMatrix());
	shader->setMat4("matrices.modelMatrix", glm::mat4(1.0));
	shader->setMat4("matrices.normalMatrix", glm::mat4(1.0));
	

	// FragmentShader uniforms	
	shader->setVec4("vColor", glm::vec4(1, 1, 1, 1));
	shader->setVec3("vEyePosition", camera->thisCameraPos);
	shader->setFloat("fAlphaTest", fAlphaTest);
	shader->setFloat("fAlphaMultiplier", fAlphaMultiplier);
	
	// Render
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, grassTexture);
	shader->setInt("gSampler", 0);
	shader->setFloat("fTimePassed", fFrameInterval);

	glEnable(GL_MULTISAMPLE);
	glEnable(GL_SAMPLE_ALPHA_TO_COVERAGE);

	glBindVertexArray(grassVAO);
	glDrawArrays(GL_POINTS, 0, numGrassTriangles);

	glDisable(GL_SAMPLE_ALPHA_TO_COVERAGE);
	glDisable(GL_MULTISAMPLE);

	shader->ActivateShader();	
}

void GrassGen::GenVertices()
{
	srand(time(NULL));
	numGrassTriangles = 0;
	/*fGrassPatchOffsetMin = 1.5f;
	fGrassPatchOffsetMax = 2.5f;*/

	fGrassPatchOffsetMin = 1.5f;
	fGrassPatchOffsetMax = 2.5f;

	GLfloat minX = -50.0f, minZ = -50.0f;
	GLfloat maxX = 50.0f, maxZ = 50.0f;

	glm::vec3 vCurrPatchPos(minX, 0.0f, minZ);

	while (vCurrPatchPos.x < maxX)
	{
		vCurrPatchPos.z = -maxZ;
		while (vCurrPatchPos.z < maxZ)
		{
			vCurrPatchPos.z += fGrassPatchOffsetMin + (fGrassPatchOffsetMax - fGrassPatchOffsetMin)*(float)(rand() % 1000)*0.001f;
			grassVertices.push_back(vCurrPatchPos);
			numGrassTriangles++;
		}
		vCurrPatchPos.x += fGrassPatchOffsetMin + (fGrassPatchOffsetMax - fGrassPatchOffsetMin)*(float)(rand() % 1000)*0.001f;
	}

	//Debug
	/*grassVertices.clear();
	grassVertices.push_back(glm::vec3(0.0f, 0.0f, 0.0f));*/
}

void GrassGen::GenBuffers()
{
	glGenVertexArrays(1, &grassVAO);
	glGenBuffers(1, &grassVBO);
	glBindVertexArray(grassVAO);
	glBindBuffer(GL_ARRAY_BUFFER, grassVBO);
	glBufferData(GL_ARRAY_BUFFER, grassVertices.size() * sizeof(glm::vec3), &grassVertices[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
	glBindVertexArray(0);
}

int GrassGen::LoadTexture()
{
	string a_sPath = "Textures/grassPack.dds";
	bool bGenerateMipMaps = true;
	FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
	FIBITMAP* dib(0);

	fif = FreeImage_GetFileType(a_sPath.c_str(), 0);

	if (fif == FIF_UNKNOWN) // If still unknown, try to guess the file format from the file extension
		fif = FreeImage_GetFIFFromFilename(a_sPath.c_str());

	if (fif == FIF_UNKNOWN) // If still unknown, return failure
		return false;

	if (FreeImage_FIFSupportsReading(fif)) // Check if the plugin has reading capabilities and load the file
		dib = FreeImage_Load(fif, a_sPath.c_str());
	if (!dib)
		return false;

	BYTE* bDataPointer = FreeImage_GetBits(dib); // Retrieve the image data

												 // If somehow one of these failed (they shouldn't), return failure
	if (bDataPointer == NULL || FreeImage_GetWidth(dib) == 0 || FreeImage_GetHeight(dib) == 0)
		return false;

	GLenum format = 0;
	int bada = FreeImage_GetBPP(dib);
	if (FreeImage_GetBPP(dib) == 32)format = GL_RGBA;
	if (FreeImage_GetBPP(dib) == 24)format = GL_BGR;
	//if (FreeImage_GetBPP(dib) == 8)format = GL_LUMINANCE;
	if (format != 0)
		CreateFromData(bDataPointer, FreeImage_GetWidth(dib), FreeImage_GetHeight(dib), FreeImage_GetBPP(dib), format, bGenerateMipMaps);

	FreeImage_Unload(dib);
}

void GrassGen::CreateFromData(BYTE* bData, int a_iWidth, int a_iHeight, int a_iBPP, GLenum format, bool bGenerateMipMaps)
{
	// Generate an OpenGL texture ID for this texture
	glGenTextures(1, &grassTexture);
	glBindTexture(GL_TEXTURE_2D, grassTexture);
	if (format == GL_RGBA || format == GL_BGRA)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, a_iWidth, a_iHeight, 0, format, GL_UNSIGNED_BYTE, bData);
	// We must handle this because of internal format parameter
	else if (format == GL_RGB || format == GL_BGR)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, a_iWidth, a_iHeight, 0, format, GL_UNSIGNED_BYTE, bData);
	else
		glTexImage2D(GL_TEXTURE_2D, 0, format, a_iWidth, a_iHeight, 0, format, GL_UNSIGNED_BYTE, bData);
	if (bGenerateMipMaps)glGenerateMipmap(GL_TEXTURE_2D);
	//glGenSamplers(1, &grassSampler);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	//sPath = "";
	//bMipMapsGenerated = bGenerateMipMaps;
	//iWidth = a_iWidth;
	//iHeight = a_iHeight;
	//iBPP = a_iBPP;
}


GrassGen::~GrassGen()
{
}
