#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

#include "managers/basemanager.h"
#include <memory>
#include "object/object.h"
#include "draw/drawers/basedrawer.h"
#include "object/invisible/camera/camera.h"

class DrawManager : public BaseManager
{
public:
    DrawManager() = default;
    ~DrawManager() = default;

    void drawObject(std::shared_ptr<Object> &obj, std::shared_ptr<BaseDrawer> &drawer, std::shared_ptr<Camera> &camera);
};

#endif // DRAWMANAGER_H
