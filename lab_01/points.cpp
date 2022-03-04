#include "points.h"
#include <stdlib.h>


void free_points(points_t &points)
{
    free(points.points);
    points.points = NULL;
    points.size = 0;
}

error_code_t allocate_points_memory(points_t &points)
{
    if (points.size <= 0)
        return ERROR_POINTS_SIZE;
    point_t *tmp = (point_t*) malloc(points.size * sizeof(point_t));
    if (tmp == NULL)
        return ERROR_MEMORY;
    points.points = tmp;
    return OK;
}

static error_code_t read_points_size(int &size, FILE *f)
{
    if (f == NULL)
        return ERROR_OPENING_FILE;
    if (fscanf(f, "%d", &size) != 1)
        return ERROR_READING_FILE;
    if (size <= 0)
        return ERROR_POINTS_SIZE;
    return OK;
}

static error_code_t read_each_point(points_t &points, FILE *f)
{
    if (f == NULL)
        return ERROR_OPENING_FILE;
    else if (points.size <= 0)
        return ERROR_POINTS_SIZE;
    else if (points.points == NULL)
        return ERROR_MEMORY;

    for (int i = 0; i < points.size; i++)
    {
        if (fscanf(f, "%lf %lf %lf", &(points.points[i].x), &(points.points[i].y), &(points.points[i].z)) != 3)
            return ERROR_READING_FILE;
        printf("%lf ", points.points[i].x);
    }
    return OK;
}

error_code_t read_points_from_file(points_t &points, FILE *f)
{
    if (f == NULL)
        return ERROR_OPENING_FILE;
    error_code_t er = read_points_size(points.size, f);
    if (er)
        return er;
    er = allocate_points_memory(points);
    if (er)
        return ERROR_MEMORY;
    er = read_each_point(points, f);
    if (er)
        free_points(points);
    return er;
}

static void turn_point(point_t &point, const double &f, const char mode)
{
    double f_cos = cos(TO_RADIANS(f));
    double f_sin = sin(TO_RADIANS(f));

    if (mode == 'x')
    {
        double tmp_y = point.y;
        point.y = point.y * f_cos + point.z * f_sin;
        point.z = - tmp_y * f_sin + point.z * f_cos;
        return;
    }
    else if (mode == 'y')
    {
        double tmp_x = point.x;
        point.x = point.x * f_cos + point.z * f_sin;
        point.z = - tmp_x * f_sin + point.z * f_cos;
        return;
    }
    else if (mode == 'z')
    {
        double tmp_x = point.x;
        point.x = point.x * f_cos + point.y * f_sin;
        point.y = - tmp_x * f_sin + point.y * f_cos;
        return;
    }
}

error_code_t turn_points(points_t &points, const turn_t &turn)
{
    if (points.points == NULL)
        return ERROR_NO_LOADING_FIGURE;
    for (int i = 0; i < points.size; i++)
    {
        turn_point(points.points[i], turn.f_x, 'x');
        turn_point(points.points[i], turn.f_y, 'y');
        turn_point(points.points[i], turn.f_z, 'z');
    }
    return OK;
}

error_code_t zoom_points(points_t &points, const zoom_t &zoom)
{
    if (points.points == NULL)
        return ERROR_NO_LOADING_FIGURE;
    for(int i = 0; i < points.size; i++)
    {
        points.points[i].x *= zoom.kx;
        points.points[i].y *= zoom.ky;
        points.points[i].z *= zoom.kz;
    }
    return OK;
}

error_code_t move_points(points_t &points, const move_t &move)
{
    if (points.points == NULL)
        return ERROR_NO_LOADING_FIGURE;
    for (int i = 0; i < points.size; i++)
    {
        points.points[i].x += move.dx;
        points.points[i].y += move.dy;
        points.points[i].z += move.dz;
    }
    return OK;
}
