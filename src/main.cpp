#include "common.h"
#include "glRender.h"
#include "headDetector.h"

int main(int argc, char* argv[])
{
	cout << "Hello World" << endl;
	
	// Test OpenGL initialization
	GLRender::initialize(argc, argv);
	
	GLRender::display();
	
	glutDisplayFunc(GLRender::display);
	
	glutMainLoop();
	
	cout << "Test for changes" << endl;
	
	// Test OpenCV initialization
	// posedetector::HeadDetector* headDetector;
	
	// headDetector->foo();
	
	// cout << "1" << endl;
	// headDetector->initializeCamera();
	// cout << "1" << endl;
	// headDetector->testVideo();
	// cout << "1" << endl;
	
	return 0;
}