#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

#include "managers/basemanager.h"
#include <memory>
#include "object/object.h"
#include "draw/drawers/basedrawer.h"
#include "object/invisible/camera/camera.h"
#include "visitor/drawvisitor.h"
#include "scene/scene.h"
class DrawManager : public BaseManager
{
public:
    DrawManager() = default;
    DrawManager(const DrawManager &manager) = delete;
    DrawManager &operator = (const DrawManager &manager) = delete;
    ~DrawManager() = default;

    void setCamera(std::shared_ptr<Camera> viewer);
    void setScene(std::shared_ptr<Scene> scene);
    void setDrawer(std::shared_ptr<BaseDrawer> drawer);

    void drawObject(std::shared_ptr<Object> obj);

private:
    std::shared_ptr<BaseDrawer> _drawer;
    std::shared_ptr<Camera> _camera;
    std::shared_ptr<Scene> _scene;
};

#endif // DRAWMANAGER_H
