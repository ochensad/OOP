#ifndef POINTS_H
#define POINTS_H

#include "error_code.h"
#include "point.h"
#include <stdio.h>

struct points
{
    int size;
    point_t *points;
};

using points_t = struct points;

struct center
{
    point_t center;
};

using center_t = struct center;


void free_points(points_t &points);
error_code_t read_points_from_file(points_t &points, FILE *f);
center_t calculate_center_point(points_t &points);
error_code_t turn_points(points_t &points, center_t &center ,const turn_t &turn);
error_code_t zoom_points(points_t &points, center_t &center, const zoom_t &zoom);
error_code_t move_points(points_t &points, center_t &center, const move_t &move);

#endif // POINTS_H
