#include "Scene.h"



Scene::Scene()
{
	shader = new Shader();
	transform = new Transform();
	model = new Model(MODEL_PATH);
	world = glm::mat4(1.0f);
	srand(time(NULL));
	//for (short i = 0; i < MAX_OBJECTS; i++)
	//{
	//	speed[i] = 0.5f + ((float)(rand() / (float)(RAND_MAX)));
	//}

	//angle = 0.0f;
	shader->LoadShaders();
}

//bool Scene::LoadTextures(GLuint &programHandle)
//{
//	if (!texture->LoadAllTextures(programHandle))
//		return false;
//
//	return true;
//}

void Scene::Draw(GLfloat deltaTime)
{
	//angle += deltaTime;
	//if (angle > 360.0f)
	//	angle -= 360.0f;
	shader->ActivateShader();

	transform->SetParent(world);

	model->Draw(shader->programHandle);



	//for (short i = 0; i < MAX_OBJECTS; i++)
	//{
	//	if (i == 0)
	//		texture->BindTextures(programHandle, 0);
	//	else
	//		texture->BindTextures(programHandle, (i % 2) + 1);

	//	nodes[i].Reset();

	//	if (i == 0)
	//	{
	//		nodes[i].RotateLocal(angle, speed[i]);
	//		nodes[i].Scale(2.0f, 2.0f, 2.0f);
	//	}
	//	else
	//	{
	//		nodes[i].SetParent(nodes[0].GetMatrix());
	//		x = 7.0f * (float)i * cos(angle * speed[i] * 0.5f);
	//		z = 7.0f * (float)i * sin(angle * speed[i] * 0.5f);
	//		nodes[i].Translate(glm::vec3(x, 0.0f, z));
	//		nodes[i].RotateLocal(angle, speed[i]);
	//		nodes[i].Scale(0.6f, 0.6f, 0.6f);
	//	}
	//	nodes[i].Update(programHandle);
	//	glDrawArrays(GL_TRIANGLES, 0, 3 * 12);
	//}
}


Scene::~Scene()
{
}
