#include "loadmanager.h"

std::shared_ptr<Object> LoadManager::load(std::shared_ptr<AbsLoadController> loader)
{
    return loader->load();
}
