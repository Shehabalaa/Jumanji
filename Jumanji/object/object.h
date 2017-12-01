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
using namespace glm;

#include <common/shader.hpp>
#include <common/texture.hpp>
#include <common/controls.hpp>
#include <common/objloader.hpp>
#include <common/vboindexer.hpp>


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

	

public:
	object(char * , char *,char*,char*);
	void Translate(const glm::vec3 &);
	void Rotate();
	void Scale();
	void Draw(const glm::mat4 &,const glm::mat4 &);


	~object();
};

