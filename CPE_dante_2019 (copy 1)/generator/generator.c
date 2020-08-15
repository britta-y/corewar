/*
** EPITECH PROJECT, 2020
** generator
** File description:
** maze
*/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"

void add_space(generate_t *maze)
{
    int j = 0;

    while (maze->maze[0][j] != '\0') {
        maze->maze[0][j] = '*';
        j++;
    }
    j = 0;
    while (maze->maze[maze->y][j] != '\0') {
        maze->maze[maze->y + 1][j] = '*';
        j++;
    }
}

char **fill_maze(generate_t *maze)
{
    int i = 0;
    int j = 0;

    while (i != maze->y  + 1) {
        j = 1;
        maze->maze[i][0] = '*';
        while (j != maze->x) {
            maze->maze[i][j] = '.';
            j++;
        }
        maze->maze[i][j] = '\0';
        i++;
    }
    add_space(maze);
    return (maze->maze);
}

char **create_maze(generate_t *maze)
{
    maze->maze = malloc(sizeof(char*) * (maze->y + 2));

    for (int i = 0; i != maze->y + 2; i++)
        maze->maze[i] = malloc((sizeof(char) * (maze->x + 1)) + 1);
    return (fill_maze(maze));
}

void free_tab(generate_t *maze)
{
    for (int i = 0; i != 201; i++)
        free(maze->coordinates[i]);
    for (int i = 0; i != maze->y + 1; i++)
        free(maze->maze[i]);
    for (int i = 0; i != maze->y + 1; i++)
        free(maze->mirror[i]);
}

int main (int ac, char **av)
{
    generate_t maze;

    if ( ac < 3)
        return (84);
    if (atoi(av[1]) < 4 || atoi(av[2]) < 2)
        return (84);
    maze.x = atoi(av[1]) + 1;
    maze.y = atoi(av[2]) / 2;
    maze.maze = create_maze(&maze);
    maze.mirror = create_maze_mirror(&maze);
    set_history(&maze);
    backtracker_algo(&maze);
    cpy_maze(&maze);
    print_maze(&maze, atoi(av[2]));
    free_tab(&maze);
    return (0);
}
