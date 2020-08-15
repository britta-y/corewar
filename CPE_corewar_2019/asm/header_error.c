/*
** EPITECH PROJECT, 2020
** header error
** File description:
** header eroor
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

int compare_string(char *check, int size, char *str)
{
    int i = 0;

    for (i = 0; i < size; i++) {
        if (check[i] != str[i])
            return (1);
    }
    return (0);
}

int header_size(char *str, int size)
{
    int i = 0;
    int j = 0;

    for (i = 0; str[i] != '\0'; i++)
        if (str[i] == '"')
            j++;
    if (j != 2)
        return (1);
    for (i = 0; str[i] != '"'; i++);
    i = i + 1;
    for (j = 0; str[i] != '"'; i++, j++);
    if (j > size)
        return (1);
    return (0);
}

int check_header(char **tab)
{
    int name = my_strlen(NAME_CMD_STRING);
    int comment = my_strlen(COMMENT_CMD_STRING);

    if (tab[0] == NULL || tab[1] == NULL)
        exit (84);
    if (compare_string(tab[0], name, NAME_CMD_STRING) == 1)
        exit(84);
    if (compare_string(tab[1], comment, COMMENT_CMD_STRING) == 1)
        exit(84);
    if (header_size(tab[0], PROG_NAME_LENGTH) == 1)
        exit(84);
    if (header_size(tab[1], COMMENT_LENGTH) == 1)
        exit(84);
    return (0);
}


