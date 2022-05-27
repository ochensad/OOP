#ifndef MODELLOADCONTROLLERCREATOR_H
#define MODELLOADCONTROLLERCREATOR_H

#include "modelloadcontroller.h"

class ModelLoadControllerCreator
{
public:
    ModelLoadControllerCreator(std::string fname) : name(fname) {};
    std::shared_ptr<ModelLoadController> createController();
    std::shared_ptr<ModelLoadController> createController(const std::shared_ptr<BaseModelLoader> &loader);

private:
    void makeInstance();
    std::shared_ptr<ModelLoadController> _controller;
    std::string name;
};

#endif // MODELLOADCONTROLLERCREATOR_H
