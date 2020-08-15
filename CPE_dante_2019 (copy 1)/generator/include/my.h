/*
** EPITECH PROJECT, 2019
**  my.h
** File description:
**  my.h
*/

#ifndef MY_GENERATOR_H
#define MY_GENERATOR_H
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

typedef struct generate generate_t;
struct generate
{
    char **maze;
    char **mirror;
    char **visitedcells;
    int x;
    int y;
    int pos_x;
    int pos_y;
    int **coordinates;
};


void print_maze(generate_t *maze, int nb);
char **create_maze_mirror(generate_t *maze);
char *my_revstr(char *str);
void cpy_maze(generate_t *maze);
int* check_neighbor(generate_t *maze);
int end_condition(generate_t *maze);
int move_point(int *neighbor, generate_t *maze);
void one_neighbor(int *neighbor, generate_t *maze);
void handle_history(generate_t *maze, int j);
void set_history(generate_t *maze);
void backtracker_algo(generate_t *maze);
char **create_visitedcells(generate_t *maze);
#endif
