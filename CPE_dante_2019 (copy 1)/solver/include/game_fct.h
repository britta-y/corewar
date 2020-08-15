/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** jsdaij
*/

#ifndef MY_H_
#define MY_H

//resolver.c
int draw_to_matrice(game *solver, int nb, int neighbour);
int main_algo(game *solver);
void get_map_path(game *solver);

//checking_functions.c
int check_node_friends(game *solver, int plus);
int check_dist(int algo, int dist);
int check_smallest_nb(game *solver);

//writing_line.c
int write_second_line(game *solver, int node, int plus);
void lift_second_line(game *solver);
int write_new(game *solver, int sm);

///handling_path.c
void close_path(game *solver, int node);
int check_path(game *solver, int plus, int board_size);

//malloc_tracker.c
int **malloc_tmp(game *solver, int **tmp, int plus);
void malloc_first(game *solver);
void malloc_tracktab(game *solver, int **tmp, int plus);
int fill_tracker_result(game *solver, int dist, int node);

///algo_setup.c
void fill_begin_tracktab(game *solver, int size);
int create_algo_tracktab(game *solver);
int fill_start_line(game *solver);

///matrice_create.c
void write_bordure_matrice(game *solver, int nodes);
int draw_to_matrice(game *solver, int nb, int neighbour);
void check_position(game *solver, int i, int j, int nb);
int fill_matrice(game *solver, int nodes);
int main_create_matrice(game *solver);

///matrice_drawing_conditions.c
void case_minimum_i(int i, int j, int nb, game *solver);
void case_minimum_j(int i, int j, int nb, game *solver);
void case_maximum_i(int i, int j, int nb, game *solver);
void case_maximum_j(int i, int j, int nb, game *solver);
void case_inbetween(int i, int j, int nb, game *solver);

///display_fct.
void disp_map(game *solver);
void disp_algo(game *solver);
void disp_matrice_map(game *solver);
void disp_matrice(game *solver);
void disp_tracker(game *solver);

///preliminary_matrice.c
int save_matrice_map(game *solver);
int create_matrice_map(game *solver);
void save_matrice(game *solver, int nodes);

///preliminary_map.c
int open_read_file(char *av, game *solver);
int check_map_size(game *solver, int nb_line);
int get_size(game *solver);
int create_tab_map(game *solver, int line);
int prepare_map(game *solver);

#endif
