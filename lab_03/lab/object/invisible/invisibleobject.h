#ifndef INVISIBLEOBJECT_H
#define INVISIBLEOBJECT_H

#include "object/object.h"

class InvisibleObject : public Object
{
public:
    InvisibleObject() = default;
    ~InvisibleObject() = default;

    virtual bool isVisible() const override { return false; }
};

#endif // INVISIBLEOBJECT_H
