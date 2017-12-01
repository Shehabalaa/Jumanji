
#include"./Jumanji/lvl/lvl.h"

#pragma once

class lvl1:public lvl
{
	object *map;
public:
	lvl1(int);
	virtual void load(char *, char *, char *, char *);
	virtual void Draw(int index, const glm::vec3 & lightpos) ;
	virtual void Draw_all(const glm::vec3 & lightpos);
	~lvl1();
};

