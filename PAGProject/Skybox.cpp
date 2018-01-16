#include "Skybox.h"



Skybox::Skybox()
{
	texture = new Texture();
	LoadBuffers();
	cubemapTexture = texture->loadCubemap(faces);
}



void Skybox::Render(Shader *shader, Camera *camera)
{
	glDepthFunc(GL_LEQUAL);
	shader->ActivateSkyboxShader();
	shader->setInt("skybox", 0);
	shader->setMat4("view", glm::mat4(glm::mat3(camera->GetViewMatrix())));
	shader->setMat4("projection", camera->GetProjectionMatrix());
	glBindVertexArray(skyboxVAO);
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glDepthFunc(GL_LESS);
	shader->ActivateShader();
}

Skybox::~Skybox()
{
}

void Skybox::LoadBuffers()
{	
	glGenVertexArrays(1, &skyboxVAO);
	glGenBuffers(1, &skyboxVBO);
	glBindVertexArray(skyboxVAO);
	glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
}