#include "includes.h"
#include "scene.h"

Scene *instance = NULL;

Scene *Scene::getInstance()
{
    if (instance == NULL)
    {
        instance = new Scene;
    }
    return instance;
}

Scene::Scene()
{
}

void Scene::project()
{
    camera.project();
}

void Scene::render()
{

    camera.setPosition();
    axis.render();

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    vec3 lightColor(1.f, 1.f, 1.0f);
    glLightfv(GL_LIGHT0, GL_POSITION, &lightColor[0]);

    stuff.render();
}

void Scene::keys(int key)
{
    switch (key)
    {
    case 'q':
        exit(0);
        break;
    }

    camera.keys(key);
}
