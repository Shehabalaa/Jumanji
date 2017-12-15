#include"Jumanji\lvl1\lvl1.h"

//object boy;
//object girl;
//object oldman;

lvl1::lvl1(int obj_num):lvl(obj_num)
{
	jmpcases = onground;
	max_mov_for_character_in_pos_XYZ = glm::vec3(4.0f,2.0f,0.0f);
	max_mov_for_character_in_neg_XYZ = glm::vec3(-4.0f,0.0f,-3.0f);
	objects = new object*[obj_num];

	lvl_view_matix = glm::lookAt(
		glm::vec3(0, 0,10),
		glm::vec3(0, 0, 0),
		glm::vec3(0, 1, 0)
	); 

	lvl_projection_matrix = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);

	this->load("snow.obj", "snow.bmp", "lvl2.vertexshader", "lvl2.fragmentshader");
	objects[0]->Scale(glm::vec3(100.0f, 50.0f,0.0f));
	objects[0]->Translate(glm::vec3(0.0f, 0.0f, -25.0f));
	objects[0]->MainModelMatrices[0] = objects[0]->ModelMatrices[0];

	this->load("boy.obj", "boy.bmp", "boy.vertexshader", "boy.fragmentshader");
	objects[1]->Rotate(0, pi, 0);
	//objects[1]->Scale(glm::vec3(2, 2, 2));
	objects[1]->Translate(glm::vec3(0, -4, 0));
	objects[1]->MainModelMatrices[0] = objects[1]->ModelMatrices[0];
	objects[1]->Tracking_Points[0] = glm::vec3(0.0f, 0.0f, 0.0f);


	int obstacles_num =27;

	//obstacles
	this->load("treelog.obj", "treelog.bmp", "treelog.vertexshader", "treelog.fragmentshader", obstacles_num);
	//frist block 3  0,1,2
							//---
	objects[2]->Scale(glm::vec3(2,2, 3.5),0);
	objects[2]->Rotate(0, pi / 2, 0,0);
	objects[2]->Translate(glm::vec3(0, -7, -25),0);
	objects[2]->MainModelMatrices[0] = objects[2]->ModelMatrices[0];

	objects[2]->Scale(glm::vec3(2, 2, 3.5),1);
	objects[2]->Rotate(0, pi / 2, 0,1);
	objects[2]->Translate(glm::vec3(-3, -7, -25),1);
	objects[2]->MainModelMatrices[1] = objects[2]->ModelMatrices[1];

	objects[2]->Scale(glm::vec3(2, 2, 3.5), 2);
	objects[2]->Rotate(0, pi / 2, 0, 2);
	objects[2]->Translate(glm::vec3(3, -7, -25), 2);
	objects[2]->MainModelMatrices[2] = objects[2]->ModelMatrices[2];
	//---

	//second block 9  3,4,5,6,7,8,9,10,11
	//  -
	//  -
	//---
	// -
	//---
	objects[2]->Scale(glm::vec3(2, 2, 3.5),3);
	objects[2]->Rotate(0, pi / 2, 0,3);
	objects[2]->Translate(glm::vec3(0, -8, -35),3);
	objects[2]->MainModelMatrices[3] = objects[2]->ModelMatrices[3];

	objects[2]->Scale(glm::vec3(2, 2, 3.5), 4);
	objects[2]->Rotate(0, pi / 2, 0, 4);
	objects[2]->Translate(glm::vec3(-3, -8, -35), 4);
	objects[2]->MainModelMatrices[4] = objects[2]->ModelMatrices[4];

	objects[2]->Scale(glm::vec3(2, 2, 3.5), 5);
	objects[2]->Rotate(0, pi / 2, 0, 5);
	objects[2]->Translate(glm::vec3(3, -8, -35), 5);
	objects[2]->MainModelMatrices[5] = objects[2]->ModelMatrices[5];
	//---

	objects[2]->Scale(glm::vec3(2, 2, 3.5), 6);
	objects[2]->Rotate(0, pi / 2, 0, 6);
	objects[2]->Translate(glm::vec3(0, -8.5, -37.5), 6);
	objects[2]->MainModelMatrices[6] = objects[2]->ModelMatrices[6];
	// - 
	objects[2]->Scale(glm::vec3(2, 2, 3.5), 7);
	objects[2]->Rotate(0, pi / 2, 0, 7);
	objects[2]->Translate(glm::vec3(0, -9, -40), 7);
	objects[2]->MainModelMatrices[7] = objects[2]->ModelMatrices[7];

	objects[2]->Scale(glm::vec3(2, 2, 3.5), 8);
	objects[2]->Rotate(0, pi / 2, 0, 8);
	objects[2]->Translate(glm::vec3(3, -9, -40), 8);
	objects[2]->MainModelMatrices[8] = objects[2]->ModelMatrices[8];

	objects[2]->Scale(glm::vec3(2, 2, 3.5), 9);
	objects[2]->Rotate(0, pi / 2, 0, 9);
	objects[2]->Translate(glm::vec3(-3, -9, -40), 9);
	objects[2]->MainModelMatrices[9] = objects[2]->ModelMatrices[9];
	//--- 
	objects[2]->Scale(glm::vec3(2, 2, 3.5), 10);
	objects[2]->Rotate(0, pi / 2, 0, 10);
	objects[2]->Translate(glm::vec3(3, -9.5, -42.5), 10);
	objects[2]->MainModelMatrices[10] = objects[2]->ModelMatrices[10];
	//  - 
	objects[2]->Scale(glm::vec3(2, 2, 3.5), 11);
	objects[2]->Rotate(0, pi / 2, 0, 11);
	objects[2]->Translate(glm::vec3(3, -10, -45), 11);
	objects[2]->MainModelMatrices[11] = objects[2]->ModelMatrices[11];
	//  -

	// thirdblock 9logs start from 12
	//  -
	// --
	//---
	//-
	//--
	objects[2]->Scale(glm::vec3(2, 2, 3.5), 12);
	objects[2]->Rotate(0, pi / 2, 0, 12);
	objects[2]->Translate(glm::vec3(0, -11, -55), 12);
	objects[2]->MainModelMatrices[12] = objects[2]->ModelMatrices[12];

	objects[2]->Scale(glm::vec3(2, 2, 3.5), 13);
	objects[2]->Rotate(0, pi / 2, 0, 13);
	objects[2]->Translate(glm::vec3(-3, -11, -55), 13);
	objects[2]->MainModelMatrices[13] = objects[2]->ModelMatrices[13];
	//--

	objects[2]->Scale(glm::vec3(2, 2, 3.5), 14);
	objects[2]->Rotate(0, pi / 2, 0, 14);
	objects[2]->Translate(glm::vec3(-3, -11.5, -57.5), 14);
	objects[2]->MainModelMatrices[14] = objects[2]->ModelMatrices[14];
	//- 
	objects[2]->Scale(glm::vec3(2, 2, 3.5), 15);
	objects[2]->Rotate(0, pi / 2, 0, 15);
	objects[2]->Translate(glm::vec3(0, -12, -60), 15);
	objects[2]->MainModelMatrices[15] = objects[2]->ModelMatrices[15];

	objects[2]->Scale(glm::vec3(2, 2, 3.5), 16);
	objects[2]->Rotate(0, pi / 2, 0, 16);
	objects[2]->Translate(glm::vec3(-3, -12, -60), 16);
	objects[2]->MainModelMatrices[16] = objects[2]->ModelMatrices[16];

	objects[2]->Scale(glm::vec3(2, 2, 3.5), 17);
	objects[2]->Rotate(0, pi / 2, 0, 17);
	objects[2]->Translate(glm::vec3(3, -12, -60), 17);
	objects[2]->MainModelMatrices[17] = objects[2]->ModelMatrices[17];
	//---
	objects[2]->Scale(glm::vec3(2, 2, 3.5), 18);
	objects[2]->Rotate(0, pi / 2, 0, 18);
	objects[2]->Translate(glm::vec3(3, -12.5, -62.5), 18);
	objects[2]->MainModelMatrices[18] = objects[2]->ModelMatrices[18];

	objects[2]->Scale(glm::vec3(2, 2, 3.5), 19);
	objects[2]->Rotate(0, pi / 2, 0, 19);
	objects[2]->Translate(glm::vec3(0, -12.5, -62.5), 19);
	objects[2]->MainModelMatrices[19] = objects[2]->ModelMatrices[19];
	// --
	objects[2]->Scale(glm::vec3(2, 2, 3.5), 20);
	objects[2]->Rotate(0, pi / 2, 0, 20);
	objects[2]->Translate(glm::vec3(3, -13, -65), 20);
	objects[2]->MainModelMatrices[20] = objects[2]->ModelMatrices[20];
	//  -
	//first air block 2 
	//-
	//-

	objects[2]->Scale(glm::vec3(1, 1, 10),21);
	objects[2]->Rotate(0, pi / 2, 0, 21);
	objects[2]->Translate(glm::vec3(0, -14,-75), 21);
	objects[2]->MainModelMatrices[21] = objects[2]->ModelMatrices[21];
	//-

	objects[2]->Scale(glm::vec3(1, 1, 10), 22);
	objects[2]->Rotate(0, pi / 2, 0, 22);
	objects[2]->Translate(glm::vec3(0, -10,-75), 22);
	objects[2]->MainModelMatrices[22] = objects[2]->ModelMatrices[22];
	//-

	//second air blocks  8
	// _	
	//|_|
	//*/

	objects[2]->Scale(glm::vec3(1.5, 1.5, 1.5), 23);
	objects[2]->Rotate(0, pi / 2, 0, 23);
	objects[2]->Translate(glm::vec3(0, -14, -85), 23);
	objects[2]->MainModelMatrices[23] = objects[2]->ModelMatrices[23];


	objects[2]->Scale(glm::vec3(1.5, 1.5, 1.5), 26);
	objects[2]->Rotate(0, pi / 2, 0, 26);
	objects[2]->Translate(glm::vec3(0, -8, -85), 26);
	objects[2]->MainModelMatrices[26] = objects[2]->ModelMatrices[26];


	objects[2]->Scale(glm::vec3(1.5, 1.5, 1.5), 24);
	objects[2]->Rotate(pi / 2, 0, 0, 24);
	objects[2]->Translate(glm::vec3(-3, -11, -85), 24);
	objects[2]->MainModelMatrices[24] = objects[2]->ModelMatrices[24];

	objects[2]->Scale(glm::vec3(1.5, 1.5, 1.5), 25);
	objects[2]->Rotate(pi / 2, 0, 0, 25);
	objects[2]->Translate(glm::vec3(3, -11, -85), 25);
	objects[2]->MainModelMatrices[25] = objects[2]->ModelMatrices[25];


}

