/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_strcat
*/

#include "my.h"

char *my_strcat(char *dest, const char *src)
{
    int index;
    int from;

    from = my_strlen(dest);
    index = 0;
    while (src[index] != '\0') {
        dest[index + from] = src[index];
        index++;
    }
    dest[index + from] = '\0';
    return (dest);
}

char *my_strcat_ch(char *dest, const char c)
{
    int from;

    from = my_strlen(dest);
    dest[from] = c;
    dest[from + 1] = '\0';
    return (dest);
}