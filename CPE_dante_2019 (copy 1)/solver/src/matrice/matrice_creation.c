/*
** EPITECH PROJECT, 2020
** matrice creation
** File description:
** matrice create and fill
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

void write_bordure_matrice(game *solver, int nodes)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < (nodes + 1); i++) {
        for (j = 0; j < (nodes + 1); j++) {
            if (i == 0)
                solver->matrice[i][j] = j;
            if (j == 0)
                solver->matrice[i][j] = i;
            if (i != 0 && j != 0)
                solver->matrice[i][j] = 0;
        }
        solver->matrice[i][j] = -1;
    }
    solver->matrice[i] = NULL;
}

int draw_to_matrice(game *solver, int nb, int neighbour)
{
    int i = nb;
    int j = neighbour;

    solver->matrice[i][j] = 1;
    solver->matrice[j][i] = 1;
    return (0);
}

void check_position(game *solver, int i, int j, int nb)
{
    int maxi = 0;
    int maxj = 0;

    for (maxi = 0; solver->matrice_map[maxi] != NULL; maxi++);
    for (maxj = 0; solver->matrice_map[0][maxj] > -1; maxj++);
    case_minimum_i(i, j, nb, solver);
    case_minimum_j(i, j, nb, solver);
    case_maximum_i(i, j, nb, solver);
    case_maximum_j(i, j, nb, solver);
    case_inbetween(i, j, nb, solver);
}

int fill_matrice(game *solver, int nodes)
{
    int i = 0;
    int j = 0;
    int check = 1;

    for (check = 1; check <= nodes;) {
        while (solver->matrice_map[i][j] != check) {
            j++;
            if (solver->matrice_map[i][j] == -1) {
                i++;
                j = 0;
            }
        }
        check_position(solver, i, j, check);
        check++;
    }
    return (0);
}

int main_create_matrice(game *solver)
{
    int nodes = create_matrice_map(solver) - 1;

    save_matrice(solver, nodes);
    write_bordure_matrice(solver, nodes);
    fill_matrice(solver, nodes);
    return (0);
}
