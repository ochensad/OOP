#ifndef MODELLOADCONTROLLER_H
#define MODELLOADCONTROLLER_H

#include "loader/baseloadcontroller.h"
#include "basemodelloader.h"

class ModelLoadController : public BaseLoadController
{
public:
    explicit ModelLoadController(std::shared_ptr<BaseModelLoader> loader);
    ~ModelLoadController() = default;

    std::shared_ptr<Object> load(std::string &file_name);

private:
    std::shared_ptr<ModelBuilder> _builder;
    std::shared_ptr<BaseModelLoader> _loader;
};

#endif // MODELLOADCONTROLLER_H
