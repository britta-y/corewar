/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_strnew
*/

#include "my.h"

char *my_strnew(size_t size)
{
    char *new;

    if (!(new = (char *)my_malloc(sizeof(char) * size + 1)))
        return (NULL);
    return (new);
}