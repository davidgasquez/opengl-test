#ifndef SCENE_H__
#define SCENE_H__ value

#include "axis.h"
#include "camera.h"
#include "stuff.h"

class Scene {
public:
  static Scene *getInstance();
  void project();
  void render();
  void keys(int key);

private:
  Scene();
  Axis axis;
  Camera camera;
  Stuff stuff;
};

#endif
