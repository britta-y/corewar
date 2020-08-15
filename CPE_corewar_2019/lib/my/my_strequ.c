/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_strequ
*/

#include "my.h"

int	my_strequ(char const *s1, char const *s2)
{
    if (!s1 || !s2)
        return (0);
    return (my_strcmp(s1, s2) == 0);
}