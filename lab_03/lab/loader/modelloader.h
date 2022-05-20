#ifndef MODELLOADER_H
#define MODELLOADER_H

#include "absloadcontroller.h"
#include "builder/modelbuilder.h"


class ModelLoader : public AbsLoadController
{
public:
    ModelLoader(const std::shared_ptr<BaseLoader> &loader): AbsLoadController(loader) { builder = std::make_shared<ModelBuilder>();};
    ~ModelLoader() = default;

    virtual std::shared_ptr<Object> load() override { return loader->load(this->builder);};

private:
    std::shared_ptr<BaseBuilder> builder;
};

#endif // MODELLOADER_H
