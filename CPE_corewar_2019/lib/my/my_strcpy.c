/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_strcpy
*/

#include "my.h"

char *my_strcpy(char *d, const char *s)
{
    char *saved = d;

    while (*s)
        *d++ = *s++;
    *d = 0;
    return (saved);
}