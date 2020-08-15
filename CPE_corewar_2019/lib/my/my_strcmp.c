/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_strcmp
*/

#include "my.h"

int	my_strcmp(const char *s1, const char *s2)
{
    if (*s1 == '\0' || *s2 == '\0')
        return (*(unsigned char *)s1 - *(unsigned char *)s2);
    while (*s1++ == *s2++ && !(*s1 == '\0' && *s2 == '\0'));
    return (*((unsigned char *)s1 - 1) - *((unsigned char *)s2 - 1));
}