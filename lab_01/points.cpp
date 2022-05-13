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

static error_code_t read_point_coordinates(point_t &point, FILE *f)
{
    if (f == NULL)
        return ERROR_OPENING_FILE;
    if (fscanf(f, "%lf %lf %lf", &point.x, &point.y, &point.z) != 3)
        return ERROR_READING_FILE;
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

    error_code_t er = OK;
    for (int i = 0; i < points.size && (er = read_point_coordinates(points.points[i], f)) == OK; i++)
        ;
    return er;
}

error_code_t read_points_from_file(points_t &points, FILE *f)
{
    if (f == NULL)
        return ERROR_OPENING_FILE;
    error_code_t er = read_points_size(points.size, f);
    if (er == OK)
    {
        er = allocate_points_memory(points);
        if (er == OK)
        {
            er = read_each_point(points, f);
            if (er != OK)
                free_points(points);
        }
    }
    return er;
}

center_t calculate_center_point(points_t &points)
{
    center_t center;
    center.center.x = 0.0;
    center.center.y = 0.0;
    center.center.z = 0.0;

    for(int i = 0; i < points.size; i++)
    {
        center.center.x += points.points[i].x;
        center.center.y += points.points[i].y;
        center.center.z += points.points[i].z;
    }

    center.center.x /= points.size;
    center.center.y /= points.size;
    center.center.z /= points.size;
    return center;
}

error_code_t turn_points(points_t &points, center_t &center ,const turn_t &turn)
{
    if (points.points == NULL)
        return ERROR_NO_LOADING_FIGURE;

    move_t move = {center.center.x, center.center.y, center.center.z};
    move_points(points, center, move);

    for (int i = 0; i < points.size; i++)
    {
        turn_point_x(points.points[i], turn);
        turn_point_y(points.points[i], turn);
        turn_point_z(points.points[i], turn);
    }
    move.dx *= -1;
    move.dy *= -1;
    move.dz *= -1;
    move_points(points, center, move);

    return OK;
}

error_code_t zoom_points(points_t &points, center_t &center, const zoom_t &zoom)
{
    if (points.points == NULL)
        return ERROR_NO_LOADING_FIGURE;
    for(int i = 0; i < points.size; i++)
    {
        zoom_point(points.points[i], zoom);
    }
    zoom_point(center.center, zoom);
    return OK;
}


error_code_t move_points(points_t &points, center_t &center, const move_t &move)
{
    if (points.points == NULL)
        return ERROR_NO_LOADING_FIGURE;
    for (int i = 0; i < points.size; i++)
    {
        move_point(points.points[i], move);
    }
    move_point(center.center, move);
    return OK;
}
