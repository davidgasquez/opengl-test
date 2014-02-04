#include "includes.h"
#include "scene.h"
#include "error.h"

void Reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    Scene::getInstance()->project();
    glutPostRedisplay();

    GLError();  //Comprobación de errores
}

void DrawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    Scene::getInstance()->render();

    glutSwapBuffers();
    GLError();  //Comprobación de errores
}

void NormalKeys(unsigned char key, int x, int y)
{
    Scene::getInstance()->keys(key);
    glutPostRedisplay();
    GLError();  //Comprobación de errores
}

void SpecialKeys(int key, int x, int y)
{
    Scene::getInstance()->keys(key);
    glutPostRedisplay();
    GLError();  //Comprobación de errores
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv); //Inicializar Glut

    // Las posibilidades son:
    // GLUT_SIMPLE -> memoria de imagen simple
    // GLUT_DOUBLE -> memoria de imagen doble
    // GLUT_INDEX -> memoria de imagen con color indizado
    // GLUT_RGB -> memoria de imagen con componentes rojo, verde y azul para cada pixel
    // GLUT_RGBA -> memoria de imagen con componentes rojo, verde, azul y alfa para cada pixel
    // GLUT_DEPTH -> memoria de profundidad o z-bufer
    // GLUT_STENCIL -> memoria de estarcido
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition( 250, 100);
    glutInitWindowSize(1020, 600);  // Tamaño de la ventana (ancho y alto)
    glutCreateWindow("Practica 1");

    glutReshapeFunc(Reshape);   //Asigna la función para que cuando cambie el tamaño de la ventana, la pueda llamar.
    glutDisplayFunc(DrawScene); //Asigna de la funcion llamada "dibujar" al evento de dibujo.
    glutKeyboardFunc(NormalKeys);
    glutSpecialFunc(SpecialKeys);

    glClearColor(1, 1, 1, 1);   //Blanco

    glEnable(GL_DEPTH_TEST);

    GLError();

    glutMainLoop(); // Bucle de eventos [Eventos,Actualizar,Pintar]
    return 0;
}