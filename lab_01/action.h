#ifndef ACTION_H
#define ACTION_H

#include "error_code.h"
#include "draw.h"

enum action
{
    DOWNLOAD,
    DRAW,
    TURN,
    ZOOM,
    MOVE,
    QUIT
};

struct request
{
    enum action action;
    const char *filename;
    canvas_t canvas;
    turn_t turn;
    move_t move;
    zoom_t zoom;
};

using request_t = struct request;

error_code_t switch_action(request_t &request);

#endif // ACTION_H
