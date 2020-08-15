/*
** EPITECH PROJECT, 2020
** line format
** File description:
** line format
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

int find_line(char *buffer)
{
    int i = 0;
    int j = 0;

    for (i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == '\n')
            j++;
    return (j);
}

int count_empty_line(char **buffer)
{
    int i = 0;
    int j = 0;
    int empty = 0;

    for (i = 0; buffer[i] != NULL; i++) {
        for (j = 0; buffer[i][j] != '\0'; j++);
        if (j == 0)
            empty++;
    }
    return (empty);
}

int *count_line_size(char **buffer)
{
    int i = 0;
    int j = 0;
    int *size = NULL;

    for (i = 0; buffer[i] != NULL; i++);
    size = malloc(sizeof(int) * (i + 1));
    for (i = 0; buffer[i] != NULL; i++) {
        for (j = 0; buffer[i][j] != '\0'; j++);
        size[i] = j;
    }
    size[i] = -1;
    return (size);
}

char **malloc_clean_tab(char **buffer)
{
    int i = 0;
    int j = 0;
    int *size = count_line_size(buffer);
    int minus = count_empty_line(buffer);
    char **clean_tab = NULL;

    for (i = 0; buffer[i] != NULL; i++);
    clean_tab = malloc(sizeof(char *) * (i - minus + 1));
    for (i = 0; size[i] > -1; i++) {
        if (size[i] > 0) {
            clean_tab[j] = malloc(sizeof(char) * (size[i] + 1));
            j++;
        }
    }
    return (clean_tab);
}

char **remove_empty_line(char **buffer)
{

    int i = 0;
    int j = 0;
    int k = 0;
    int *size = count_line_size(buffer);
    char **clean_tab = malloc_clean_tab(buffer);

    for (i = 0; size[i] > -1; i++) {
        if (size[i] > 0) {
            for (j = 0; j < size[i]; j++)
                clean_tab[k][j] = buffer[i][j];
            clean_tab[k][j] = '\0';
            k++;
        }
    }
    clean_tab[k] = NULL;
    return (clean_tab);
}

