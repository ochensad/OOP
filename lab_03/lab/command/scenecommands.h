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
    DrawSceneCommand(std::shared_ptr<BaseDrawer> &drawer, int index) : drawer(drawer), index(index) {};
    ~DrawSceneCommand() = default;

    virtual void execute() override
    {
        auto cam = std::make_shared<Camera>(SceneManagerCreator().createManager()->getScene()->getCamera());
        auto sce = SceneManagerCreator().createManager()->getScene();
        auto obj = SceneManagerCreator().createManager()->getScene()->getObjects()->getObjects().at(index);
        DrawManagerCreator().createManager()->setDrawer(drawer);
        DrawManagerCreator().createManager()->setCamera(cam);
        DrawManagerCreator().createManager()->setScene(sce);
        DrawManagerCreator().createManager()->drawObject(obj);
    }

private:
    std::shared_ptr<BaseDrawer> drawer;
    int index;
};

#endif // SCENECOMMANDS_H
