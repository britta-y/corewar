/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_revstr
*/

#include "my.h"

char *my_revstr(char *s)
{
    int		i = 0;
    int		len = (my_strlen(s) - 1);
    char	tmp;

    if (s[i] == '-')
        i++;
    while (i < len) {
        tmp = s[len];
        s[len] = s[i];
        s[i] = tmp;
        i++;
        len--;
    }
    return (s);
}