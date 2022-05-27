#include "scenemanager.h"

SceneManager::SceneManager()
{
    scene = std::make_shared<Scene>();
}

std::shared_ptr<Scene> SceneManager::getScene() const
{
    return scene;
}

void SceneManager::setScene(std::shared_ptr<Scene> scene)
{
    this->scene = std::move(scene);
}
