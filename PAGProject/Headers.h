#pragma once
#include <glad\glad.h>
#include <glm\ext.hpp>
#include <GLFW\glfw3.h>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <AntTweakBar.h>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

#define VERTEX_SHADER_FILENAME "Shaders/myShader.vert"
#define FRAGMENT_SHADER_FILENAME "Shaders/myShader.frag"
#define CP_FRAGMENT_SHADER_FILENAME "Shaders/CPShader.frag"
#define LIGHT_VERTEX_SHADER_FILENAME "Shaders/lightShader.vert"
#define LIGHT_FRAGMENT_SHADER_FILENAME "Shaders/lightShader.frag"

#define TEXTURE0_FILENAME "Textures/lavaTexture.jpg"
#define TEXTURE1_FILENAME "Textures/planetTexture.jpg"
#define TEXTURE2_FILENAME "Textures/planet2Texture.jpg"

#define CAMERA_SPEED 30.0f

#define MODEL_FILENAME "Models/Nanosuit/nanosuit.obj"
//#define MODEL_FILENAME "Models/Hooh/hooh.obj"
#define PATH_CUBE_RED "Models/CubeRed/CubeRed.obj"
#define PATH_CUBE_GREEN "Models/CubeGreen/CubeGreen.obj"
#define PATH_CUBE_BLUE "Models/CubeBlue/CubeBlue.obj"


