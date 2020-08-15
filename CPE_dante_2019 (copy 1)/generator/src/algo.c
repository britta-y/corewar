/*
** EPITECH PROJECT, 2020
** algo
** File description:
** backtracker
*/
#include "../include/my.h"
#include <stdio.h>

void fill_cross(generate_t *maze)
{
    int i = 0;
    int j = 0;
    int r = 0;

    while (i != maze->y  + 1) {
        j = 1;
        while (j != maze->x) {
            if (maze->maze[i][j] == '.') {
                r = 1 + rand() % (3 - 1);
                if ( r == 1)
                    maze->maze[i][j] = 'X';
                else
                    maze->maze[i][j] = '*';
            }
            j++;
        }
        i++;
    }
}

int move_point(int *neighbor, generate_t *maze)
{
    int k = -1;
    int count = 0;

    for (int i = 0; i != 4; i++)
        if (neighbor[i] == 0)
            count++;
    if ( count == 4) {
        handle_history(maze, 2);
        return (0);
    }
    while (neighbor[k] != 1)
        k = 0 + rand() % (4 - 0);
    if (k == 0)
        maze->pos_y -= 1;
    if (k == 1)
        maze->pos_x += 1;
    if (k == 2)
        maze->pos_y += 1;
    if (k == 3)
        maze->pos_x -= 1;
    maze->maze[maze->pos_y][maze->pos_x] = '*';
    return (0);
}

void add_wall(int *neighbor, generate_t *maze)
{
    int k = -1;
    int i = maze->pos_y;
    int j = maze->pos_x;

    while (neighbor[k] != 1)
        k = 0 + rand() % (4 - 0);
    neighbor[k] = 0;
    if (k == 0 && maze->maze[i - 1][j] == '.')
        maze->maze[i - 1][j] = 'X';
    if (k == 1 && maze->maze[i][j + 1] == '.')
        maze->maze[i][j + 1] = 'X';
    if (k == 2 && maze->maze[i + 1][j] == '.')
        maze->maze[i + 1][j] = 'X';
    if (k == 3 && maze->maze[i][j - 1] == '.')
        maze->maze[i][j - 1] = 'X';
}

int* check_neighbor(generate_t *maze)
{
    int	*neighbor = malloc(sizeof(int) * 4);
    int i = maze->pos_y;
    int j = maze->pos_x;

    for (int k = 0; k != 4; k++)
        neighbor[k] = 0;
    if (maze->maze[i - 1][j] == '.')
        neighbor[0] = 1;
    if (maze->maze[i][j + 1] == '.')
        neighbor[1] = 1;
    if (maze->maze[i + 1][j] == '.')
        neighbor[2] = 1;
    if (maze->maze[i][j - 1] == '.')
        neighbor [3] = 1;
    one_neighbor(neighbor, maze);
    for (int k = 0; k != 4; k++)
        if (neighbor[k] != 0)
            return (neighbor);
    return (NULL);
}

void backtracker_algo(generate_t *maze)
{ 
    int k = 0;
    int* neighbor = NULL;

    maze->pos_y = 1;
    maze->pos_x = 1;
    maze->maze[1][1] = '*';
    while (end_condition(maze) == 0) {
        if ((neighbor = check_neighbor(maze)) == NULL) {
            handle_history(maze, 2);
        } else {
            handle_history(maze, 1);
            add_wall(neighbor, maze);
            move_point(neighbor, maze);
        }
        k++;
    }
    fill_cross(maze);
}
