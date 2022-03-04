#ifndef CONECT_H
#define CONECT_H

#include "error_code.h"
#include <stdio.h>

struct conect
{
    int first;
    int second;
};

using conect_t = struct conect;

struct conections
{
    int size;
    conect_t *conections;
};

using conections_t = struct conections;

void free_conections(conections_t &conectins);
error_code_t read_conections_from_file(conections_t &conections, FILE *f);

#endif // CONECT_H
