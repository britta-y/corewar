/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_strncmp
*/

#include "my.h"

int my_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    if (n == 0)
        return (0);
    if (*s1 == '\0' || *s2 == '\0')
        return (*(unsigned char *)s1 - *(unsigned char *)s2);
    i = -1;
    while (++i < n && *s1++ == *s2++ && !(*s1 == '\0' && *s2 == '\0'))
        ;
    return (*((unsigned char *)s1 - 1) - *((unsigned char *)s2 - 1));
}