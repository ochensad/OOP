#include "camerabuilder.h"

shared_ptr<Camera> CameraBuilder::build()
{
    return this->camera_ptr;
}

CameraBuilder CameraBuilder::buildPos(double &x, double &y, double &z)
{
    this->camera_ptr->setPos(x,y,z);

    return *this;
}
