#include "scenemanager.h"

SceneManager::SceneManager()
{
    scene = std::make_shared<Scene>();
}

std::shared_ptr<Scene> SceneManager::getScene() const
{
    return scene;
}

std::shared_ptr<Camera> SceneManager::getCamera() const
{
    return camera;
}

void SceneManager::setScene(std::shared_ptr<Scene> scene)
{
    this->scene = std::move(scene);
}

void SceneManager::setCamera(const size_t camera_id)
{
    auto camera = scene->getCameras().at(camera_id);
    this->camera = camera;
}
