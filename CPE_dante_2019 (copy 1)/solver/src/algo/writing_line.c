/*
** EPITECH PROJECT, 2020
** writing line
** File description:
** writing line
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

int write_second_line(game *solver, int node, int plus)
{
    int i = 0;
    int dist = solver->tracker[plus - 1][0] + 1;
    int k = 0;
    int j = 0;
    int check = 0;

    for (k = 0; solver->nodes[k] > -1; k++);
    for (j = 0; j < k; j++) {
        for (i = 1; solver->algo[2][i] > -2; i++) {
            check = check_dist(solver->algo[2][i], dist);
            if (solver->algo[0][i] == solver->nodes[j] && check == 0) {
                solver->algo[2][i + 1] = node;
                solver->algo[2][i] = dist;
            }
        }
    }
    return (dist);
}

void lift_second_line(game *solver)
{
    int i = 0;
    int j = 0;

    for (i = 0; solver->algo[0][i] > -2; i++)
        solver->algo[1][i] = solver->algo[2][i];
    solver->algo[1][i] = -2;
    solver->algo[2][i] = -2;
}

int write_new(game *solver, int sm)
{
    int i = 0;
    int node = 0;

    for (i = 0; solver->algo[1][i] != sm; i++);
    solver->algo[2][i] = -1;
    solver->algo[2][i + 1] = -1;
    node = (i / 2) + 1;
    return (node);
}
