#include "Game\Game.h"

int main( void )
{
	Game Jumanji;

	//Jumanji.levels[0]->objects[0]->Translate(glm::vec3(3, -3, 0));
	do{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Jumanji.levels[0]->Draw_all(glm::vec3(0,0,9));


		//Swap buffers
		glfwSwapBuffers();

	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey( GLFW_KEY_ESC ) != GLFW_PRESS &&
		   glfwGetWindowParam( GLFW_OPENED ) );



	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}

