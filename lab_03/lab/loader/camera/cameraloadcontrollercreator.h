#ifndef CAMERALOADCONTROLLERCREATOR_H
#define CAMERALOADCONTROLLERCREATOR_H

#include "cameraloadcontroller.h"

class CameraLoadControllerCreator
{
public:
    CameraLoadControllerCreator(std::string fname) : name(fname) {};
    std::shared_ptr<CameraLoadController> createController();
    std::shared_ptr<CameraLoadController> createController(const std::shared_ptr<BaseCameraLoader> &loader);

private:
    void makeInstance();
    std::shared_ptr<CameraLoadController> _controller;
    std::string name;
};

#endif // CAMERALOADCONTROLLERCREATOR_H
