#include "InitWindow.h"

bool Core::Display::InitWindow(char* windowTitle)
{
	int window_width = 480;
	int window_height = 480;

	// center screen
	int window_x = (glutGet(GLUT_SCREEN_WIDTH) - window_width) / 2;
	int window_y = (glutGet(GLUT_SCREEN_HEIGHT) - window_height) / 2;

	glutInitWindowSize(window_width, window_height);
	glutInitWindowPosition(window_x, window_y);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow(windowTitle);

	// setup GLEW
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return false;
	}

	return true;
}