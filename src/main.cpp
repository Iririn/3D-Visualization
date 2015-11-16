#include "glRender.h"
#include "headDetector.h"

using namespace posedetector;
using namespace glrender;

int main(int argc, char* argv[])
{
	cout << "Hello World" << endl;
	
	// --------------------------
	// Test OpenGL initialization
	// --------------------------
	// initialize(argc, argv);
	
	// display();
	
	// glutDisplayFunc(display);
	
	// glutMainLoop();
	
	
	// --------------------------
	// Test OpenCV initialization
	// --------------------------
	HeadDetector* headDetector = new HeadDetector();
	
	headDetector->foo();
	
	// headDetector.initializeCamera();
	headDetector->testVideo();
	
	return 0;
}