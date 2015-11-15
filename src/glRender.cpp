#include "glRender.h"

namespace GLRender {

void foo() 
{
	cout << "Calling function in glRender.cpp" << endl;
}

void initialize(int argc, char* argv[])
{
	// Initialize
	glutInit(&argc,argv);
	
	// Request double buffered true color window with z-buffer
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	
	// Create window
	glutCreateWindow("Cube");
	
	// Enable depth buffer
	glEnable(GL_DEPTH_TEST);
}

void display()
{
	//  Clear screen and Z-buffer
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	// Reset transformations
	glLoadIdentity();
	  
	glBegin(GL_POLYGON);
	glColor3f( 1.0, 0.0, 0.0 );    glVertex3f(  0.5, -0.5, -0.5 );	// P1 is red
	glColor3f( 0.0, 1.0, 0.0 );    glVertex3f(  0.5,  0.5, -0.5 );	// P2 is green
	glColor3f( 0.0, 0.0, 1.0 );    glVertex3f( -0.5,  0.5, -0.5 );	// P3 is blue
	glColor3f( 1.0, 0.0, 1.0 );    glVertex3f( -0.5, -0.5, -0.5 );	// P4 is purple
	glEnd();
	
	glFlush();
	glutSwapBuffers();
}

// void specialKeys(int key, int x, int y)
// {
	
// }




}; //end namespace