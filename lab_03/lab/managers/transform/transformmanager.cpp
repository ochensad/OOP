#include "transformmanager.h"

void TransformManager::transformObject(shared_ptr<Object> &obj, const Point &move, const Point &scale, const Point &turn)
{
    obj->transform(move, scale, turn);
}
