#ifndef BASECAMERABUILDER_H
#define BASECAMERABUILDER_H


#include "object/invisible/camera/camera.h"

class BaseCameraBuilder
{
public:
    BaseCameraBuilder() = default;
    ~BaseCameraBuilder() = default;

    virtual bool isBuild() const = 0;
    virtual void build() = 0;

    virtual std::shared_ptr<Camera> get() = 0;
};

#endif // BASECAMERABUILDER_H
