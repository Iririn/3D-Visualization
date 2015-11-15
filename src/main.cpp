#include "common.h"
#include "glRender.h"
#include "headDetector.h"

int main(int argc, char* argv[])
{
	cout << "Hello World" << endl;
	
	// Test function call
	GLRender::foo();
	HeadDetector::foo();
	
	// Test OpenGL initialize
	GLRender::initialize(argc, argv);
	
	GLRender::display();
	
	glutDisplayFunc(GLRender::display);
	
	glutMainLoop();
	
	
	return 0;
}