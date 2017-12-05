#include"Jumanji\lvl1\lvl1.h"

//object boy;
//object girl;
//object oldman;

lvl1::lvl1(int obj_num):lvl(obj_num)
{
	objects = new object*[obj_num];
	lvl_view_matix = glm::lookAt(
		glm::vec3(0, 0, 8),
		glm::vec3(0, 0, 0),
		glm::vec3(0, 1,0)
	); 

	lvl_projection_matix = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);

	this->load("lvl1map.obj ", "lvl1map.bmp", "lvl1map.vertexshader", "lvl1map.fragmentshader");
	objects[0]->Scale(glm::vec3(5,4,1));
	objects[0]->MainModelMatrix = objects[0]->ModelMatrix;
	this->load("treelog.obj", "treelog.bmp", "treelog.vertexshader", "treelog.fragmentshader");
	//objects[1]->Scale(glm::vec3(.5, .5, .5));
	objects[1]->Rotate(0, pi / 2, 0);
	objects[1]->Translate(glm::vec3(0, 0, 1));
	objects[1]->MainModelMatrix = objects[1]->ModelMatrix;
	this->load("boy.obj", "boy.bmp", "treelog.vertexshader", "treelog.fragmentshader");
	//objects[2]->Scale(glm::vec3(4, 4, 4));
	objects[2]->Rotate(pi/2, 0, 0);
	objects[2]->Translate(glm::vec3(0,1.7, 1));
	objects[2]->MainModelMatrix = objects[2]->ModelMatrix;


}

void lvl1::load(char *p,char*t,char *vname,char *fname)
{
	if (already_loaded < objects_n)
	{
		objects[already_loaded++] = new object(p, t, vname, fname);
	}
	
}

void lvl1::Draw(int index,const glm::vec3 & lightpos)
{

	objects[index]->Draw(lvl_view_matix, lvl_projection_matix, lightpos);
}

void lvl1::Draw_all(const glm::vec3 & lightpos)
{
	computeMatricesFromInputs();
	lvl_view_matix = getViewMatrix();
	lvl_projection_matix = getProjectionMatrix();

	for (int  i = 0; i <already_loaded; i++)
	{
		objects[i]->Draw(lvl_view_matix, lvl_projection_matix, lightpos);
	}
	
}

lvl1::~lvl1()
{
	for (int i = 0; i < already_loaded; i++)
	{
		delete objects[i];
	}
}
