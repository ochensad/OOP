#ifndef BASEBUILDER_H
#define BASEBUILDER_H

#include <string>

#include "object/visible/model/model.h"

class BaseBuilder
{
public:
    BaseBuilder() = default;
    ~BaseBuilder() = default;

    virtual bool isBuild() const = 0;
    virtual void build() = 0;

    virtual void buildPoint(const double &x, const double &y, const double &z) = 0;
    virtual void buildConnect(const size_t &pt1, const size_t &pt2) = 0;
    virtual std::shared_ptr<Model> get() = 0;
};

#endif // BASEBUILDER_H
