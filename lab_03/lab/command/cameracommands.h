#ifndef CAMERACOMMANDS_H
#define CAMERACOMMANDS_H

#include "basecommand.h"
#include "object/invisible/camera/camera.h"
#include "managers/scene/scenemanagercreator.h"
#include "loader/baseloader.h"
#include "managers/load/loadmanagercreator.h"

class SetCameraCommand : public BaseCameraCommand
{
public:
    SetCameraCommand() = delete;
    ~SetCameraCommand() = default;

    SetCameraCommand(size_t camera_n) : camera_num(camera_n) {};

    virtual void execute() override
    {
        SceneManagerCreator().createManager()->getScene()->setCamera(camera_num);
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
    LoadCameraCommand(const std::string conf, const std::string &fname) : config_file(conf), fname(fname) {};
    ~LoadCameraCommand() = default;

    virtual void execute() override
    {
        auto moderator = CameraLoadControllerCreator(config_file).createController();
        auto manager = LoadManagerCreator().create_manager(moderator);
        auto new_obj = manager->load_camera(fname);
        SceneManagerCreator().createManager()->getScene()->addCamera(new_obj);
    }

private:
    std::string config_file;
    std::string fname;
};

class MoveCameraCommand : public BaseCameraCommand
{
public:
    MoveCameraCommand() = delete;
    ~MoveCameraCommand() = default;

    MoveCameraCommand(int index_n, double dx, double dy) : index(index_n)
    {
      Point buf(dx, dy, 0.0);
      move = buf;
    };

    virtual void execute() override
    {
        SceneManagerCreator().createManager()->getScene()->getCameras().at(index)->move(move);
    }

private:
    int index;
    Point move;
};


#endif // CAMERACOMMANDS_H
