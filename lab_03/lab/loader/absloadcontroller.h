#ifndef ABSLOADCONTROLLER_H
#define ABSLOADCONTROLLER_H

#include "loader/baseloader.h"
#include "object/object.h"

class AbsLoadController
{
public:
    AbsLoadController(const std::shared_ptr<BaseLoader> &loader) : loader(loader) {};
    ~AbsLoadController() = default;
    virtual std::shared_ptr<Object> load() = 0;
    virtual void setLoader(std::shared_ptr<BaseLoader> loader) { this->loader = loader; };
protected:
    shared_ptr<BaseLoader> loader;
};

#endif // ABSLOADCONTROLLER_H
