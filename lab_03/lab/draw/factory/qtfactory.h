#ifndef QTFACTORY_H
#define QTFACTORY_H

#include "absgraphfactory.h"
#include "draw/drawers/qtdrawer.h"

class QtFactory : public AbsGraphFactory
{
public:
    QtFactory(std::shared_ptr<QGraphicsScene> &scene, std::shared_ptr<QPen> &pen) : scene(scene), pen(pen) {};
    virtual unique_ptr<BaseDrawer> createGraphics() override
    {
        return unique_ptr<BaseDrawer>(new QtDrawer(scene, pen));
    }
private:
    shared_ptr<QGraphicsScene> scene;
    shared_ptr<QPen> pen;
};

#endif // QTFACTORY_H
