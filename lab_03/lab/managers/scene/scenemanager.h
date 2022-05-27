#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "scene/scene.h"

class SceneManager
{
public:
    SceneManager();
    ~SceneManager() = default;

    shared_ptr<Scene> getScene() const;

    void setScene(shared_ptr<Scene>);
protected:
    shared_ptr<Scene> scene;
};

#endif // SCENEMANAGER_H
