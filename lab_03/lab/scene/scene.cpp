#include "scene.h"

bool Scene::addObject(std::shared_ptr<Object> &obj)
{
    return this->objects->add(obj);
}

void Scene::removeObject(ObjectIterator &it)
{
    if (it < this->objects->end())
        objects->remove(it);
}

std::shared_ptr<Composite> Scene::getObjects()
{
    return this->objects;
}

vector<std::shared_ptr<Camera>> Scene::getCameras()
{
    return this->cameras;
}

void Scene::addCamera(std::shared_ptr<Camera> &camera)
{
    this->cameras.push_back(camera);
}

void Scene::removeCamera(size_t index)
{
    auto iter = cameras.begin();

    std::advance(iter, index);
    cameras.erase(iter);
}

void Scene::setCamera(size_t index)
{
    this->cur_camera = index;
}

shared_ptr<Camera> Scene::getCamera() const
{
    return this->cameras.at(cur_camera);
}

