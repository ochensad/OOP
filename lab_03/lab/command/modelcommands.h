#ifndef MODELCOMMANDS_H
#define MODELCOMMANDS_H

#include "basecommand.h"
#include "managers/transform/transformmanagercreator.h"
#include "managers/scene/scenemanagercreator.h"
#include "managers/load/loadmanagercreator.h"
#include "scene/scene.h"
#include "loader/baseloader.h"
#include "loader/modelloader.h"

#include <algorithm>

class MoveModelCommand : public BaseModelCommand
{
public:
    MoveModelCommand() = delete;
    MoveModelCommand(const double &dx, const double &dy, const double &dz, const size_t model_num)
    {
        model_numb = model_num;
        Point buf(dx, dy, dz);
        this->move.setPos(buf);
    }
    ~MoveModelCommand() = default;

    virtual void execute() override
    {
        std::shared_ptr<Object> model = SceneManagerCreator().createManager()->getScene()->getObjects()->getObjects().at(model_numb);
        TransformManagerCreator().createManager()->transformObject(model, move, Point(1, 1, 1), Point(0, 0, 0));
    }
private:
    size_t model_numb;

    Point move;
};

class ScaleModelCommand : public BaseModelCommand
{
public:
    ScaleModelCommand() = delete;
    ScaleModelCommand(const double &kx, const double &ky, const double &kz, const size_t model_num)
    {
        model_numb = model_num;
        Point buf(kx, ky, kz);
        this->scale.setPos(buf);
    }
    ~ScaleModelCommand() = default;

    virtual void execute() override
    {
        std::shared_ptr<Object> model = SceneManagerCreator().createManager()->getScene()->getObjects()->getObjects().at(model_numb);
        TransformManagerCreator().createManager()->transformObject(model, Point(0, 0, 0), scale, Point(0, 0, 0));
    }
private:
    size_t model_numb;

    Point scale;
};

class RotateModelCommand : public BaseModelCommand
{
public:
    RotateModelCommand() = delete;
    RotateModelCommand(const double &kx, const double &ky, const double &kz, const size_t model_num)
    {
        model_numb = model_num;
        Point buf(kx, ky, kz);
        this->rotate.setPos(buf);
    }
    ~RotateModelCommand() = default;

    virtual void execute() override
    {
        std::shared_ptr<Object> model = SceneManagerCreator().createManager()->getScene()->getObjects()->getObjects().at(model_numb);
        TransformManagerCreator().createManager()->transformObject(model, Point(0, 0, 0), Point(1, 1, 1), rotate);
    }
private:
    size_t model_numb;

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
    LoadModelCommand(std::shared_ptr<BaseLoader> &loader, const std::string &fname) : loader(loader), fname(fname) {};
    ~LoadModelCommand() = default;

    virtual void execute() override
    {
        loader->open(fname);

        auto new_obj = LoadManagerCreator().createManager()->load(std::make_shared<ModelLoader>(loader));
        loader->close();

        SceneManagerCreator().createManager()->getScene()->addObject(new_obj);
    }

    private:
        std::shared_ptr<BaseLoader> loader;
        std::string fname;
    };

#endif // MODELCOMMANDS_H
