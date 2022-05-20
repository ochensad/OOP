#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "scene/scene.h"

class SceneManager
{
public:
    SceneManager();
    ~SceneManager() = default;

    shared_ptr<Scene> getScene() const;
    shared_ptr<Camera> getCamera() const;

    void setScene(shared_ptr<Scene>);
    void setCamera(const size_t camera_id);
protected:
    shared_ptr<Camera> camera;
    shared_ptr<Scene> scene;
};

#endif // SCENEMANAGER_H
