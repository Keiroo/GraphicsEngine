#include "Mesh.h"



Mesh::Mesh()
{
	transform = new Transform();
	texture = new Texture();
	angle = 0.0f;
	srand(time(NULL));
	for (short i = 0; i < MAX_OBJECTS; i++)
	{
		//speed[i] = (float)(rand() / (float)(RAND_MAX));
		speed[i] = 0.5f + ((float)(rand() / (float)(RAND_MAX)));
	}
}

void Mesh::LoadBuffers()
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glGenBuffers(3, VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (GLvoid*)0);

	glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);

	glBindBuffer(GL_ARRAY_BUFFER, VBO[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(texCoords), texCoords, GL_STATIC_DRAW);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (GLvoid*)0);
}

bool Mesh::LoadTextures(GLuint &programHandle)
{
	if (!texture->LoadAllTextures(programHandle))
		return false;

	/*texture->BindTextures(programHandle);*/
	return true;
}

void Mesh::Render(GLuint &programHandle, float deltaTime)
{
	angle += deltaTime;
	if (angle > 360.0f)
		angle -= 360.0f;

	glUseProgram(programHandle);
	glBindVertexArray(VAO);
	texture->BindTextures(programHandle);

	for (short i = 0; i < MAX_OBJECTS; i++)
	{
		transform->Reset();
		
		if (i == 0)
		{
			//transform->RotateLocal(angle, speed[i]);
			transform->Scale(1.5f, 1.5f, 1.5f);
		}
		else
		{
			x = 7.0f * (float)i * cos(angle* speed[i] * 0.5f);
			z = 7.0f * (float)i * sin(angle* speed[i] * 0.5f);
			transform->Translate(glm::vec3(x, 0.0f, z));
			transform->RotateLocal(angle, speed[i]);
			transform->Scale(speed[i], speed[i], speed[i]);
		}
		transform->Update(programHandle);

		//glDrawElements(GL_TRIANGLES, 3 * 12, GL_UNSIGNED_INT, 0);
		glDrawArrays(GL_TRIANGLES, 0, 3 * 12);
	}

	

}

Mesh::~Mesh()
{
}
