/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_str_to_upper
*/

#include "my.h"

int	str_to_upper(int c)
{
    if (c >= 'a' && c <= 'z')
        return ((c - 'a') + 'A');
    return (c);
}