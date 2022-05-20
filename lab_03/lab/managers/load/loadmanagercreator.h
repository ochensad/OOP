#ifndef LOADMANAGERCREATOR_H
#define LOADMANAGERCREATOR_H

#include "loadmanager.h"

class LoadManagerCreator
{
public:
    shared_ptr<LoadManager> createManager();
private:
    void makeInstance();
    shared_ptr<LoadManager> manager;
};

#endif // LOADMANAGERCREATOR_H
