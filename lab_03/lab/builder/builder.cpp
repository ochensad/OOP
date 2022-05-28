#include "builder.h"

template<typename Type>

shared_ptr<Type> Builder<Type>::build()
{
    return this->data;
}

template<typename Type>
Builder<Type> Builder<Type>::buildPos(double &x, double &y, double &z)
{
    this->data.s;
    return *this;
}

