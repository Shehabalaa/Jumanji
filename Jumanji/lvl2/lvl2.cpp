#include"Jumanji\lvl2\lvl2.h"

//object boy;
//object girl;
//object oldman;

lvl2::lvl2(int obj_num) :lvl(obj_num)
{
	
	objects = new object*[obj_num];
	lvl_view_matix = glm::lookAt(
		glm::vec3(0.0f, 0.0f, 10.0f),     // Camera is here
		glm::vec3(0.0f, 0.0f, 0.0f), // and looks here : at the same position, plus "direction"
		glm::vec3(0.0f, 1.0f, 0.0f)                 // Head is up (set to 0,-1,0 to look upside-down)
	);

	lvl_projection_matrix = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
	this->load("snow.obj", "snow.bmp", "lvl2.vertexshader", "lvl2.fragmentshader");
	objects[0]->Scale(glm::vec3(100.0f, 50.0f, 0.0f));
	objects[0]->Translate(glm::vec3(0.0f, 0.0f, -25.0f));
	objects[0]->MainModelMatrix = objects[0]->ModelMatrix;
	this->load("Mei.obj", "Colors.bmp", "lvl2.vertexshader", "lvl2.fragmentshader");
	objects[1]->Translate(glm::vec3(0, -3,2));
	objects[1]->MainModelMatrix = objects[1]->ModelMatrix;




	this->load("Elk.obj", "Elk.bmp", "lvl2.vertexshader", "lvl2.fragmentshader");
	objects[2]->Scale(glm::vec3(2, 2, 2));
	objects[2]->Translate(glm::vec3(1,-3.5f, 0));
	objects[2]->MainModelMatrix = objects[2]->ModelMatrix;
	this->load("Elk.obj", "Elk.bmp", "lvl2.vertexshader", "lvl2.fragmentshader");
	objects[3]->Scale(glm::vec3(2, 2, 2));
	objects[3]->Translate(glm::vec3(3, -3.5f, 0));
	objects[3]->MainModelMatrix = objects[3]->ModelMatrix;


	this->load("Elk.obj", "Elk.bmp", "lvl2.vertexshader", "lvl2.fragmentshader");
	objects[4]->Scale(glm::vec3(2, 2, 2));
	objects[4]->Translate(glm::vec3(1, -3.5f, -5));
	objects[4]->MainModelMatrix = objects[4]->ModelMatrix;
	this->load("Elk.obj", "Elk.bmp", "lvl2.vertexshader", "lvl2.fragmentshader");
	objects[5]->Scale(glm::vec3(2, 2, 2));
	objects[5]->Translate(glm::vec3(3, -3.5f, -5));
	objects[5]->MainModelMatrix = objects[5]->ModelMatrix;


	this->load("Elk.obj", "Elk.bmp", "lvl2.vertexshader", "lvl2.fragmentshader");
	objects[6]->Scale(glm::vec3(2, 2, 2));
	objects[6]->Translate(glm::vec3(1, -4, -10));
	objects[6]->MainModelMatrix = objects[6]->ModelMatrix;
	this->load("Elk.obj", "Elk.bmp", "lvl2.vertexshader", "lvl2.fragmentshader");
	objects[7]->Scale(glm::vec3(2, 2, 2));
	objects[7]->Translate(glm::vec3(3, -4, -10));
	objects[7]->MainModelMatrix = objects[7]->ModelMatrix;

	this->load("Elk.obj", "Elk.bmp", "lvl2.vertexshader", "lvl2.fragmentshader");
	objects[8]->Scale(glm::vec3(2, 2, 2));
	objects[8]->Translate(glm::vec3(1, -4.5f, -15));
	objects[8]->MainModelMatrix = objects[8]->ModelMatrix;
	this->load("Elk.obj", "Elk.bmp", "lvl2.vertexshader", "lvl2.fragmentshader");
	objects[9]->Scale(glm::vec3(2, 2, 2));
	objects[9]->Translate(glm::vec3(3, -4.5f, -15));
	objects[9]->MainModelMatrix = objects[9]->ModelMatrix;









	this->load("Elk.obj", "Elk.bmp", "lvl2.vertexshader", "lvl2.fragmentshader");
	objects[10]->Scale(glm::vec3(2, 2, 2));
	objects[10]->Translate(glm::vec3(-1, -3.5f, -5));
	objects[10]->MainModelMatrix = objects[10]->ModelMatrix;
	this->load("Elk.obj", "Elk.bmp", "lvl2.vertexshader", "lvl2.fragmentshader");
	objects[11]->Scale(glm::vec3(2, 2, 2));
	objects[11]->Translate(glm::vec3(-3, -3.5f, -5));
	objects[11]->MainModelMatrix = objects[11]->ModelMatrix;


	this->load("Elk.obj", "Elk.bmp", "lvl2.vertexshader", "lvl2.fragmentshader");
	objects[12]->Scale(glm::vec3(2, 2, 2));
	objects[12]->Translate(glm::vec3(-1, -3.5f, -10));
	objects[12]->MainModelMatrix = objects[12]->ModelMatrix;
	this->load("Elk.obj", "Elk.bmp", "lvl2.vertexshader", "lvl2.fragmentshader");
	objects[13]->Scale(glm::vec3(2, 2, 2));
	objects[13]->Translate(glm::vec3(-3, -3.5f, -10));
	objects[13]->MainModelMatrix = objects[13]->ModelMatrix;


	this->load("Elk.obj", "Elk.bmp", "lvl2.vertexshader", "lvl2.fragmentshader");
	objects[14]->Scale(glm::vec3(2, 2, 2));
	objects[14]->Translate(glm::vec3(-1, -4, -15));
	objects[14]->MainModelMatrix = objects[14]->ModelMatrix;
	this->load("Elk.obj", "Elk.bmp", "lvl2.vertexshader", "lvl2.fragmentshader");
	objects[15]->Scale(glm::vec3(2, 2, 2));
	objects[15]->Translate(glm::vec3(-3, -4, -15));
	objects[15]->MainModelMatrix = objects[15]->ModelMatrix;

	this->load("Elk.obj", "Elk.bmp", "lvl2.vertexshader", "lvl2.fragmentshader");
	objects[16]->Scale(glm::vec3(2, 2, 2));
	objects[16]->Translate(glm::vec3(0, -4.5f, -20));
	objects[16]->MainModelMatrix = objects[16]->ModelMatrix;
	this->load("Elk.obj", "Elk.bmp", "lvl2.vertexshader", "lvl2.fragmentshader");
	objects[17]->Scale(glm::vec3(2, 2, 2));
	objects[17]->Translate(glm::vec3(-3, -4.5f, -18));
	objects[17]->MainModelMatrix = objects[17]->ModelMatrix;


}

void lvl2::load(char *p, char*t, char *vname, char *fname)
{
	if (already_loaded < objects_n)
	{
		objects[already_loaded++] = new object(p, t, vname, fname);
	}

}

void lvl2::Draw(int index, const glm::vec3 & lightpos)
{

	objects[index]->Draw(lvl_view_matix, lvl_projection_matrix, lightpos);
}

void lvl2::Draw_all(const glm::vec3 & lightpos)
{

	for (int i = 0; i <already_loaded; i++)
	{
		objects[i]->Draw(lvl_view_matix, lvl_projection_matrix, lightpos);
	}

}

lvl2::~lvl2()
{
	for (int i = 0; i < already_loaded; i++)
	{
		delete objects[i];
	}
}
