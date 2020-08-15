/*
** EPITECH PROJECT, 2020
** preliminary
** File description:
** creating from buffer and stocking in tab maze map
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

int open_read_file(char *av, game *solver)
{
    struct stat buf_size;
    int fd = open(av, O_RDONLY);
    int size = 0;
    char *buffer = NULL;
    int check = 0;

    stat(av, &buf_size);
    size = buf_size.st_size;
    if (fd < 0)
        return (84);
    buffer = malloc(sizeof(char) * (size + 1));
    check = read(fd, buffer, size);
    if (check < 0)
        return (84);
    buffer[size] = '\0';
    solver->prep_map = buffer;
    close(fd);
    return (0);
}

int check_map_size(game *solver, int nb_line)
{
    int *line_size = malloc(sizeof(int) * (nb_line + 1));
    int i = 0;
    int j = 0;
    int k = 0;

    for (i = 0, j = 0; solver->prep_map[i] != '\0'; i++, j++) {
        if (solver->prep_map[i] == '\n') {
            line_size[k] = j;
            k++;
            j = -1;
        }
    }
    for (i = 0; i < nb_line; i++)
        if (line_size[i] != line_size[0])
            return (84);
    return (0);
}

int get_size(game *solver)
{
    int i = 0;
    int j = 0;

    for (i = 0; solver->prep_map[i] != '\0'; i++) {
        if (solver->prep_map[i] != 'X' && solver->prep_map[i] != '*')
            if (solver->prep_map[i] != '\n')
                return (84);
        if (solver->prep_map[i] == '\n')
            j++;
    }
    if (check_map_size(solver, j) == 84)
        return (84);
    return (j);
}

int create_tab_map(game *solver, int line)
{
    int col = 0;
    int i = 0;
    int j = 0;
    int k = 0;

    for (col = 0; solver->prep_map[col] != '\n'; col++);
    solver->map = malloc(sizeof(char *) * (line + 1));
    for (i = 0; i < line; i++)
        solver->map[i] = malloc(sizeof(char) * (col + 2));
    for (i = 0, k = 0; i < line; k++, i++) {
        for (j = 0; j < col; j++, k++)
            solver->map[i][j] = solver->prep_map[k];
        solver->map[i][j] = '\n';
        solver->map[i][j + 1] = '\0';
    }
    solver->map[i] = NULL;
    return (0);
}

int prepare_map(game *solver)
{
    if (get_size(solver) == 84)
        return (84);
    return (get_size(solver));
}
