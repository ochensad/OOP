#ifndef LOADMANAGERCREATOR_H
#define LOADMANAGERCREATOR_H

#include "loadmanager.h"
#include "loader/camera/cameraloadcontroller.h"
#include "loader/model/modelloadcontroller.h"

class LoadManagerCreator
{
public:
    shared_ptr<LoadManager> createManager();
    std::shared_ptr<LoadManager> create_manager(const std::shared_ptr <CameraLoadController> &loader);
    std::shared_ptr<LoadManager> create_manager(const std::shared_ptr <ModelLoadController> &loader);
private:
    void makeInstance();
    shared_ptr<LoadManager> manager;
};

#endif // LOADMANAGERCREATOR_H
