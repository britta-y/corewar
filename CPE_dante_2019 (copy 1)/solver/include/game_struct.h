/*
** EPITECH PROJECT, 2020
** game struct
** File description:
** structures
*/
#ifndef GAME_STRUCT_H_
#define GAME_STRUCT_H_

typedef struct game game;
struct game
{
    char *prep_map;
    char **map;
    int **matrice;
    int **matrice_map;
    int **algo;
    int *nodes;
    int **tracker;
    int ok;
};

#endif
