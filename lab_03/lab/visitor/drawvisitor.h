#ifndef DRAWVISITOR_H
#define DRAWVISITOR_H

#include "visitor.h"
#include "draw/drawers/basedrawer.h"
#include "object/visible/model/model.h"
#include "object/composite/composite.h"
#include "object/invisible/camera/camera.h"


class DrawVisitor : public Visitor
{
public:
    DrawVisitor(shared_ptr<BaseDrawer> &drawer, shared_ptr<Camera> &camera) : drawer(drawer), camera(camera) {};

    virtual void visit(Camera &cam) override;
    virtual void visit(Model &model) override;
    virtual void visit(Composite &composite) override;

    void setDrawer(std::shared_ptr<BaseDrawer> &drawer);
    void setCamera(std::shared_ptr<Camera> &camera);

private:
    std::shared_ptr<BaseDrawer> drawer;
    std::shared_ptr<Camera> camera;

    Point scenePoint(const Point &point);
};

#endif // DRAWVISITOR_H
