#include "includes.h"
#include "camera.h"

Camera::Camera()
    : xAngle(0.f), yAngle(0.f), distance(-5.f)
{
    viewMatrix = translate(viewMatrix, vec3(0.f, 0.f, -5.f));
}
void Camera::project()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-.5f * 1.7, .5f * 1.7, -.5f, .5f, 1.f, 1000.f);
}

void Camera::setPosition()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixf(value_ptr(viewMatrix));
}

void Camera::keys(int key)
{
    switch (key)
    {
    case GLUT_KEY_LEFT:
        yAngle--;
        break;
    case GLUT_KEY_RIGHT:
        yAngle++;
        break;
    case GLUT_KEY_UP:
        xAngle--;
        break;
    case GLUT_KEY_DOWN:
        xAngle++;
        break;
    case GLUT_KEY_PAGE_UP:
        distance *= 1.2f;
        break;
    case GLUT_KEY_PAGE_DOWN:
        distance /= 1.2f;
        break;
    }

    //Hacer los cambios en viewMatrix
    viewMatrix = translate(mat4(), vec3(0.f, 0.f, distance));
    viewMatrix = rotate(viewMatrix, xAngle, vec3(1.f, 0.f, 0.f));
    viewMatrix = rotate(viewMatrix, yAngle, vec3(0.f, 1.f, 0.f));

}