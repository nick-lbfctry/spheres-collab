#include <gl/glew.h>
#include <gl/freeglut.h>
#include "Core\GameState.h"

void display(void);

Core::GameState gameState;

//-------------------------------------------------------------------------
//  Program Main method.
//-------------------------------------------------------------------------
void main(int argc, char **argv)
{
	//  Connect to the windowing system + create a window
	//  with the specified dimensions and position
	//  + set the display mode + specify the window title.
	glutInit(&argc, argv);
	gameState.Init();

	// Set the callback functions
	glutDisplayFunc(display);

	//  Start GLUT event processing loop
	glutMainLoop();
}


//-------------------------------------------------------------------------
//  This function is passed to glutDisplayFunc in order to display 
//  OpenGL contents on the window.
//-------------------------------------------------------------------------
void display(void)
{
	//  Clear the window or more specifically the frame buffer...
	//  This happens by replacing all the contents of the frame
	//  buffer by the clear color (black in our case)
	glClear(GL_COLOR_BUFFER_BIT);

	//  Draw object
	gameState.Render();	

	//  Swap contents of backward and forward frame buffers
	glutSwapBuffers();
}