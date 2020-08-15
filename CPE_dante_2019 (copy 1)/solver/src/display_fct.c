/*
** EPITECH PROJECT, 2020
** display fct
** File description:
** display functions
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/game_struct.h"
#include "../include/game_fct.h"
#include "../include/printf_fct.h"

void disp_tracker(game *solver)
{
    int i = 0;
    int j = 0;
    for (i = 0; solver->tracker[i] != NULL; i++) {
        for (j = 0; solver->tracker[i][j] > -1; j++)
            printf("%i ", solver->tracker[i][j]);
        printf("\n");
    }
}

void disp_map(game *solver)
{
    int i = 0;
    int j = 0;
    
    for (i = 0; solver->map[i] != NULL; i++);
    for (j = 0; solver->map[i - 1][j] != '\n'; j++);
    solver->map[i - 1][j] = '\0';
    for (i = 0; solver->map[i] != NULL; i++)
        printf("%s", solver->map[i]);
}

void disp_algo(game *solver)
{
    int i = 0;
    int j = 0;

    for (i = 0; solver->algo[i] != NULL; i++) {
        for (j = 0; solver->algo[i][j] > -2; j++)
            printf("%i  ", solver->algo[i][j]);
        printf("\n");
    }
}

void disp_matrice_map(game *solver)
{
    int i = 0;
    int j = 0;

    for (i = 0; solver->matrice_map[i] != NULL; i++) {
        for (j = 0; solver->matrice_map[i][j] != -1; j++)
            printf("%i ", solver->matrice_map[i][j]);
        printf("\n");
    }
}

void disp_matrice(game *solver)
{
    int i = 0;
    int j = 0;

    for (i = 0; solver->matrice[i] != NULL; i++) {
        for (j = 0; solver->matrice[i][j] != -1; j++)
            printf("%i ", solver->matrice[i][j]);
        printf("\n");
    }
}
