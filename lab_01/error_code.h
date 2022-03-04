#ifndef ERROR_CODE_H
#define ERROR_CODE_H

enum error_code
{
    OK,
    ERROR_OPENING_FILE,
    ERROR_CLOSING_FILE,
    ERROR_READING_FILE,
    ERROR_NO_LOADING_FIGURE,
    ERROR_POINTS_SIZE,
    ERROR_MEMORY,
    ERROR_CONECTIONS_SIZE,
    ERROR_SCENE,
    ERROR_UNKNOWN_COMAND
};

using error_code_t = enum error_code;

void error_message(const error_code_t error);

#endif // ERROR_CODE_H
