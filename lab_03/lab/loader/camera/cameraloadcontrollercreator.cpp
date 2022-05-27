#include "cameraloadcontrollercreator.h"

#include "config/config.h"
#include "exeptions/exeptions.h"
#include "cameraloader.h"

std::shared_ptr<CameraLoadController> CameraLoadControllerCreator::createController() {
    if (nullptr == _controller) {
        makeInstance();
    }

    return _controller;
}

std::shared_ptr<CameraLoadController> CameraLoadControllerCreator::createController(const std::shared_ptr<BaseCameraLoader> &loader) {
    if (nullptr == _controller) {
        makeInstance();
    }
    _controller->setLoader(loader);
    return _controller;
}

void CameraLoadControllerCreator::makeInstance()
{
    static std::shared_ptr<CameraLoadController> controller;
    if (!controller)
    {
        std::shared_ptr<BaseCameraLoader> loader;
        if (name != "")
        {
            GraphLibConfig cr (this->name);
            cr.readConfig();
            if (cr.getLoadSource() == "file")
                loader = std::shared_ptr<BaseCameraLoader>(new CameraLoader);
            else
            {
                string em = "Error : config file";
                throw FileError(em);
            }
        }
        else
        {
            string em = "Error : config file";
            throw FileError(em);
        }
        controller = std::make_shared<CameraLoadController>(loader);
    }

    _controller = controller;
}
