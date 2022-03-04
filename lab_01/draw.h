#ifndef DRAW_H
#define DRAW_H

#include <QGraphicsView>
#include "error_code.h"
#include "figure.h"

struct canvas
{
    QGraphicsScene *scene;
    double width;
    double height;
};

struct point_line
{
    point_t start;
    point_t end;
};

using point_line_t = struct point_line;

using canvas_t = struct canvas;

error_code_t draw_figure(const figure_t &figure, canvas_t &canvas);

#endif // DRAW_H
