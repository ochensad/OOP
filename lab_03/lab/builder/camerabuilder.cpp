#include "camerabuilder.h"

bool CameraBuilder::isBuild() const
{
    return this->camera_ptr != nullptr;
}

void CameraBuilder::build()
{
    this->camera_ptr = make_shared<Camera>();
}

void CameraBuilder::buildCam(double &x, double &y, double &z)
{
    this->camera_ptr->setPos(x,y,z);
}

shared_ptr<Camera> CameraBuilder::get()
{
    return this->camera_ptr;
}
