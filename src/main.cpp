#include "common.h"
#include "glRender.h"
#include "headDetector.h"

int main(int argc, char* argv[])
{
	cout << "Hello World" << endl;
	
	// Test function call
	GLRender::foo();
	
	// Test OpenGL initialization
	// GLRender::initialize(argc, argv);
	
	// GLRender::display();
	
	// glutDisplayFunc(GLRender::display);
	
	// glutMainLoop();
	
	
	// Test OpenCV initialization
	posedetector::HeadDetector* headDetector;
	
	headDetector->initializeCamera();
	cout << "testing" << endl;
	headDetector->testVideo();
	
	return 0;
}