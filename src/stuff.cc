#include "includes.h"
#include "stuff.h"

void Stuff::render()
{
    glTranslatef(0.f, 0.75f, 0.0f);
    glutSolidTeapot(1.f);
}