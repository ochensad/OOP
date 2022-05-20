#ifndef TRANSFORMMANAGERCREATOR_H
#define TRANSFORMMANAGERCREATOR_H

#include "transformmanager.h"

class TransformManagerCreator
{
public:
    shared_ptr<TransformManager> createManager();
private:
    void makeInstance();
    shared_ptr<TransformManager> manager;
};

#endif // TRANSFORMMANAGERCREATOR_H
