#include "includes.h"
#include "axis.h"

const int AXIS_SIZE = 5000;

void Axis::render()
{
    glBegin(GL_LINES);
	    glColor3f(1, 0, 0); 
	    glVertex3f(-AXIS_SIZE, 0, 0);
	    glVertex3f(AXIS_SIZE, 0, 0);

	    glColor3f(0, 1, 0);
	    glVertex3f(0, -AXIS_SIZE, 0);
	    glVertex3f(0, AXIS_SIZE, 0);

	    glColor3f(0, 0, 1);
	    glVertex3f(0, 0, -AXIS_SIZE);
	    glVertex3f(0, 0, AXIS_SIZE);
    glEnd();
}