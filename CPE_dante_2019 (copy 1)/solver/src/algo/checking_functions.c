/*
** EPITECH PROJECT, 2020
** checking functions
** File description:
** checking functions
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

int check_node_friends(game *solver, int plus)
{
    int i = 0;
    int friends = 0;
    int node = solver->tracker[plus - 1][1];

    for (i = 1; solver->matrice[node][i] > -1; i++)
        if (solver->matrice[node][i] == 1)
            friends++;
    if (friends == 0)
        return (1);
    solver->nodes = malloc(sizeof(int) * (friends + 1));
    for (i = 1, friends = 0; solver->matrice[node][i] > -1; i++) {
        if (solver->matrice[node][i] == 1) {
            if (solver->algo[1][(i * 2) - 1] > -1) {
                solver->nodes[friends] = i;
                friends++;
            }
        }
    }
    solver->nodes[friends] = -1;
    return (friends);
}

int check_dist(int algo, int dist)
{
    if (algo < dist)
        return (0);
    return (1);
}

int check_smallest_nb(game *solver)
{
    int i = 0;
    int j = 0;
    int sm = 1;

    for (j = 0, i = 0; solver->algo[2][i] != -2; i++) {
        if ((i % 2) > 0 && solver->algo[2][i] > 0) {
            j++;
            if (j == 1)
                sm = solver->algo[2][i];
            if (solver->algo[2][i] <= sm)
                sm = i;
        }
    }
    return (sm);
}
