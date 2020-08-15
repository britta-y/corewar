/*
** EPITECH PROJECT, 2020
** label error
** File description:
** label error
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "asm.h"
#include "../lib/my/my.h"
#include "../include/op.h"

int my_compare(char *res, char *str)
{
    int i = 0;

    if (my_strlen(res) != my_strlen(str))
        return (1);
    for (i = 0; res[i] != '\0'; i++)
        if (res[i] != str[i])
            return (1);
    return (0);
}

int check_optional_label(char *label)
{
    int i = 0;
    char **arg = str_to_word(label, ' ');

    for (i = 0; arg[0][i] != '\0'; i++) {
        if (label[i] == LABEL_CHAR)
            return (1);
    }
    return (0);
}

int check_nbr_arg(char *label, int nb)
{
    int i = 0;
    int arg = 0;

    for (i = 0; label[i] != '\0'; i++)
        if (label[i] == SEPARATOR_CHAR)
            arg++;
    if ((arg + 1) == nb)
        return (0);
    return (1);
}

int check_label_arg(char *label)
{
    int i = 0;
    char **arg = str_to_word(label, ' ');
    int nb = 0;

    for (i = 0; op_tab[i].mnemonique != 0; i++)
        if (my_compare(op_tab[i].mnemonique, arg[0]) == 0) {
            nb = op_tab[i].nbr_args;
            return (nb);
        }
    return (-1);
}

int check_label(char **tab)
{
    int i = 0;
    int nb = 0;

    for (i = 2; tab[i] != NULL; i++) {
        if (check_optional_label(tab[i]) == 1)
            i++;
        nb = check_label_arg(tab[i]);
        if (nb == -1)
            exit (84);
        if (check_nbr_arg(tab[i], nb) == 1)
            exit (84);
    }
    return (0);
}
