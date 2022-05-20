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
