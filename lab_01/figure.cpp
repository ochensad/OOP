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

error_code_t download_figure(figure_t &figure, const char* filename)
{
    if (filename == NULL)
        return ERROR_OPENING_FILE;
    FILE *f = fopen(filename, "r");
    if (f == NULL)
        return ERROR_OPENING_FILE;
    figure_t tmp;

    error_code_t er = read_figure_from_file(tmp, f);

    if (fclose(f))
        return ERROR_CLOSING_FILE;
    if (er == OK)
    {
        free_figure(figure);
        figure = tmp;
    }
    return er;
}

error_code_t turn_figure(figure_t &figure, const turn_t &turn)
{
    return turn_points(figure.points, turn);
}

error_code_t zoom_figure(figure_t &figure, const zoom_t &zoom)
{
    return zoom_points(figure.points, zoom);
}

error_code_t move_figure(figure_t &figure, const move_t &move)
{
    return move_points(figure.points, move);
}
