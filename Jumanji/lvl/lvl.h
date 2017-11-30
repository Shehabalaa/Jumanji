#include"../object/object.h"
#pragma once

class lvl
{
public:
	object** objects;
	int objects_n;
	int already_loaded = 0;
	glm::mat4 lvl_view_matix;
	glm::mat4 lvl_projection_matix;
//	static boy boy;
//	static girl girl;
//	static oldman oldman;

public:
	lvl(int);
	virtual void load(char *, char *, char *, char *) = 0;
	virtual void Draw(int index) = 0;
	virtual void Draw_all() = 0;
	~lvl();
};

