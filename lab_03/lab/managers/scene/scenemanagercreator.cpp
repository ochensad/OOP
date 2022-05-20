#include "scenemanagercreator.h"

std::shared_ptr<SceneManager> SceneManagerCreator::createManager() {
    if (nullptr == manager) {
        makeInstance();
    }
    return manager;
}

void SceneManagerCreator::makeInstance() {
    static std::shared_ptr<SceneManager> manager(new SceneManager());
    this->manager = manager;
}
