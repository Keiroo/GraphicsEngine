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
#define SKYBOX_VERTEX_SHADER_FILENAME "Shaders/skyboxShader.vert"
#define SKYBOX_FRAGMENT_SHADER_FILENAME "Shaders/skyboxShader.frag"
#define REF_VERTEX_SHADER_FILENAME "Shaders/refShader.vert"
#define REF_FRAGMENT_SHADER_FILENAME "Shaders/refShader.frag"
#define GRASS_VERTEX_SHADER_FILENAME "Shaders/grassShader.vert"
#define GRASS_GEOMETRY_SHADER_FILENAME "Shaders/grassShader.geom"
#define GRASS_FRAGMENT_SHADER_FILENAME "Shaders/grassShader.frag"
#define HDR_VERTEX_SHADER_FILENAME "Shaders/hdrShader.vert"
#define HDR_FRAGMENT_SHADER_FILENAME "Shaders/hdrShader.frag"
#define REFL_VERTEX_SHADER_FILENAME "Shaders/reflShader.vert"
#define REFL_FRAGMENT_SHADER_FILENAME "Shaders/reflShader.frag"

#define TEXTURE0_FILENAME "Textures/lavaTexture.jpg"
#define TEXTURE1_FILENAME "Textures/planetTexture.jpg"
#define TEXTURE2_FILENAME "Textures/planet2Texture.jpg"
#define TERRAIN_TEXTURE_FILENAME "Textures/terrain.jpg"

#define CAMERA_SPEED 50.0f

#define MODEL_FILENAME "Models/Nanosuit/nanosuit.obj"
//#define MODEL_FILENAME "Models/Hooh/hooh.obj"
#define PATH_CUBE_RED "Models/CubeRed/CubeRed.obj"
#define PATH_CUBE_GREEN "Models/CubeGreen/CubeGreen.obj"
#define PATH_CUBE_BLUE "Models/CubeBlue/CubeBlue.obj"

#define PLANE_FILENAME "Models/Plane/Plane.obj"
#define WOMANROCK_FILENAME "Models/womanrock/womanrock.obj"
#define OLAV_FILENAME "Models/olav/Testvb.obj"
#define TEMPLAR_FILENAME "Models/armor/armor.blend"