void lvl1::load(char *p,char*t,char *vname,char *fname,int num_of_copies_of_same_object) // numn of copies inluding the original obj (if only one obj with 0 copy so num of copies = 1)
{
	if (already_loaded < objects_n)
	{
		objects[already_loaded++] = new object(p, t, vname, fname, num_of_copies_of_same_object);
	}
	
}

void lvl1::Draw(int index,const glm::vec3 & lightpos)
{
	for (int i = 0; i < objects[index]->Copies_num; i++)
		objects[index]->Draw(lvl_view_matix, lvl_projection_matrix, lightpos,i);
	
}


void lvl1::Draw_all(const glm::vec3 & lightpos)
{
	//computeMatricesFromInputs();
	//lvl_view_matix = getViewMatrix();
	//lvl_projection_matrix = getProjectionMatrix();



	for (int i = 0; i < already_loaded; i++)
		for (int j = 0; j < objects[i]->Copies_num; j++)
			objects[i]->Draw(lvl_view_matix, lvl_projection_matrix, lightpos,j);


	//	Sleep(5);
}

void lvl1::Play(const glm::vec3 & lightpos)
{
	//tree logs

		float treelog_speed_z = 0.1;
		float treelog_speed_y = 3.0 / (25 / treelog_speed_z);
		//first block
		for (int i = 0; i < 3; i++)
			objects[2]->Translate(glm::vec3(0.0f, treelog_speed_y, treelog_speed_z), i);

		//second block
		treelog_speed_y = 4.0 / (35 / treelog_speed_z);
		for (int i = 3; i < 6; i++)
			objects[2]->Translate(glm::vec3(0.0f, treelog_speed_y, treelog_speed_z), i);

		treelog_speed_y = 4.5 / (37.5 / treelog_speed_z);
		objects[2]->Translate(glm::vec3(0.0f, treelog_speed_y, treelog_speed_z), 6);

		treelog_speed_y = 5.0 / (40 / treelog_speed_z);
		for (int i = 7; i < 10; i++)
			objects[2]->Translate(glm::vec3(0.0f, treelog_speed_y, treelog_speed_z), i);

		treelog_speed_y = 5.5 / (42.5 / treelog_speed_z);
		objects[2]->Translate(glm::vec3(0.0f, treelog_speed_y, treelog_speed_z), 10);

		treelog_speed_y = 6.0 / (45 / treelog_speed_z);
		objects[2]->Translate(glm::vec3(0.0f, treelog_speed_y, treelog_speed_z), 11);

		//third block

		treelog_speed_y = 7.0 / (55 / treelog_speed_z);
		for (int i = 12; i < 14; i++)
			objects[2]->Translate(glm::vec3(0.0f, treelog_speed_y, treelog_speed_z), i);

		treelog_speed_y = 7.5 / (57.5 / treelog_speed_z);
		objects[2]->Translate(glm::vec3(0.0f, treelog_speed_y, treelog_speed_z), 14);

		treelog_speed_y = 8.0 / (60 / treelog_speed_z);
		for (int i = 15; i < 18; i++)
			objects[2]->Translate(glm::vec3(0.0f, treelog_speed_y, treelog_speed_z), i);

		treelog_speed_y = 8.5 / (62.5 / treelog_speed_z);
		for (int i = 18; i < 20; i++)
			objects[2]->Translate(glm::vec3(0.0f, treelog_speed_y, treelog_speed_z), i);

		treelog_speed_y = 9.0 / (65 / treelog_speed_z);
		objects[2]->Translate(glm::vec3(0.0f, treelog_speed_y, treelog_speed_z), 20);


		//fourth block

		treelog_speed_y = 10.0 / (75 / treelog_speed_z);
		for (int i = 21; i < 23; i++)
			objects[2]->Translate(glm::vec3(0.0f, treelog_speed_y, treelog_speed_z), i);


		//finally fith block

		treelog_speed_y = 11.0 / (85 / treelog_speed_z);

		glm::vec3 tmp = objects[2]->Tracking_Points[23];
		objects[2]->Translate(-tmp, 23);
		objects[2]->Translate(glm::vec3(0, -3, 0), 23);
		objects[2]->Rotate(0, 0, .1, 23);
		objects[2]->Translate(tmp + glm::vec3(0, 3, 0), 23);
		objects[2]->Translate(glm::vec3(0.0f, treelog_speed_y, treelog_speed_z), 23);

		tmp = objects[2]->Tracking_Points[24];
		objects[2]->Translate(-tmp, 24);
		objects[2]->Translate(glm::vec3(-3, 0, 0), 24);
		objects[2]->Rotate(0, 0, .1, 24);
		objects[2]->Translate(tmp + glm::vec3(3, 0, 0), 24);
		objects[2]->Translate(glm::vec3(0.0f, treelog_speed_y, treelog_speed_z), 24);


		tmp = objects[2]->Tracking_Points[25];
		objects[2]->Translate(-tmp, 25);
		objects[2]->Translate(glm::vec3(3, 0, 0), 25);
		objects[2]->Rotate(0, 0, .1, 25);
		objects[2]->Translate(tmp + glm::vec3(-3,0 , 0), 25);
		objects[2]->Translate(glm::vec3(0.0f, treelog_speed_y, treelog_speed_z), 25);

		tmp = objects[2]->Tracking_Points[26];
		objects[2]->Translate(-tmp, 26);
		objects[2]->Translate(glm::vec3(0, 3, 0), 26);
		objects[2]->Rotate(0, 0, .1, 26);
		objects[2]->Translate(tmp + glm::vec3(0, -3, 0), 26);
		objects[2]->Translate(glm::vec3(0.0f, treelog_speed_y, treelog_speed_z), 26);




	


	// boyyyyyyyyyyyyyyyyyyyyyyyyyy

	glm::mediump_float moving_speed = .1;
	glm::mediump_float jumping_speed = .1;
	// Move forward
	if (glfwGetKey(GLFW_KEY_UP) == GLFW_PRESS) {
		glm::mediump_float tmp = objects[1]->Tracking_Points[0].z - moving_speed;
		if(tmp >= max_mov_for_character_in_neg_XYZ.z)
			objects[1]->Translate(glm::vec3(0.0f, 0.0f, -moving_speed));
	}
	// Move backward
	if (glfwGetKey(GLFW_KEY_DOWN) == GLFW_PRESS) {
		glm::mediump_float tmp = objects[1]->Tracking_Points[0].z + moving_speed;
		if (tmp <= max_mov_for_character_in_pos_XYZ.z)
			objects[1]->Translate(glm::vec3(0.0f, 0.0f, moving_speed));
	}
	// move right
	if (glfwGetKey(GLFW_KEY_RIGHT) == GLFW_PRESS) {
		glm::mediump_float tmp = objects[1]->Tracking_Points[0].x + moving_speed;
		if (tmp <= max_mov_for_character_in_pos_XYZ.x)
			objects[1]->Translate(glm::vec3(moving_speed, 0.0f, 0.0f));
	}
	// move left
	if (glfwGetKey(GLFW_KEY_LEFT) == GLFW_PRESS) {
		glm::mediump_float tmp = objects[1]->Tracking_Points[0].x - moving_speed;
		if (tmp >= max_mov_for_character_in_neg_XYZ.x)
			objects[1]->Translate(glm::vec3(-moving_speed, 0.0f, 0.0f));
	}
	// jump
	// checking max fly
	glm::mediump_float tmp1 = 0.0f;
	switch (jmpcases)
	{
	case onground:
		if (glfwGetKey(GLFW_KEY_SPACE) == GLFW_PRESS && glfwGetKey(GLFW_KEY_SPACE) == GLFW_PRESS)
			jmpcases = goingup;
		break;
	case goingup:
		tmp1 = objects[1]->Tracking_Points[0].y + jumping_speed;
		if (tmp1 <= max_mov_for_character_in_pos_XYZ.y)
			objects[1]->Translate(glm::vec3(0.0f, jumping_speed, 0.0f));
		else
			jmpcases = maxfly;
		break;
	case maxfly:
		jmpcases = goingdown;
		break;
	case goingdown:
		tmp1 = objects[1]->Tracking_Points[0].y - jumping_speed;
		if(tmp1 >= max_mov_for_character_in_neg_XYZ.y)
			objects[1]->Translate(glm::vec3(0.0f, -jumping_speed, 0.0f));
		if (tmp1 <=0)// if happend that boy gets beyond ground
		{
			objects[1]->Translate(glm::vec3(0.0, -objects[1]->Tracking_Points[0].y, 0.0f));
			jmpcases = onground;
		}
		break;
	default:
		break;
	}



	Draw_all(lightpos);
	
	for (int i = 0; i < objects[2]->Copies_num; i++)
		if (CollisionDetection(*objects[1], *objects[2], 0, i))
			printf("aaaaaaaaaaaaaaa\n");
		

}


lvl1::~lvl1()
{
	for (int i = 0; i < already_loaded; i++)
	{
		delete objects[i];
	}
}
