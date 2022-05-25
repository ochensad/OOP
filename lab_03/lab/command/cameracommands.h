#ifndef CAMERACOMMANDS_H
#define CAMERACOMMANDS_H

#include "basecommand.h"
#include "object/invisible/camera/camera.h"
#include "managers/scene/scenemanagercreator.h"
#include "loader/baseloader.h"
#include "managers/load/loadmanagercreator.h"
#include "loader/cameraloader.h"

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

class LoadCameraCommand : public BaseCameraCommand
{
public:
    LoadCameraCommand() = delete;
    LoadCameraCommand(std::shared_ptr<BaseLoader> &loader, const std::string &fname) : loader(loader), fname(fname) {};
    ~LoadCameraCommand() = default;

    virtual void execute() override
    {
        loader->open(fname);

        auto new_cam = LoadManagerCreator().createManager()->load(std::make_shared<CameraLoader>(loader));
        auto camera =  std::dynamic_pointer_cast<Camera>(new_cam);
        loader->close();

        SceneManagerCreator().createManager()->getScene()->addCamera(camera);
    }

    private:
        std::shared_ptr<BaseLoader> loader;
        std::string fname;
    };


#endif // CAMERACOMMANDS_H
