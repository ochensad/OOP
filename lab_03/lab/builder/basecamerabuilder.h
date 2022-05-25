#ifndef BASECAMERABUILDER_H
#define BASECAMERABUILDER_H


#include "object/invisible/camera/camera.h"
#include "basebuilder.h"

class BaseCameraBuilder : public BaseBuilder
{
public:
    BaseCameraBuilder() = default;
    ~BaseCameraBuilder() = default;

    virtual bool isBuild() const = 0;
    virtual void build() = 0;
    virtual void buildCam(double &x, double &y, double &z);

    virtual std::shared_ptr<Camera> get() = 0;
};

#endif // BASECAMERABUILDER_H
