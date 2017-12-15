#include "Game\Game.h"

int main( void )
{
	Game Jumanji;
	bool start = 0;
	//Jumanji.levels[0]->objects[0]->Translate(glm::vec3(3, -3, 0));
	do {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
		start = start || glfwGetKey(GLFW_KEY_ENTER) == GLFW_PRESS;
		if (start)
			Jumanji.levels[0]->Play(glm::vec3(0, 3, 3));

		//Jumanji.levels[1]->Draw_all(glm::vec3(0, 0, 10));


		//Swap buffers
		glfwSwapBuffers();

	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey( GLFW_KEY_ESC ) != GLFW_PRESS &&
		   glfwGetWindowParam( GLFW_OPENED ) );



	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}

