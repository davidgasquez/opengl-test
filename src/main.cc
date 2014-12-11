#include "includes.h"
#include "scene.h"
#include "error.h"

void Reshape(int width, int height) {
  glViewport(0, 0, width, height);
  Scene::getInstance()->project();
  glutPostRedisplay();

  GLError();
}

void DrawScene() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

  Scene::getInstance()->render();

  glutSwapBuffers();
  GLError();
}

void NormalKeys(unsigned char key, int x, int y) {
  Scene::getInstance()->keys(key);
  glutPostRedisplay();
  GLError();
}

void SpecialKeys(int key, int x, int y) {
  Scene::getInstance()->keys(key);
  glutPostRedisplay();
  GLError();
}


int main(int argc, char *argv[]) {
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowPosition( 250, 100);
  glutInitWindowSize(1020, 600);
  glutCreateWindow("Test");

  glutReshapeFunc(Reshape);
  glutDisplayFunc(DrawScene);
  glutKeyboardFunc(NormalKeys);
  glutSpecialFunc(SpecialKeys);

  glClearColor(1, 1, 1, 1);

  glEnable(GL_DEPTH_TEST);

  GLError();

  glutMainLoop();
  return 0;
}
