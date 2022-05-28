#include "cameraloadcontroller.h"

CameraLoadController::CameraLoadController(std::shared_ptr<BaseCameraLoader> loader)
{
    _loader = loader;
    _builder = make_shared<CameraBuilder>();
}

std::shared_ptr<Camera> CameraLoadController::load(std::string &file_name) {
    try {
        _loader->open(file_name);
    }
    catch (FileError &error) {
        std::string msg = "Error : Open file";
        throw FileError(msg);
    }

    std::shared_ptr<Camera> model;

    try {
        model = _loader->load(_builder);
    }
    catch (std::exception &error) {
        std::string msg = "Error : Read model";
        throw FileError(msg);
    }

    _loader->close();

    return model;
}
