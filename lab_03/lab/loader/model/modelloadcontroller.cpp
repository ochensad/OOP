#include "modelloadcontroller.h"

ModelLoadController::ModelLoadController(std::shared_ptr<BaseModelLoader> loader) : _builder(new ModelBuilder)
{
    _loader = loader;
}

std::shared_ptr<Object> ModelLoadController::load(std::string &file_name) {
    try {
        _loader->open(file_name);
    }
    catch (FileError &error) {
        std::string msg = "Error : Open file";
        throw FileError(msg);
    }

    std::shared_ptr<Object> model;

    try {
        model = _loader->load(_builder);
    }
    catch (std::exception &error) {
        std::string msg = "Error : Read model";
        throw FileError(msg);
    }

    _loader->close();

    return model;
}
