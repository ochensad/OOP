#include "drawmanagercreator.h"

std::shared_ptr<DrawManager> DrawManagerCreator::createManager() {
    if (nullptr == manager) {
        makeInstance();
    }
    return manager;
}

void DrawManagerCreator::makeInstance() {
    static std::shared_ptr<DrawManager> manager(new DrawManager());
    this->manager = manager;
}
