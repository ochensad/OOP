#include "draw.h"


error_code_t clear_canvas(const canvas_t &canvas)
{
    if (!canvas.scene)
        return ERROR_SCENE;
    canvas.scene->clear();
    return OK;
}

static point_t convert_point(point_t point, const canvas_t &canvas)
{
    point.x += canvas.width / 2;
    point.y += canvas.height / 2;
    return point;
}

static void convert_line(point_line_t &line, const canvas_t &canvas)
{
    line.start = convert_point(line.start, canvas);
    line.end = convert_point(line.end, canvas);
}

static point_line_t get_line(const conect_t &conect, const point_t *points, const canvas_t &canvas)
{
    point_line_t line;
    line.start = points[conect.first];
    line.end = points[conect.second];
    return line;
}

static void draw_line(point_line_t line,const canvas_t &canvas)
{
    canvas.scene->addLine(line.start.x, line.start.y, line.end.x, line.end.y, QPen(Qt::blue, 3));
}

static error_code_t draw_lines(const points_t &points, const conections_t &conections, const canvas_t &canvas)
{
    if (points.points == NULL || conections.conections == NULL)
        return ERROR_MEMORY;

    point_line_t line;

    for (int i = 0; i < conections.size; i++)
    {
        line = get_line(conections.conections[i], points.points, canvas);
        convert_line(line, canvas);
        draw_line(line, canvas);
    }
    return OK;
}

error_code_t draw_figure(const figure_t &figure, canvas_t &canvas)
{
    error_code_t er = clear_canvas(canvas);
    if (er)
        return er;

    er = draw_lines(figure.points, figure.conections, canvas);
    return er;
}
