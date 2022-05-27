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

    void move(const Point &move_value);
    void scale(const Point &scale_value);
    void rotate(const Point &rotate_value);
private:
    vector<Point> points;
    vector<Connect> connections;
};

#endif // MODELSTRUCTURE_H
