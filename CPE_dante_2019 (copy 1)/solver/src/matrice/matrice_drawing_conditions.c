/*
** EPITECH PROJECT, 2020
** matrice drawing conditions
** File description:
** conditions for drawing
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

void case_minimum_i(int i, int j, int nb, game *solver)
{
    int right = j + 1;
    int down = i + 1;
    int left = j - 1;
    int maxj = 0;

    for (maxj = 0; solver->matrice_map[0][maxj] > -1; maxj++);
    if (i == 0 && j > 0 && j < (maxj - 1)) {
        if (solver->matrice_map[i][left] > 0)
            draw_to_matrice(solver, nb, solver->matrice_map[i][left]);
        if (solver->matrice_map[i][right] > 0)
            draw_to_matrice(solver, nb, solver->matrice_map[i][right]);
        if (solver->matrice_map[down][j] > 0)
            draw_to_matrice(solver, nb, solver->matrice_map[down][j]);
    }
    if (i == 0 && j == (maxj - 1)) {
        if (solver->matrice_map[i][left] > 0)
            draw_to_matrice(solver, nb, solver->matrice_map[i][left]);
        if (solver->matrice_map[down][j] > 0)
            draw_to_matrice(solver, nb, solver->matrice_map[down][j]);
    }
}

void case_maximum_i(int i, int j, int nb, game *solver)
{
    int up = i - 1;
    int right = j + 1;
    int left = j - 1;
    int maxi = 0;
    int maxj = 0;
    for (maxi = 0; solver->matrice_map[maxi] != NULL; maxi++);
    for (maxj = 0; solver->matrice_map[0][maxj] > -1; maxj++);
    if (i == (maxi - 1) && j > 0 && j < (maxj - 1)) {
        if (solver->matrice_map[i][left] > 0)
            draw_to_matrice(solver, nb, solver->matrice_map[i][left]);
        if (solver->matrice_map[i][right] > 0)
            draw_to_matrice(solver, nb, solver->matrice_map[i][right]);
        if (solver->matrice_map[up][j] > 0)
            draw_to_matrice(solver, nb, solver->matrice_map[up][j]);
    }
    if (i == (maxi - 1) && j == 0) {
        if (solver->matrice_map[i][right] > 0)
            draw_to_matrice(solver, nb, solver->matrice_map[i][right]);
        if (solver->matrice_map[up][j] > 0)
            draw_to_matrice(solver, nb, solver->matrice_map[up][j]);
    }
}

void case_minimum_j(int i, int j, int nb, game *solver)
{
    int up = i - 1;
    int right = j + 1;
    int down = i + 1;
    int maxi = 0;

    for (maxi = 0; solver->matrice_map[maxi] != NULL; maxi++);
    if (j == 0 && i > 0 && i < (maxi - 1)) {
        if (solver->matrice_map[down][j] > 0)
            draw_to_matrice(solver, nb, solver->matrice_map[down][j]);
        if (solver->matrice_map[i][right] > 0)
            draw_to_matrice(solver, nb, solver->matrice_map[i][right]);
        if (solver->matrice_map[up][j] > 0)
            draw_to_matrice(solver, nb, solver->matrice_map[up][j]);
    }
    if (j == 0 && i == 0) {
        if (solver->matrice_map[down][j] > 0)
            draw_to_matrice(solver, nb, solver->matrice_map[down][j]);
        if (solver->matrice_map[i][right] > 0)
            draw_to_matrice(solver, nb, solver->matrice_map[i][right]);
    }
}

void case_maximum_j(int i, int j, int nb, game *solver)
{
    int up = i - 1;
    int right = j + 1;
    int left = j - 1;
    int maxi = 0;
    int maxj = 0;
    for (maxi = 0; solver->matrice_map[maxi] != NULL; maxi++);
    for (maxj = 0; solver->matrice_map[0][maxj] > -1; maxj++);
    if (j == (maxj - 1) && i > 0 && i < (maxi - 1)) {
        if (solver->matrice_map[i][left] > 0)
            draw_to_matrice(solver, nb, solver->matrice_map[i][left]);
        if (solver->matrice_map[i][right] > 0)
            draw_to_matrice(solver, nb, solver->matrice_map[i][right]);
        if (solver->matrice_map[up][j] > 0)
            draw_to_matrice(solver, nb, solver->matrice_map[up][j]);
    }
    if (j == (maxj - 1) && i == (maxi - 1)) {
        if (solver->matrice_map[i][left] > 0)
            draw_to_matrice(solver, nb, solver->matrice_map[i][left]);
        if (solver->matrice_map[up][j] > 0)
            draw_to_matrice(solver, nb, solver->matrice_map[up][j]);
    }
}

void case_inbetween(int i, int j, int nb, game *solver)
{
    int up = i - 1;
    int right = j + 1;
    int down = i + 1;
    int left = j - 1;
    int maxi = 0;
    int maxj = 0;

    for (maxi = 0; solver->matrice_map[maxi] != NULL; maxi++);
    for (maxj = 0; solver->matrice_map[0][maxj] > -1; maxj++);
    if (j > 0 && j < (maxj - 1) && i > 0 && i < (maxi - 1)) {
        if (solver->matrice_map[i][left] > 0)
            draw_to_matrice(solver, nb, solver->matrice_map[i][left]);
        if (solver->matrice_map[i][right] > 0)
            draw_to_matrice(solver, nb, solver->matrice_map[i][right]);
        if (solver->matrice_map[up][j] > 0)
            draw_to_matrice(solver, nb, solver->matrice_map[up][j]);
        if (solver->matrice_map[down][j] > 0) {
            draw_to_matrice(solver, nb, solver->matrice_map[down][j]);
        }
    }
}
