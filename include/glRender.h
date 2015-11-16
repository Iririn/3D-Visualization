#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif

#include "common.h"

namespace glrender {

void foo();

// OpenGL initialize function
void initialize(int argc, char* argv[]);

// OpenGL callback function
void display();

}; // end namespace