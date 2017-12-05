
#include"./Jumanji/lvl/lvl.h"

#pragma once

class lvl2 :public lvl
{
	object *map;
public:
	lvl2(int);
	virtual void load(char *, char *, char *, char *);
	virtual void Draw(int index, const glm::vec3 & lightpos);
	virtual void Draw_all(const glm::vec3 & lightpos);
	virtual void computeMatricesFromInputs();

	~lvl2();
};