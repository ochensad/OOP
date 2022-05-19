#ifndef TRANSFORMMANAGER_H
#define TRANSFORMMANAGER_H

#include "managers/basemanager.h"
#include "object/object.h"

class TransformManager
{
public:
    TransformManager() = default;
    ~TransformManager() = default;

    void transformObject(shared_ptr<Object> &obj, const Point &move, const Point &scale, const Point &turn);
};

#endif // TRANSFORMMANAGER_H
