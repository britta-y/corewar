/*
** EPITECH PROJECT, 2020
** preliminary matrice
** File description:
** matrice creation in progress
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

int save_matrice_map(game *solver)
{
    int line = 0;
    int col = 0;
    int i = 0;

    for (line = 0; solver->map[line] != NULL; line++)
        for (col = 0; solver->map[line][col] != '\n'; col++);
    solver->matrice_map = malloc(sizeof(int *) * (line + 1));
    for (i = 0; i < line; i++)
        solver->matrice_map[i] = malloc(sizeof(int) * (col + 1));
    return (col);
}

int create_matrice_map(game *solver)
{
    int col = save_matrice_map(solver);
    int i = 0;
    int j = 0;
    int nodes = 1;
    int del = -1;

    for (i = 0; solver->map[i] != NULL; i++) {
        for (j = 0; j < col; j++) {
            if (solver->map[i][j] == '*') {
                solver->matrice_map[i][j] = nodes;
                nodes++;
            } else
                solver->matrice_map[i][j] = 0;
        }
        solver->matrice_map[i][j] = del;
    }
    solver->matrice_map[i] = NULL;
    return (nodes);
}

void save_matrice(game *solver, int nodes)
{
    int i = 0;

    solver->matrice = malloc(sizeof(int *) * (nodes + 2));
    for (i = 0; i < (nodes + 2); i++)
        solver->matrice[i] = malloc(sizeof(int) * (nodes + 2));
}
