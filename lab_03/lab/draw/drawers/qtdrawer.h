#ifndef QTDRAWER_H
#define QTDRAWER_H

#include <QGraphicsScene>
#include "basedrawer.h"
#include "object/object.h"

class QtDrawer : public BaseDrawer
{
public:
    QtDrawer() : scene(nullptr), pen(nullptr) {};
    QtDrawer(shared_ptr<QGraphicsScene> &scene, shared_ptr<QPen> &pen) : scene(scene), pen(pen) {};
    QtDrawer(const QtDrawer &drawer);

    virtual void drawLine(const Point &point_start, const Point &point_end) override;
    virtual void clearScene() override;
private:
    shared_ptr<QGraphicsScene> scene;
    shared_ptr<QPen> pen;
};

#endif // QTDRAWER_H
