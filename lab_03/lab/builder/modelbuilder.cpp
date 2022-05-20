#include "modelbuilder.h"

bool ModelBuilder::isBuild() const
{
    return this->model_ptr != nullptr;
}

void ModelBuilder::build()
{
    this->model_ptr = make_shared<Model>();
}

void ModelBuilder::buildPoint(const double &x, const double &y, const double &z)
{
    if (!this->isBuild())
    {
        string s = "Model pointer doesn't exist";
        throw ModelError(s);
    }

    Point p_obj(x, y, z);
    this->model_ptr->addPoint(p_obj);
}

void ModelBuilder::buildConnect(const size_t &p_1, const size_t &p_2)
{
    if (!this->isBuild())
    {
        string s = "Model pointer doesn't exist";
        throw ModelError(s);
    }

    Connect c_obj(p_1, p_2);
    this->model_ptr->addConnect(c_obj);
}

shared_ptr<Model> ModelBuilder::get()
{
    return this->model_ptr;
}
