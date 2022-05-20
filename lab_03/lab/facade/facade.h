#ifndef FACADE_H
#define FACADE_H

#include "command/basecommand.h"

class Facade
{
public:
    Facade() = default;
    ~Facade() = default;

    void exec(BaseCommand &command);
};

#endif // FACADE_H
