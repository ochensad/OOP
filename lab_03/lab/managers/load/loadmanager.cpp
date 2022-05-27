#include "loadmanager.h"

std::shared_ptr<Camera> LoadManager::load_camera(std::string &name)
{
    return _loaderCamera->load(name);
}

std::shared_ptr<Object> LoadManager::load_model(std::string name)
{
    return _loaderModel->load(name);
}

void LoadManager::set_loader(std::shared_ptr<CameraLoadController> loader)
{
    _loaderCamera = loader;
}

void LoadManager::set_loader(std::shared_ptr<ModelLoadController> loader)
{
    _loaderModel = loader;
}
