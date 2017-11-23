#pragma once
#include <glad\glad.h>
#include <glm\ext.hpp>
#include <GLFW\glfw3.h>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

#define VERTEX_SHADER_FILENAME "Shaders/myShader.vert"
#define FRAGMENT_SHADER_FILENAME "Shaders/myShader.frag"

#define TEXTURE0_FILENAME "Textures/lavaTexture.jpg"
#define TEXTURE1_FILENAME "Textures/planetTexture.jpg"
#define TEXTURE2_FILENAME "Textures/planet2Texture.jpg"

#define MODEL_FILENAME "Models/Nanosuit/nanosuit.obj"
