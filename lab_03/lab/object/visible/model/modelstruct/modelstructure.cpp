#include "modelstructure.h"

ModelStructure::ModelStructure(vector<Point> &points, vector<Connect> &connections)
{
    this->points = points;
    this->connections = connections;
}

void ModelStructure::addPoint(const Point &p)
{
    this->points.push_back(p);
}

void ModelStructure::addConnect(const Connect &c)
{
    this->connections.push_back(c);
}

const vector<Point> &ModelStructure::getPoints() const
{
    return this->points;
}

const vector<Connect> &ModelStructure::getConnections() const
{
    return this->connections;
}

void ModelStructure::transform(const Point &move_value, const Point &rotate_value, const Point &scale_value)
{
    for(auto &point: this->points)
    {
        point.move(move_value.getX(), move_value.getY(), move_value.getZ());
        point.scale(scale_value.getX(), scale_value.getY(), scale_value.getZ());
        point.rotate(rotate_value.getX(), rotate_value.getY(), rotate_value.getZ());
    }
}
