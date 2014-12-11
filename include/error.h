#ifndef ERROR_H__
#define ERROR_H__ value

static void GLError() {
  GLenum error = glGetError();
  if (error != GL_NO_ERROR) {
    cerr << "Error: " << gluErrorString(error) << endl;
    exit(1);
  }
}

#endif
