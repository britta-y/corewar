/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_strlen
*/

#include "my.h"

int	my_strlen(const char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}