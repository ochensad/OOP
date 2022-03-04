#include "conect.h"
#include <stdlib.h>

void free_conections(conections_t &conectins)
{
    free(conectins.conections);
    conectins.conections = NULL;
    conectins.size = 0;
}

error_code_t allocate_conections_memory(conections_t &conections)
{
    if (conections.size <= 0)
        return ERROR_CONECTIONS_SIZE;
    conect_t *tmp = (conect_t*) malloc(conections.size * sizeof(conect_t));
    if (tmp == NULL)
        return ERROR_MEMORY;
    conections.conections = tmp;
    return OK;
}

static error_code_t read_conections_size(int &size, FILE *f)
{
    if (f == NULL)
        return ERROR_OPENING_FILE;
    if (fscanf(f, "%d", &size) != 1)
        return ERROR_READING_FILE;
    if (size <= 0)
        return ERROR_CONECTIONS_SIZE;
    return OK;
}

static error_code_t read_each_conection(conections_t &conection, FILE *f)
{
    if (f == NULL)
        return ERROR_OPENING_FILE;
    else if (conection.size <= 0)
        return ERROR_CONECTIONS_SIZE;
    else if (conection.conections == NULL)
        return ERROR_MEMORY;

    for (int i = 0; i < conection.size; i++)
        if (fscanf(f, "%d %d", &(conection.conections[i].first), &(conection.conections[i].second)) != 2)
            return ERROR_READING_FILE;
    return OK;
}

error_code_t read_conections_from_file(conections_t &conections, FILE *f)
{
    if (f == NULL)
        return ERROR_OPENING_FILE;
    error_code_t er = read_conections_size(conections.size, f);
    if (er)
        return er;
    er = allocate_conections_memory(conections);
    if (er)
        return er;
    er = read_each_conection(conections, f);
    if (er)
        free_conections(conections);
    return er;
}
