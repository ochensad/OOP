#ifndef ABSGRAPHFACTORY_H
#define ABSGRAPHFACTORY_H

#include "draw/drawers/basedrawer.h"
#include <memory>

class AbsGraphFactory
{
public:
    virtual std::unique_ptr<BaseDrawer> createGraphics() = 0;
};

#endif // ABSGRAPHFACTORY_H
