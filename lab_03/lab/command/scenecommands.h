#ifndef SCENECOMMANDS_H
#define SCENECOMMANDS_H

#include "basecommand.h"
#include "draw/drawers/basedrawer.h"
#include "object/object.h"
#include "managers/scene/scenemanagercreator.h"
#include "managers/draw/drawmanagercreator.h"

class DrawSceneCommand : public BaseSceneCommand
{
public:
    DrawSceneCommand() = delete;
    DrawSceneCommand(std::shared_ptr<BaseDrawer> &drawer, std::shared_ptr<Object> &obj) : drawer(drawer), obj(obj) {};
    ~DrawSceneCommand() = default;

    virtual void execute() override
    {
        auto cam = std::make_shared<Camera>(SceneManagerCreator().createManager()->getCamera()->getPos());
        std::shared_ptr<Visitor> draw_visitor = std::make_shared<DrawVisitor>(drawer, cam);

        DrawManagerCreator().createManager()->drawObject(obj, drawer, cam);
    }

private:
    std::shared_ptr<BaseDrawer> drawer;
    std::shared_ptr<Object> obj;
};

#endif // SCENECOMMANDS_H
