#ifndef LOADMANAGER_H
#define LOADMANAGER_H

#include "managers/basemanager.h"
#include "loader/absloadcontroller.h"

class LoadManager : public BaseManager
{
public:
    LoadManager() = default;
    ~LoadManager() = default;

    shared_ptr<Object> load(shared_ptr<AbsLoadController> loader);
};

#endif // LOADMANAGER_H
