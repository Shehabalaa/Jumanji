#pragma once
#include"../object/object.h"
#include <common/collisiondetection.hpp>
class lvl
{
public:
	object** objects;
	int objects_n;
	int already_loaded = 0;
	glm::mat4 lvl_view_matix;
	glm::mat4 lvl_projection_matrix;
	glm::vec3 position;
	glm::vec3 direction;
	glm::vec3 up;
	// Initial horizontal angle : toward -Z
	float horizontalAngle = 3.14f;
	// Initial vertical angle : none
	float verticalAngle = 0.0f;
	// Initial Field of View
	float initialFoV = 45.0f;

	float speed = 3.0f; // 3 units / second
	float mouseSpeed = 0.005f;

//	static boy boy;
//	static girl girl;
//	static oldman oldman;

public:
	lvl(int);
	virtual void load(char *, char *, char *, char *) = 0;
	virtual void Draw(int index,const glm::vec3 & lightpos) = 0;
	virtual void Draw_all(const glm::vec3 & lightpos) = 0;
	virtual void Play(const glm::vec3 & lightpos) = 0;
	~lvl();
};

