
#include"./Jumanji/lvl/lvl.h"

#pragma once

class lvl1:public lvl
{

public:
	lvl1(int);
	virtual void load(char *, char *, char *, char *);
	virtual void Draw(int index) ;
	virtual void Draw_all();
	~lvl1();
};

