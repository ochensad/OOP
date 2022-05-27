#include "drawmanager.h"

void DrawManager::setCamera(std::shared_ptr<Camera> viewer) {
    _camera = viewer;
}

void DrawManager::setDrawer(std::shared_ptr<BaseDrawer> drawer) {
    _drawer = drawer;
}

void DrawManager::setScene(std::shared_ptr<Scene> scene) {
    _scene = std::move(scene);
}


void DrawManager::drawObject(std::shared_ptr<Object> obj)
{
    std::shared_ptr<Visitor> visitor(new DrawVisitor(_drawer, _camera));
    obj->accept(visitor);
}
