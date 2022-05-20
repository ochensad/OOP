#ifndef CAMERABUILDER_H
#define CAMERABUILDER_H

#include "basebuilder.h"
#include "object/invisible/camera/camera.h"
#include "exeptions/exeptions.h"

class CameraBuilder : public BaseBuilder
{
public:
    CameraBuilder() : camera_ptr(nullptr) {};
    ~CameraBuilder() = default;

    bool isBuild() const override;
    void build() override;

    shared_ptr<Camera> get();
private:
    shared_ptr<Camera> camera_ptr;
};

#endif // CAMERABUILDER_H
