/*
** EPITECH PROJECT, 2020
** asm
** File description:
** check
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "asm.h"
#include "../lib/my/my.h"
#include "../include/op.h"

int position_label(char *label)
{
    if (label[0] == ':')
        return (0);
    if (label[1] == ':')
        return (1);
    printf("error1");
    exit (84);
}

int is_declared(char *str, char *label)
{
    int j = position_label(label) + 1;

    for (int i = 0; str[i] != ':'; i++) {
        if (label[j] != str[i])
            return (1);
        j++;
    }
    return (0);
}

void label_declaration(char *label, char **tab)
{
    char **line = NULL;

    for (int i = 2; tab[i] != NULL; i++) {
        line = str_to_word_array(tab[i]);
        if (is_declared(line[0], label) == 0)
            return;
        for (int j = 0; line[j] != NULL; j++)
            free(line[j]);
    }
    printf("error2");
    exit (84);
}

void search_label_arg(char **arg, char **tab)
{
    for (int i = 0; arg[i] != NULL; i++) {
        if (is_label(arg[i]) == 0)
            label_declaration(arg[i], tab);
    }
}

void optional_label(char **tab)
{
    char **line = NULL;

    for (int i = 2; tab[i] != NULL; i++) {
        line = str_to_word_array(tab[i]);
        if (search_instruction(line) == 1)
            search_label_arg(line, tab);
        for (int j = 0; line[j] != NULL; j++)
            free(line[j]);
    }
}
