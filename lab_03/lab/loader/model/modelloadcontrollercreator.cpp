#include "modelloadcontrollercreator.h"
#include "loader/model/modelloader.h"
#include "config/config.h"
#include "exeptions/exeptions.h"

std::shared_ptr<ModelLoadController> ModelLoadControllerCreator::createController() {
    if (nullptr == _controller)
    {
        makeInstance();
    }

    return _controller;
}

std::shared_ptr<ModelLoadController> ModelLoadControllerCreator::createController(const std::shared_ptr<BaseModelLoader> &loader) {
    if (nullptr == _controller) {
        makeInstance();
    }
    _controller->setLoader(loader);
    return _controller;
}

void ModelLoadControllerCreator::makeInstance()
{
    static std::shared_ptr<ModelLoadController> controller;
    if (!controller)
    {
        std::shared_ptr<BaseModelLoader> loader;
        if (name != "")
        {
            GraphLibConfig cr (this->name);
            cr.readConfig();
            if (cr.getLoadSource() == "file")
                loader = std::shared_ptr<BaseModelLoader>(new ModelLoader);
            else
            {
                string em = "Error : config file";
                throw FileError(em);
            }
        }
        else
        {
            string em = "Error : config file";
            throw FileError(em);
        }
        controller = std::make_shared<ModelLoadController>(loader);
    }

    _controller = controller;
}
