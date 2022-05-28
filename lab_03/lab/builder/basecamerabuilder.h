#ifndef BASECAMERABUILDER_H
#define BASECAMERABUILDER_H


#include "object/invisible/camera/camera.h"
#include "basebuilder.h"

class BaseCameraBuilder : public BaseBuilder
{
public:
    BaseCameraBuilder() = default;
    ~BaseCameraBuilder() = default;

    virtual void build() = 0;
    virtual std::shared_ptr<BaseCameraBuilder> buildPos(double &x, double &y, double &z);

    //virtual std::shared_ptr<Camera> get() = 0;
};

#endif // BASECAMERABUILDER_H
