#include "qtdrawer.h"

QtDrawer::QtDrawer(const QtDrawer &drawer)
{
    this->scene = drawer.scene;
    this->pen = drawer.pen;
}

void QtDrawer::clearScene()
{
    scene->clear();
}

void QtDrawer::drawLine(const Point &point_start, const Point &point_end)
{
    this->scene->addLine(point_start.getX(), point_start.getY(), point_end.getX(), point_end.getY(), *pen);
}
