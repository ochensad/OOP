#include "figure.h"
#include <stdio.h>

figure_t figure_init(void)
{
    static figure_t tmp;
    tmp.points.size = 0;
    tmp.points.points = NULL;

    tmp.conections.size = 0;
    tmp.conections.conections = NULL;
    return tmp;
}

void free_figure(figure_t &figure)
{
    free_points(figure.points);
    free_conections(figure.conections);
}

static error_code_t read_figure_from_file(figure_t &figure, FILE *f)
{
    if (f == NULL)
        return ERROR_OPENING_FILE;

    figure = figure_init();

    error_code_t er = read_points_from_file(figure.points, f);
    if (er == OK)
    {
        er = read_conections_from_file(figure.conections, f);
        if (er)
            free_points(figure.points);
    }
    return er;
}

void copy_figure(figure_t &figure_dst, figure_t &figure_src)
{
    free_figure(figure_dst);
    figure_dst = figure_src;
}

static error_code_t check_data(const figure_t &figure)
{
    if (figure.points.points == NULL || figure.conections.conections == NULL)
        return ERROR_MEMORY;
    return check_connections(figure.conections, figure.points.size);
}

static void calculate_center(figure_t &figure)
{
    figure.center = calculate_center_point(figure.points);
}

error_code_t download_figure(figure_t &figure, const char* filename)
{
    if (filename == NULL)
        return ERROR_OPENING_FILE;
    FILE *f = fopen(filename, "r");
    if (f == NULL)
        return ERROR_OPENING_FILE;
    figure_t tmp;

    error_code_t er = read_figure_from_file(tmp, f);
    if (er == OK)
    {
        er = check_data(tmp);
        if (er != OK)
            free_figure(tmp);
        else
        {
            calculate_center(tmp);
            copy_figure(figure, tmp);
        }
    }
    return er;
}

error_code_t turn_figure(figure_t &figure, const turn_t &turn)
{
    return turn_points(figure.points, figure.center, turn);
}

error_code_t zoom_figure(figure_t &figure, const zoom_t &zoom)
{
    return zoom_points(figure.points, figure.center, zoom);
}

error_code_t move_figure(figure_t &figure, const move_t &move)
{
    return move_points(figure.points, figure.center, move);
}
