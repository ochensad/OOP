#include "loadmanagercreator.h"

std::shared_ptr<LoadManager> LoadManagerCreator::createManager() {
    if (nullptr == manager) {
        makeInstance();
    }
    return manager;
}

void LoadManagerCreator::makeInstance() {
    static std::shared_ptr<LoadManager> manager(new LoadManager());
    this->manager = manager;
}

std::shared_ptr<LoadManager> LoadManagerCreator::create_manager(const std::shared_ptr <CameraLoadController> &loader) {
    if (nullptr == manager) {
        makeInstance();
    }
    manager->set_loader(loader);
    return manager;
}

std::shared_ptr<LoadManager> LoadManagerCreator::create_manager(const std::shared_ptr <ModelLoadController> &loader) {
    if (nullptr == manager) {
        makeInstance();
    }
    manager->set_loader(loader);
    return manager;
}
