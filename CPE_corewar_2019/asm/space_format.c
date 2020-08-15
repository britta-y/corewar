/*
** EPITECH PROJECT, 2020
** space format
** File description:
** space format
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

char **malloc_space_tab(char **table)
{
    int i = 0;
    int j = 0;
    char **clean_tab = NULL;
    int *size = count_line_size(table);

    for (i = 0; table[i] != NULL; i++) {
        for (j = 0; table[i][j] == ' '; j++);
        size[i] = size[i] - j;
    }
    for (i = 0; table[i] != NULL; i++);
    clean_tab = malloc(sizeof(char *) * (i + 1));
    for (i = 0; table[i] != NULL; i++)
        clean_tab[i] = malloc(sizeof(char) * (size[i] + 1));
    return (clean_tab);
}

char **remove_space_tab(char **table)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char **clean_tab = malloc_space_tab(table);

    for (i = 0; table[i] != NULL; i++) {
        for (j = 0; table[i][j] == '\t' || table[i][j] == ' ' ; j++);
        for (k = 0; table[i][j] != '\0'; j++, k++)
            clean_tab[i][k] = table[i][j];
        clean_tab[i][k] = '\0';
    }
    clean_tab[i] = NULL;
    return (clean_tab);
}
