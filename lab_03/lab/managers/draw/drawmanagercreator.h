#ifndef DRAWMANAGERCREATOR_H
#define DRAWMANAGERCREATOR_H

#include "drawmanager.h"

class DrawManagerCreator
{
public:
    shared_ptr<DrawManager> createManager();
private:
    void makeInstance();
    shared_ptr<DrawManager> manager;
};

#endif // DRAWMANAGERCREATOR_H
