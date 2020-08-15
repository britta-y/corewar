/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_malloc
*/

#include "my.h"

void *my_malloc(size_t size)
{
    void *to_alloc = malloc(size);

    if (to_alloc == NULL)
        exit(84);
    my_memset(to_alloc, 0, size);
    return (to_alloc);
}