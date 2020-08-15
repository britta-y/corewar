/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_strnequ
*/

#include "my.h"

int	my_strnequ(char const *s1, char const *s2, size_t n)
{
    if (s1 == NULL || s2 == NULL)
        return (0);
    if (n == 0)
        return (1);
    if (my_strncmp(s1, s2, n) == 0)
        return (1);
    else
        return (0);
}