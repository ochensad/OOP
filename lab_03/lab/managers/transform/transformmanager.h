#ifndef TRANSFORMMANAGER_H
#define TRANSFORMMANAGER_H

#include "managers/basemanager.h"
#include "object/object.h"
#include "object/composite/composite.h"

class TransformManager
{
public:
    TransformManager() = default;
    ~TransformManager() = default;

    void moveObject(shared_ptr<Object> &obj, const Point &move);
    void scaleObject(shared_ptr<Object> &obj,const Point &scale);
    void rotateObject(shared_ptr<Object> &obj, const Point &rotate);
};

#endif // TRANSFORMMANAGER_H
