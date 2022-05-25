#ifndef CAMERALOADER_H
#define CAMERALOADER_H

#include "absloadcontroller.h"
#include "builder/camerabuilder.h"


class CameraLoader : public AbsLoadController
{
public:
    CameraLoader(const std::shared_ptr<BaseLoader> &loader): AbsLoadController(loader) { builder = std::make_shared<CameraBuilder>();};
    ~CameraLoader() = default;

    virtual std::shared_ptr<Object> load() override { return loader->load(this->builder);};

private:
    std::shared_ptr<BaseBuilder> builder;
};

#endif // CAMERALOADER_H
