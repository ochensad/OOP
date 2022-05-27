#ifndef LOADMANAGER_H
#define LOADMANAGER_H

#include "managers/basemanager.h"
#include "loader/baseloader.h"
#include "object/object.h"
#include "loader/camera/cameraloadcontrollercreator.h"
#include "loader/model/modelloadcontrollercreator.h"

class LoadManager : public BaseManager
{
public:
    LoadManager() = default;
    ~LoadManager() = default;

    virtual std::shared_ptr<Object> load_model(std::string name);
    virtual std::shared_ptr<Camera> load_camera(std::string &name);

    virtual void set_loader(std::shared_ptr<CameraLoadController> loader);
    virtual void set_loader(std::shared_ptr<ModelLoadController> loader);

private:
    std::shared_ptr<CameraLoadController> _loaderCamera;
    std::shared_ptr<ModelLoadController> _loaderModel;
};

#endif // LOADMANAGER_H
