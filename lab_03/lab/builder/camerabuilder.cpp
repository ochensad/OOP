#include "camerabuilder.h"

bool CameraBuilder::isBuild() const
{
    return this->camera_ptr != nullptr;
}

void CameraBuilder::build()
{
    this->camera_ptr = make_shared<Camera>();
}

shared_ptr<Camera> CameraBuilder::get()
{
    return this->camera_ptr;
}
