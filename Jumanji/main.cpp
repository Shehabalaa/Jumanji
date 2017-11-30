#include "Game\Game.h"

int main( void )
{
	Game Jumanji;

	 
	do{

		Jumanji.levels[0]->Draw(0);

		//Swap buffers
		glfwSwapBuffers();

	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey( GLFW_KEY_ESC ) != GLFW_PRESS &&
		   glfwGetWindowParam( GLFW_OPENED ) );



	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}

