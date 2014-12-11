#ifndef CAMERA_H__
#define CAMERA_H__ value

class Camera {
public:
  Camera();
  void project();
  void setPosition();
  void keys(int key);

private:
  mat4 viewMatrix;
  float xAngle, yAngle, distance;
};

#endif
