/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_str_to_lower
*/

#include "my.h"

int	str_to_lower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return ((c - 'A') + 'a');
    return (c);
}