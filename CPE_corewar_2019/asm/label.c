/*
** EPITECH PROJECT, 2020
** label
** File description:
** check label
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "asm.h"
#include "../lib/my/my.h"
#include "../include/op.h"

void check_label_char(char c)
{
    int i = 0;
    int count = 0;

    while (LABEL_CHARS[i] != '\0') {
        if (c == LABEL_CHARS[i])
            count++;
        i++;
    }
    if (count != 1)
        exit (84);
}

char *take_label(char *str, int param)
{
    int j = 0;
    char *label = malloc(my_strlen(str));

    for (int i = param; (str[i] != SEPARATOR_CHAR
    && str[i] != '\n' && str[i] != '\0'); i++) {
        label[j] = str[i];
        j++;
        check_label_char(str[i]);
    }
    label[j] = '\0';
    return (label);
}

int is_label(char *str)
{
    if (str[0] == LABEL_CHAR || str[1] == LABEL_CHAR)
        return (0);
    return (1);
}
