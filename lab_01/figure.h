#ifndef FIGURE_H
#define FIGURE_H

#include "points.h"
#include "conect.h"
#include "error_code.h"

struct figure
{
    points_t points;
    conections_t conections;
};

using figure_t = struct figure;

figure_t figure_init(void);
void free_figure(figure_t &figure);
error_code_t download_figure(figure_t &figure, const char* filename);
error_code_t turn_figure(figure_t &figure, const turn_t &turn);
error_code_t zoom_figure(figure_t &figure, const zoom_t &zoom);
error_code_t move_figure(figure_t &figure, const move_t &move);
#endif // FIGURE_H
