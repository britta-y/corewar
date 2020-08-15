/*
** EPITECH PROJECT, 2020
** position
** File description:
** maage history of position
*/
#include "../include/my.h"
#include <stdio.h>

void print_maze(generate_t *maze, int nb)
{
    for (int i = 1; i != maze->y + 1; i++) {
        if (i != 1)
            printf("\n");
        for (int j = 1; maze->maze[i][j] != '\0'; j++)
            printf("%c", maze->maze[i][j]);
    }
    if (nb % 2 != 0) {
        printf("\n");
        for (int i = 1; i != maze->x; i++)
            printf("%c", '*');
    }
    for (int i = 1; i != maze->y + 1; i++) {
        printf("\n");
        for (int j = 0; maze->mirror[i][j + 1] != '\0'; j++)
            printf("%c", maze->mirror[i][j]);
    }
}

int end_condition(generate_t *maze)
{
    static int i = 0;
    int *neighbor = NULL;

    if (maze->pos_y == 1 && maze->pos_x == 1
        && i != 0 &&
        (neighbor = check_neighbor(maze)) == NULL) {
        i++;
        return (-1);
    }
    i++;
    return (0);
}

void one_neighbor(int *neighbor, generate_t *maze)
{
    int count = 0;

    for (int i = 0; i != 4; i++)
        if (neighbor[i] == 1)
            count++;
    if ( count == 1) {
        move_point(neighbor, maze);
    }
}

void set_history(generate_t *maze)
{
    maze->coordinates = malloc(sizeof(int*) * 200);
    for (int i = 0; i != 200; i++)
        maze->coordinates[i] = malloc(sizeof(int) * 2);
}

void handle_history(generate_t *maze, int j)
{
    static int i = 0;

    if (j == 1) {
    maze->coordinates[i][0] = maze->pos_y;
    maze->coordinates[i][1] = maze->pos_x;
    i++;
    } else {
        maze->pos_y = maze->coordinates[i - 1][0];
        maze->pos_x = maze->coordinates[i - 1][1];
        i--;
    }
}
