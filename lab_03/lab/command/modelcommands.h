#ifndef MODELCOMMANDS_H
#define MODELCOMMANDS_H

#include "basecommand.h"
#include "managers/transform/transformmanagercreator.h"
#include "managers/scene/scenemanagercreator.h"
#include "managers/load/loadmanagercreator.h"
#include "scene/scene.h"
#include "loader/baseloader.h"

#include <algorithm>

class MoveModelCommand : public BaseModelCommand
{
public:
    MoveModelCommand() = delete;
    MoveModelCommand(const double &dx, const double &dy, const double &dz, int index)
    {
        this->cur_index = index;
        Point buf(dx, dy, dz);
        this->move.setPos(buf);
    }
    ~MoveModelCommand() = default;

    virtual void execute() override
    {
        shared_ptr<Object> model = SceneManagerCreator().createManager()->getScene()->getObjects()->getObjects().at(cur_index);
        TransformManagerCreator().createManager()->moveObject(model, move);
    }
private:
    int cur_index;
    Point move;
};

class ScaleModelCommand : public BaseModelCommand
{
public:
    ScaleModelCommand() = delete;
    ScaleModelCommand(const double &kx, const double &ky, const double &kz, int index)
    {
        this->cur_index = index;
        Point buf(kx, ky, kz);
        this->scale.setPos(buf);
    }
    ~ScaleModelCommand() = default;

    virtual void execute() override
    {
        shared_ptr<Object> model = SceneManagerCreator().createManager()->getScene()->getObjects()->getObjects().at(cur_index);
        TransformManagerCreator().createManager()->scaleObject(model, scale);
    }
private:
    int cur_index;
    Point scale;
};

class RotateModelCommand : public BaseModelCommand
{
public:
    RotateModelCommand() = delete;
    RotateModelCommand(const double &kx, const double &ky, const double &kz, int index)
    {
        this->cur_index = index;
        Point buf(kx, ky, kz);
        this->rotate.setPos(buf);
    }
    ~RotateModelCommand() = default;

    virtual void execute() override
    {
        shared_ptr<Object> model = SceneManagerCreator().createManager()->getScene()->getObjects()->getObjects().at(cur_index);
        TransformManagerCreator().createManager()->rotateObject(model, rotate);
    }
private:
    int cur_index;
    Point rotate;
};

class AddModelCommand : public BaseModelCommand
{
public:
    AddModelCommand() = delete;
    AddModelCommand(std::shared_ptr<Object> model) : _model(model) { };
    ~AddModelCommand() = default;

    virtual void execute() override
    {
        SceneManagerCreator().createManager()->getScene()->addObject(_model);
    }
private:
    std::shared_ptr<Object> _model;
};

class RemoveModelCommand : public BaseModelCommand
{
public:
    RemoveModelCommand() = delete;
    RemoveModelCommand(std::shared_ptr<Object> &obj) : obj(obj) {};
    ~RemoveModelCommand() = default;

    virtual void execute() override
    {
        auto it = find(SceneManagerCreator().createManager()->getScene()->getObjects()->begin(), SceneManagerCreator().createManager()->getScene()->getObjects()->end(), obj);
        SceneManagerCreator().createManager()->getScene()->removeObject(it);
    }
private:
    std::shared_ptr<Object> obj;
};

class LoadModelCommand : public BaseModelCommand
{
public:
    LoadModelCommand() = delete;
    LoadModelCommand(std::string conf, const std::string &fname) : config_file(conf), fname(fname) {};
    ~LoadModelCommand() = default;

    virtual void execute() override
    {
        auto moderator = ModelLoadControllerCreator(config_file).createController();
        auto manager = LoadManagerCreator().create_manager(moderator);
        auto new_obj = manager->load_model(fname);
        SceneManagerCreator().createManager()->getScene()->addObject(new_obj);
    }

    private:
        std::string config_file;
        std::string fname;
    };

#endif // MODELCOMMANDS_H
