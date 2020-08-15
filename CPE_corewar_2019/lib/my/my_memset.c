/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_memset
*/

#include "my.h"

void *my_memset(void *s, int c, size_t n)
{
    char *d = s;

    while (n) {
        *d++ = (unsigned char)c;
        n--;
    }
    return (s);
}