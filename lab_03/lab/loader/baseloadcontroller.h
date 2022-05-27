#ifndef BASELOADCONTROLLER_H
#define BASELOADCONTROLLER_H

#include "baseloader.h"
#include <memory>

class BaseLoadController {
public:
    BaseLoadController() = default;
    ~BaseLoadController() = default;
    virtual void setLoader(std::shared_ptr<BaseLoader> loader)
    {
        _loader = loader;
    }

protected:
    std::shared_ptr<BaseLoader> _loader;
};

#endif // BASELOADCONTROLLER_H
