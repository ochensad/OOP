#ifndef BUILDER_H
#define BUILDER_H

#include "basebuilder.h"


template<typename Type>
class Builder : public BaseBuilder
{
public:
    Builder()
    {
        this->data = make_shared<Type>();
    };
    shared_ptr<Type> build();
    Builder buildPos(double &x, double &y, double &z);

private:
    shared_ptr<Type> data;
};

#endif // BUILDER_H
