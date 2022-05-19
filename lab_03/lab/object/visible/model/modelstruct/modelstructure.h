#ifndef MODELSTRUCTURE_H
#define MODELSTRUCTURE_H

#include <vector>
#include "point.h"
#include "connect.h"

using namespace std;

class ModelStructure
{
public:
    ModelStructure() = default;
    ModelStructure(vector<Point> &points, vector<Connect> &connections);
    ~ModelStructure() = default;

    void addPoint(const Point &p);
    void addConnect(const Connect &c);

    const vector<Point> &getPoints() const;
    const vector<Connect> &getConnections() const;

    void transform(const Point &move_value, const Point &rotate_value, const Point &scale_value);
private:
    vector<Point> points;
    vector<Connect> connections;
};

#endif // MODELSTRUCTURE_H
