/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_strncat
*/

#include "my.h"

char *my_strncat(char *dest, const char *src, size_t n)
{
    size_t index = 0;
    int	from = my_strlen(dest);

    while (src[index] != '\0' && index < n) {
        dest[index + from] = src[index];
        index++;
    }
    dest[index + from] = '\0';
    return (dest);
}