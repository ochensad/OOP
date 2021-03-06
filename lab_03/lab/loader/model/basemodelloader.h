#ifndef BASEMODELLOADER_H
#define BASEMODELLOADER_H

#include "loader/baseloader.h"
#include "builder/modelbuilder.h"

class BaseModelLoader : public BaseLoader
{
public:
    virtual std::shared_ptr<Object> load(std::shared_ptr<ModelBuilder> builder) = 0;
};

#endif // BASEMODELLOADER_H
