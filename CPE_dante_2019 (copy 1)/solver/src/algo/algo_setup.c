/*
** EPITECH PROJECT, 2020
** algo setup
** File description:
** setting up tracker for algo
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

void fill_begin_tracktab(game *solver, int size)
{
    int i = 0;
    int j = 0;
    int k = 0;

    size = size * 2 - 1;
    for (i = 1, j = 0; j < size; j++) {
        if ((j % 2) > 0) {
            solver->algo[0][j] = i;
            i++;
        } else
            solver->algo[0][j] = 0;
    }
    for (i = 0; i < 3; i++) {
        if (i > 0) {
            for (k = 0; k < j; k++)
                solver->algo[i][k] = 0;
            solver->algo[i][k] = -2;
        }
    }
    solver->algo[0][j] = -2;
    solver->algo[3] = NULL;
}

int create_algo_tracktab(game *solver)
{
    int i = 0;
    int size = 0;

    for (size = 0; solver->matrice[0][size] != -1; size++);
    solver->algo = malloc(sizeof(int *) * (size * 2) - 1);
    for (i = 0; i < 3; i++)
        solver->algo[i] = malloc(sizeof(int) * (size * 2) + 1);
    return (size);
}

int fill_start_line(game *solver)
{
    int d = 0;
    int node = 1;

    solver->algo[1][1] = d;
    solver->algo[1][2] = node;
    solver->algo[2][1] = -1;
    solver->algo[2][2] = -1;
    return (node);
}
