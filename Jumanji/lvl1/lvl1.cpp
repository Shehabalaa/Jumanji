#include"Jumanji\lvl1\lvl1.h"

//object boy;
//object girl;
//object oldman;

lvl1::lvl1(int obj_num):lvl(obj_num)
{
	objects = new object*[obj_num];
	lvl_view_matix = glm::lookAt(
		glm::vec3(0.0f, 0.0f, 10.0f),     // Camera is here
		glm::vec3(0.0f, 0.0f, 0.0f), // and looks here : at the same position, plus "direction"
		glm::vec3(0.0f, 1.0f, 0.0f)                 // Head is up (set to 0,-1,0 to look upside-down)
	); 

	lvl_projection_matrix = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);

	this->load("lvl1map.obj ", "lvl1map.bmp", "lvl1map.vertexshader", "lvl1map.fragmentshader");
	objects[0]->Scale(glm::vec3(5,4,1));
	objects[0]->MainModelMatrix = objects[0]->ModelMatrix;
	this->load("treelog.obj", "treelog.bmp", "treelog.vertexshader", "treelog.fragmentshader");
	objects[1]->Rotate(0, pi / 2, 0);
	objects[1]->Translate(glm::vec3(0, 0, 5));
	objects[1]->MainModelMatrix = objects[1]->ModelMatrix;


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

	objects[index]->Draw(lvl_view_matix, lvl_projection_matrix, lightpos);
}

void lvl1::Draw_all(const glm::vec3 & lightpos)
{

	for (int  i = 0; i <already_loaded; i++)
	{
		objects[i]->Draw(lvl_view_matix, lvl_projection_matrix, lightpos);
	}
	
}

void lvl1::computeMatricesFromInputs()
{
	// glfwGetTime is called only once, the first time this function is called
	static double lastTime = glfwGetTime();

	// Compute time difference between current and last frame
	double currentTime = glfwGetTime();
	float deltaTime = float(currentTime - lastTime);

	// Get mouse position
	int xpos, ypos;
	glfwGetMousePos(&xpos, &ypos);

	// Reset mouse position for next frame
	// EDIT : Doesn't work on Mac OS, hence the code below is a bit different from the website's
	//glfwSetMousePos(1024/2, 768/2);

	// Compute new orientation
	horizontalAngle = 3.14f + mouseSpeed * float(1024 / 2 - xpos);
	verticalAngle = mouseSpeed * float(768 / 2 - ypos);

	// Direction : Spherical coordinates to Cartesian coordinates conversion
	glm::vec3 direction(
		cos(verticalAngle) * sin(horizontalAngle),
		sin(verticalAngle),
		cos(verticalAngle) * cos(horizontalAngle)
	);

	// Right vector
	glm::vec3 right = glm::vec3(
		sin(horizontalAngle - 3.14f / 2.0f),
		0,
		cos(horizontalAngle - 3.14f / 2.0f)
	);

	// Up vector
	glm::vec3 up = glm::cross(right, direction);

	// Move forward
	if (glfwGetKey(GLFW_KEY_UP) == GLFW_PRESS) {
		position += direction * deltaTime * speed;
	}
	// Move backward
	if (glfwGetKey(GLFW_KEY_DOWN) == GLFW_PRESS) {
		position -= direction * deltaTime * speed;
	}
	// Strafe right
	if (glfwGetKey(GLFW_KEY_RIGHT) == GLFW_PRESS) {
		position += right * deltaTime * speed;
	}
	// Strafe left
	if (glfwGetKey(GLFW_KEY_LEFT) == GLFW_PRESS) {
		position -= right * deltaTime * speed;
	}

	float FoV = initialFoV - 5 * glfwGetMouseWheel();

	// Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	lvl_projection_matrix = glm::perspective(FoV, 4.0f / 3.0f, 0.1f, 100.0f);
	// Camera matrix
	lvl_view_matix = glm::lookAt(
		position,           // Camera is here
		position + direction, // and looks here : at the same position, plus "direction"
		up                  // Head is up (set to 0,-1,0 to look upside-down)
	);

	// For the next frame, the "last time" will be "now"
	lastTime = currentTime;

}
lvl1::~lvl1()
{
	for (int i = 0; i < already_loaded; i++)
	{
		delete objects[i];
	}
}
