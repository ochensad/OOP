#ifndef BASEBUILDER_H
#define BASEBUILDER_H

#include <string>

class BaseBuilder
{
public:
    BaseBuilder() = default;
    ~BaseBuilder() = default;

    virtual bool isBuild() const = 0;
    virtual void build() = 0;
};

#endif // BASEBUILDER_H
