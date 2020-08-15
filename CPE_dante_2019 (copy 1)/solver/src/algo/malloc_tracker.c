/*
** EPITECH PROJECT, 2020
** malloc_tracker
** File description:
** malloc tracker
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../include/game_struct.h"
#include "../../include/game_fct.h"
#include "../../include/printf_fct.h"

int **malloc_tmp(game *solver, int **tmp, int plus)
{
    int i = 0;
    int j = 0;

    tmp = malloc(sizeof(int *) * (plus + 1));
    for (i = 0; i < (plus + 1); i++)
        tmp[i] = malloc(sizeof(int) * 3);
    for (i = 0; i < (plus); i++) {
        for (j = 0; j < 2; j++)
            tmp[i][j] = solver->tracker[i][j];
        tmp[i][j] = -1;
    }
    tmp[i] = NULL;
    return (tmp);
}

void malloc_first(game *solver)
{
    int i = 0;
    int j = 0;

    solver->tracker = malloc(sizeof(int *) * 3);
    for (i = 0; i < 1; i++)
        solver->tracker[i] = malloc(sizeof(int) * 3);
    for (i = 0; i < 1; i++) {
        for (j = 0; j < 2; j++)
            solver->tracker[i][j] = 0;
        solver->tracker[i][j] = -1;
    }
    solver->tracker[i] = NULL;
}

void malloc_tracktab(game *solver, int **tmp, int plus)
{
    int i = 0;
    int j = 0;

    solver->tracker = malloc(sizeof(int *) * (plus + 1));
    for (i = 0; i < (plus + 1); i++)
        solver->tracker[i] = malloc(sizeof(int) * 3);
    for (i = 0; i < (plus - 1); i++) {
        for (j = 0; j < 2; j++)
            solver->tracker[i][j] = tmp[i][j];
        solver->tracker[i][j] = -1;
    }
}

int fill_tracker_result(game *solver, int dist, int node)
{
    static int plus = 1;
    int **tmp = NULL;

    if (plus == 1)
        malloc_first(solver);
    tmp = malloc_tmp(solver, tmp, plus);
    plus++;
    malloc_tracktab(solver, tmp, plus);
    solver->tracker[plus - 1][0] = dist;
    solver->tracker[plus - 1][1] = node;
    solver->tracker[plus - 1][2] = -1;
    solver->tracker[plus] = NULL;
    return (plus);
}
