#include "transformmanagercreator.h"

using namespace std;

std::shared_ptr<TransformManager> TransformManagerCreator::createManager() {
    if (nullptr == manager) {
        makeInstance();
    }
    return manager;
}

void TransformManagerCreator::makeInstance() {
    static std::shared_ptr<TransformManager> manager(new TransformManager());
    this->manager = manager;
}
