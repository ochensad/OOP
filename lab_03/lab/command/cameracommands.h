#ifndef CAMERACOMMANDS_H
#define CAMERACOMMANDS_H

#include "basecommand.h"
#include "object/invisible/camera/camera.h"
#include "managers/scene/scenemanagercreator.h"

class SetCameraCommand : public BaseCameraCommand
{
public:
    SetCameraCommand() = delete;
    ~SetCameraCommand() = default;

    SetCameraCommand(size_t camera_n) : camera_num(camera_n) {};

    virtual void execute() override
    {
        SceneManagerCreator().createManager()->setCamera(camera_num);
    }

private:
    size_t camera_num;
};

class RemoveCameraCommand : public BaseCameraCommand
{
public:
    RemoveCameraCommand() = delete;
    ~RemoveCameraCommand() = default;

    RemoveCameraCommand(size_t camera_n) : camera_num(camera_n) {};

    virtual void execute() override
    {
        SceneManagerCreator().createManager()->getScene()->removeCamera(camera_num);
    }

private:
    size_t camera_num;
};

class AddCameraCommand : public BaseCameraCommand
{
public:
    AddCameraCommand() = delete;
    ~AddCameraCommand() = default;

    AddCameraCommand(std::shared_ptr<Camera> camera = nullptr) : camera(camera) {};

    virtual void execute() override
    {
        SceneManagerCreator().createManager()->getScene()->addCamera(camera);
    }

private:
    std::shared_ptr<Camera> camera {nullptr};
};


#endif // CAMERACOMMANDS_H
