#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <vector>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GL/glfw.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>
using namespace glm;

#include <common/shader.hpp>
#include <common/texture.hpp>
#include <common/controls.hpp>
#include <common/objloader.hpp>
#include <common/vboindexer.hpp>
#define pi  3.14159265358979323846


class object
{
public:
	char * obj_path;
	char * texrure_path;
	GLuint objectID;
	GLuint MVP_MatrixID;
    GLuint ViewMatrixID;
	GLuint ModelMatrixID;
	GLuint vertexPosition_modelspaceID;
	GLuint vertexUVID;
	GLuint vertexNormal_modelspaceID;
	GLuint Texture;
	GLuint TextureID;
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;
	GLuint vertexbuffer;
	GLuint uvbuffer;
	GLuint normalbuffer;
	GLuint LightID;
	glm::mat4 ModelMatrix;
	glm::mat4 MainModelMatrix;

	

public:
	object(char * , char *,char*,char*);
	void Translate(const glm::vec3 &);
	void Rotate(float x_angle_in_rand, float y_angle_in_rand, float z_angle_in_rand);
	void Scale(const glm::vec3 &);
	void Draw(const glm::mat4 &,const glm::mat4 &, const glm::vec3 &lightPos);


	~object();
};

