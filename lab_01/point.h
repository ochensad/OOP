#ifndef POINT_H
#define POINT_H

#endif // POINT_H

#include <cmath>
#define PI M_PI
#define TO_RADIANS(angle) ((angle) * PI / 180)

struct point
{
    double x;
    double y;
    double z;
};

using point_t = struct point;

struct turn
{
    double f_x;
    double f_y;
    double f_z;
};

using turn_t = struct turn;

struct move
{
    double dx;
    double dy;
    double dz;
};

using move_t = struct move;

struct zoom
{
    double kx;
    double ky;
    double kz;
};

using zoom_t = struct zoom;

void turn_point_z(point_t &point, const turn_t &turn);
void turn_point_y(point_t &point, const turn_t &turn);
void turn_point_x(point_t &point, const turn_t &turn);
void move_point(point_t &point, const move_t &move);
void zoom_point(point_t &point, const zoom_t &zoom);
