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

void Model::transform(const Point &move, const Point &scale, const Point &rotate)
{
    this->structure->transform(move, rotate, scale);
}

void Model::accept(std::shared_ptr<Visitor> visitor)
{
    visitor->visit(*this);
}
