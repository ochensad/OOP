#include "action.h"
#include "figure.h"

error_code_t switch_action(request_t &request)
{
    static figure_t figure = figure_init();
    error_code_t er = OK;

    switch (request.action)
    {
        case DOWNLOAD:
            er = download_figure(figure, request.filename);
            break;
        case DRAW:
            er = draw_figure(figure, request.canvas);
            break;
        case TURN:
            er = turn_figure(figure, request.turn);
            break;
        case ZOOM:
            er = zoom_figure(figure, request.zoom);
            break;
        case MOVE:
            er = move_figure(figure, request.move);
            break;
        case QUIT:
            free_figure(figure);
            break;
        default:
            er = ERROR_UNKNOWN_COMAND;
            break;
    }
    return er;
}
