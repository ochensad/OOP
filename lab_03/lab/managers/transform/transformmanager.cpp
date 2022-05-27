#include "transformmanager.h"

void TransformManager::moveObject(shared_ptr<Object> &obj, const Point &move)
{
    obj->move(move);
}

void TransformManager::scaleObject(shared_ptr<Object> &obj, const Point &scale)
{
    obj->scale(scale);
}

void TransformManager::rotateObject(shared_ptr<Object> &obj, const Point &rotate)
{
    obj->rotate(rotate);
}
