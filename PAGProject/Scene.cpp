#include "Scene.h"



Scene::Scene()
{
	texture = new Texture();
	world = glm::mat4(1.0f);
	srand(time(NULL));
	for (short i = 0; i < MAX_OBJECTS; i++)
	{
		speed[i] = 0.5f + ((float)(rand() / (float)(RAND_MAX)));
	}
}

bool Scene::LoadTextures(GLuint &programHandle)
{
	if (!texture->LoadAllTextures(programHandle))
		return false;

	return true;
}

void Scene::Draw(GLuint &programHandle, GLfloat angle)
{
	for (short i = 0; i < MAX_OBJECTS; i++)
	{
		if (i == 0)
			texture->BindTextures(programHandle, 0);
		else
			texture->BindTextures(programHandle, (i % 2) + 1);

		nodes[i].Reset();

		if (i == 0)
		{
			nodes[i].RotateLocal(angle, speed[i]);
			nodes[i].Scale(2.0f, 2.0f, 2.0f);
		}
		else
		{
			nodes[i].SetParent(nodes[0].GetMatrix());
			x = 7.0f * (float)i * cos(angle * speed[i] * 0.5f);
			z = 7.0f * (float)i * sin(angle * speed[i] * 0.5f);
			nodes[i].Translate(glm::vec3(x, 0.0f, z));
			nodes[i].RotateLocal(angle, speed[i]);
			nodes[i].Scale(0.6f, 0.6f, 0.6f);
		}
		nodes[i].Update(programHandle);
		glDrawArrays(GL_TRIANGLES, 0, 3 * 12);
	}
	//for (short i = 0; i < MAX_OBJECTS; i++)
	//{
	//	texture->BindTextures(programHandle, (i % 3));

	//	transform->Reset();

	//	if (i == 0)
	//	{
	//		transform->RotateLocal(angle, speed[i]);
	//		transform->Scale(1.5f, 1.5f, 1.5f);
	//	}
	//	else
	//	{
	//		x = 7.0f * (float)i * cos(angle* speed[i] * 0.5f);
	//		z = 7.0f * (float)i * sin(angle* speed[i] * 0.5f);
	//		transform->Translate(glm::vec3(x, 0.0f, z));
	//		transform->RotateLocal(angle, speed[i]);
	//		transform->Scale(speed[i], speed[i], speed[i]);
	//	}
	//	transform->Update(programHandle);

	//	//glDrawElements(GL_TRIANGLES, 3 * 12, GL_UNSIGNED_INT, 0);
	//	glDrawArrays(GL_TRIANGLES, 0, 3 * 12);
	//}
}


Scene::~Scene()
{
}
