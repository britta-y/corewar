/*
** EPITECH PROJECT, 2020
** prog
** File description:
** size
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "asm.h"
#include "../lib/my/my.h"
#include "../include/op.h"

int compute_param(char **str, int nb, int start)
{
    int i = 0;
    int y = start;
    int size = 0;

    while (i != nb) {
        if (param_type(str[y]) == 1) {
            size += 1;
        }
        else if (param_type(str[y]) == 2) {
            size += DIR_SIZE;
        }
        else if (param_type(str[y]) == 3) {
            size += IND_SIZE;
        }
        i++;
        y++;
    }
    return (size + 1);
}

int compute_prog_size(char **tab)
{
    int size = 0;
    int i = 0;
    int start = 0;
    char **line = NULL;

    for (int k = 2; tab[k] != NULL; k++) {
        line = str_to_word_array(tab[k]);
        start = search_instruction(line);
        for (i = 0; line[i] != NULL; i++);
        if (i <= 1)
            continue;
        if (start == 2)
            i--;
        size += compute_param(line, i - 1, start);
        for (int j = 0; line[j] != NULL; j++)
            free(line[j]);
    }
    return (size);
}
