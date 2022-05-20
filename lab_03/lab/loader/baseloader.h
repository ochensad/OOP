#ifndef BASELOADER_H
#define BASELOADER_H

#include "builder/basebuilder.h"
#include "object/object.h"

class BaseLoader
{
public:
    BaseLoader() = default;
    virtual ~BaseLoader() = default;

    virtual void open(string &fname) = 0;
    virtual void close() = 0;
};

#endif // BASELOADER_H
