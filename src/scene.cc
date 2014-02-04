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
