/*
** EPITECH PROJECT, 2020
** parameters
** File description:
** param
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "asm.h"
#include "../lib/my/my.h"
#include "../include/op.h"

char *take_nbr(char *str)
{
    char *param = malloc(3);
    int i = 0;
    int j = 0;

    for (; (str[i] != SEPARATOR_CHAR
            && str[i] != '\n' && str[i] != '\0'); i++) {
        if (str[i] == DIRECT_CHAR || str[i] == LABEL_CHAR || str[i] == 'r') {
            continue;
        }
        param[j] = str[i];
        j++;
    }
    param[j] = '\0';
    return (param);
}

void write_direct(char *str, int fd, int size)
{
    int nb = 0;
    char *label = NULL;

    if (is_label(str) == 0) {
        label = take_label(str, 2);
        write(fd, &label, size);
        free(label);
        return;
    }
    nb = my_getnbr(take_nbr(str));
    write(fd, &nb, size);
}

void write_register(char *str, int fd)
{
    int nb = my_getnbr(take_nbr(str));

    if (nb > 16 || nb < 1) {
        printf("error3");
        exit (84);
    }
    write(fd, &nb, 1);
}

void write_indirect(char *str, int fd, int size)
{
    int nb = 0;

    if (is_label(str) == 0)
        return;
    my_getnbr(take_nbr(str));
    write(fd, &nb, size);
}

void take_parameters(char **str, int nb, int start, int fd)
{
    int i = 0;
    int y = start;

    while (i != nb) {
        if (param_type(str[y]) == 1) {
            write_register(str[y], fd);
        }
        else if (param_type(str[y]) == 2) {
            write_direct(str[y], fd, DIR_SIZE);
        }
        else if (param_type(str[y]) == 3) {
            write_indirect(str[y], fd, IND_SIZE);
        }
        i++;
        y++;
    }
}
