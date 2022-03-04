#ifndef POINTS_H
#define POINTS_H

#include "error_code.h"
#include <stdio.h>

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

struct points
{
    int size;
    point_t *points;
};

using points_t = struct points;

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

void free_points(points_t &points);
error_code_t read_points_from_file(points_t &points, FILE *f);
error_code_t turn_points(points_t &points, const turn_t &turn);
error_code_t zoom_points(points_t &points, const zoom_t &zoom);
error_code_t move_points(points_t &points, const move_t &move);

#endif // POINTS_H
