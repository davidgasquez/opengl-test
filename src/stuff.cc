#include "includes.h"
#include "stuff.h"

void Stuff::render()
{
    glColor3f(0.1f, 0.1f, 0.1f);
    glutWireTeapot(1.f);
}