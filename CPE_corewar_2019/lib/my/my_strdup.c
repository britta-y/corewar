/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_strdup
*/

#include "my.h"

char *my_strdup(const char *src)
{
    char *str = (char *)my_malloc(sizeof(char) * (my_strlen(src) + 1));
    int	i = -1;

    if (str == NULL)
        return (NULL);
    while (src[++i])
        str[i] = src[i];
    return (str);
}