#ifndef SCENEMANAGERCREATOR_H
#define SCENEMANAGERCREATOR_H

#include "scenemanager.h"

class SceneManagerCreator
{
public:
    shared_ptr<SceneManager> createManager();
private:
    void makeInstance();
    shared_ptr<SceneManager> manager;
};
#endif // SCENEMANAGERCREATOR_H
