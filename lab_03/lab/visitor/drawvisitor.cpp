#include "drawvisitor.h"

void DrawVisitor::visit(Camera &cam) {}

void DrawVisitor::visit(Model &model)
{
    auto points = model.getStructure()->getPoints();

    for(auto connect: model.getStructure()->getConnections())
    {
        this->drawer->drawLine(scenePoint(points.at(connect.getFirstPoint())), scenePoint(points.at(connect.getSecondPoint())));
    }
}

void DrawVisitor::visit(Composite &composite)
{
    composite.accept(make_shared<DrawVisitor>(*this));
}

void DrawVisitor::setDrawer(std::shared_ptr<BaseDrawer> &drawer)
{
    this->drawer = drawer;
}

void DrawVisitor::setCamera(std::shared_ptr<Camera> &camera)
{
    this->camera = camera;
}

Point DrawVisitor::scenePoint(const Point &_point)
{
    return Point(_point.getX() + camera->getPos().getX() + 571/2, _point.getY() + camera->getPos().getY() + 561/2, _point.getZ());
}
