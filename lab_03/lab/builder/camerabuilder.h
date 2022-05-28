#ifndef CAMERABUILDER_H
#define CAMERABUILDER_H

#include "basecamerabuilder.h"
#include "object/invisible/camera/camera.h"
#include "exeptions/exeptions.h"

class CameraBuilder
{
public:
    CameraBuilder()
    {
        this->camera_ptr = make_shared<Camera>();
    };
    ~CameraBuilder() = default;

    shared_ptr<Camera> build();

    CameraBuilder buildPos(double &x, double &y, double &z);

private:
    shared_ptr<Camera> camera_ptr;
};

#endif // CAMERABUILDER_H
