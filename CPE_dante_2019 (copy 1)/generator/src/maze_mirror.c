/*
** EPITECH PROJECT, 2020
** maze
** File description:
** reverse
*/
#include "../include/my.h"
#include <string.h>
#include <stdio.h>

void add_space_mirror(generate_t *maze)
{
    int j = 0;

    while (maze->mirror[0][j] != '\0') {
        maze->mirror[0][j] = '*';
        j++;
    }
    j = 0;
    while (maze->mirror[maze->y][j] != '\0') {
        maze->mirror[maze->y + 1][j] = '*';
        j++;
    }
}

char **fill_maze_mirror(generate_t *maze)
{
    int i = 0;
    int j = 0;

    while (i != maze->y  + 1) {
        j = 1;
        maze->mirror[i][0] = '*';
        while (j != maze->x) {
            maze->mirror[i][j] = '.';
            j++;
        }
        maze->mirror[i][j] = '\0';
        i++;
    }
    add_space_mirror(maze);
    return (maze->mirror);
}

char **create_maze_mirror(generate_t *maze)
{
    maze->mirror = malloc(sizeof(char*) * (maze->y + 2));

    for (int i = 0; i != maze->y + 2; i++)
        maze->mirror[i] = malloc((sizeof(char) * (maze->x + 1)) + 1);
    return (fill_maze_mirror(maze));
}

void cpy_maze(generate_t *maze)
{
    int i = 0;
    int j = 0;
    int k = maze->y + 1;

    while (i != maze->y + 1) {
        strcpy(maze->mirror[i], maze->maze[k]);
        maze->mirror[i] = my_revstr(maze->mirror[i]);
        k--;
        i++;
    }
}
