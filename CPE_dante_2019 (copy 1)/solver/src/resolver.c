/*
** EPITECH PROJECT, 2020
** resolver
** File description:
** map resolver main function
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

int check_friends(game *solver, int plus)
{
    static int round = 0;
    if (solver->ok == 0)
        round++;
    else
        round = 0;
    if (round == 2)
        return (1);
    return (0);
}

int main_algo(game *solver)
{
    int board_size = create_algo_tracktab(solver);
    int node = 1;
    int dist = 0;
    int plus = 0;
    fill_begin_tracktab(solver, board_size);
    board_size = board_size * 2 - 1;
    node = fill_start_line(solver);
    plus = fill_tracker_result(solver, dist, node);
    while (1) {
        solver->ok = check_node_friends(solver, plus);
        solver->ok = check_friends(solver, plus);
        write_second_line(solver, node, plus);
        node = check_smallest_nb(solver);
        dist = solver->algo[2][node];
        node = node / 2 + 1;
        plus = fill_tracker_result(solver, dist, node);
        if (check_path(solver, plus, board_size) == 0 || solver->ok == 1)
            return(solver->ok);
        lift_second_line(solver);
        close_path(solver, node);
    }
    return (solver->ok);
}

void get_map_path(game *solver)
{
    int i = 0;
    int j = 0;
    int k = 1;
    int check = 0;
    int map = 0;

    for (k = 1; solver->tracker[k] != NULL; k++) {
        check = solver->tracker[k][1];
        for (i = 0; solver->matrice_map[i] != NULL; i++) {
            for (j = 0; solver->matrice_map[i][j] > -1; j++) {
                map = solver->matrice_map[i][j];
                if (map == check)
                    solver->map[i][j] = 'o';
            }
        }
    }
    disp_map(solver);
}

int check_solution(game *solver)
{
    int i = 0;
    int j = 0;

    for (i = 0; solver->map[i] != NULL; i++)
        for (j = 0; solver->map[i][j] != '\n'; j++);
    if ((solver->map[i - 1][j - 1] == '*') && (solver->map[0][0] == '*'))
        return (0);
    return (84);
}

int main(int ac, char **av)
{
    struct game solver;
    int check = 0;

    if (open_read_file(av[1], &solver) == 84)
        return (84);
    if (prepare_map(&solver) == 84)
        return (84);
    create_tab_map(&solver, prepare_map(&solver));
    if (check_solution(&solver) == 84) {
        printf("no solution found");
        return (84);
    }
    main_create_matrice(&solver);
    check = main_algo(&solver);
    if (check == 1) {
        printf("no solution found");
        return (check);
    } else
        get_map_path(&solver);
    return (check);
}
