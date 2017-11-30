#include"Jumanji\lvl1\lvl1.h"


//object boy;
//object girl;
//object oldman;

lvl1::lvl1(int obj_num):lvl(obj_num)
{
	objects = new object*[obj_num];
	lvl_view_matix = glm::lookAt(
		glm::vec3(0, 30, 0),
		glm::vec3(0, 0, 0),
		glm::vec3(0, 0,-1)
	); 

	lvl_projection_matix = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f); ;
}

void lvl1::load(char *p,char*t,char *vname,char *fname)
{
	if (already_loaded < objects_n)
	{
		objects[already_loaded++] = new object(p, t, vname, fname);
	}
	
}

void lvl1::Draw(int index)
{
	objects[index]->Draw(lvl_view_matix, lvl_projection_matix);
}

void lvl1::Draw_all()
{
	for (int  i = 0; i <already_loaded; i++)
	{
		objects[i]->Draw(lvl_view_matix, lvl_projection_matix);
	}
	
}

lvl1::~lvl1()
{
	for (int i = 0; i < already_loaded; i++)
	{
		delete objects[i];
	}
}
