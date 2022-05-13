#include "point.h"

void move_point(point_t &point, const move_t &move)
{
    point.x += move.dx;
    point.y += move.dy;
    point.z += move.dz;
}

void zoom_point(point_t &point, const zoom_t &zoom)
{
    point.x *= zoom.kx;
    point.y *= zoom.ky;
    point.z *= zoom.kz;
}

void turn_point_x(point_t &point, const turn_t &turn)
{
    double f_cos = cos(TO_RADIANS(turn.f_x));
    double f_sin = sin(TO_RADIANS(turn.f_x));
    double tmp_y = point.y;
    point.y = point.y * f_cos + point.z * f_sin;
    point.z = - tmp_y * f_sin + point.z * f_cos;
    return;
}

void turn_point_y(point_t &point, const turn_t &turn)
{
    double f_cos = cos(TO_RADIANS(turn.f_y));
    double f_sin = sin(TO_RADIANS(turn.f_y));
    double tmp_x = point.x;
    point.x = point.x * f_cos + point.z * f_sin;
    point.z = - tmp_x  * f_sin + point.z * f_cos;
    return;
}

void turn_point_z(point_t &point, const turn_t &turn)
{
    double f_cos = cos(TO_RADIANS(turn.f_z));
    double f_sin = sin(TO_RADIANS(turn.f_z));
    double tmp_x = point.x;
    point.x = point.x  * f_cos + point.y * f_sin;
    point.y = - tmp_x * f_sin + point.y  * f_cos;
    return;
}
