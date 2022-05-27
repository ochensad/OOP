#ifndef CAMERALOADCONTROLLER_H
#define CAMERALOADCONTROLLER_H

#include "loader/baseloadcontroller.h"
#include "basecameraloader.h"

class CameraLoadController : public BaseLoadController
{
public:
    explicit CameraLoadController(std::shared_ptr<BaseCameraLoader> loader);
    ~CameraLoadController() = default;

    std::shared_ptr<Camera> load(std::string &file_name);

private:
    std::shared_ptr<CameraBuilder> _builder;
    std::shared_ptr<BaseCameraLoader> _loader;
};

#endif // CAMERALOADCONTROLLER_H
