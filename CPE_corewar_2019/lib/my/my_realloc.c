/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_realloc
*/

#include "my.h"

void *my_realloc(void *old, size_t n)
{
    char *d = old;
    void *new = malloc(n);
    char *new_n = new;

    if (new == NULL)
        return (NULL);
    my_memset(new, 0, n);
    for (int i = 0; d[i] != 0; i = i + 1)
        new_n[i] = d[i];
    free(old);
    return (new);
}