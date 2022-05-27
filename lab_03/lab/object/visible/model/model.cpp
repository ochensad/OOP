#include "model.h"

Model::Model(const Model &model)
{
    this->structure = model.getStructure();
}

void Model::addPoint(const Point &point)
{
    this->structure->addPoint(point);
}

void Model::addConnect(const Connect &connect)
{
    this->structure->addConnect(connect);
}

void Model::move(const Point &move)
{
    this->structure->move(move);
}

void Model::scale(const Point &scale)
{
    this->structure->scale(scale);
}

void Model::rotate(const Point &rotate)
{
    this->structure->rotate(rotate);
}

void Model::accept(std::shared_ptr<Visitor> visitor)
{
    visitor->visit(*this);
}
