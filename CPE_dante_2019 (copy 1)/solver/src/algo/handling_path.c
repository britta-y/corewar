/*
** EPITECH PROJECT, 2020
** handling path
** File description:
** handling path
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

void close_path(game *solver, int node)
{
    int i = (node * 2) - 1;

    solver->algo[2][i] = -1;
    solver->algo[2][i + 1] = -1;
}

int check_path(game *solver, int plus, int board_size)
{
    int size = board_size / 2;

    if (solver->tracker[plus - 1][1] == size)
        return (0);
    return (1);
}
