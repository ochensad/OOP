#ifndef CAMERABUILDER_H
#define CAMERABUILDER_H

#include "basecamerabuilder.h"
#include "object/invisible/camera/camera.h"
#include "exeptions/exeptions.h"

class CameraBuilder : public BaseBuilder
{
public:
    CameraBuilder() : camera_ptr(nullptr) {};
    ~CameraBuilder() = default;

    bool isBuild() const override;
    void build() override;

    void buildCam(double &x, double &y, double &z);

    virtual shared_ptr<Camera> get();
private:
    shared_ptr<Camera> camera_ptr;
};

#endif // CAMERABUILDER_H
