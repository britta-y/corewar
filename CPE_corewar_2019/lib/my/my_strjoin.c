/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_strjoin
*/

#include "my.h"

char *my_strjoin(char const *s1, char const *s2)
{
    int	total_size;
    char *res;

    if (!s1 || !s2)
        return (NULL);
    total_size = my_strlen(s1) + my_strlen(s2);
    if (!(res = my_malloc(sizeof(char) * (total_size + 1))))
        return (NULL);
    res[total_size] = '\0';
    while (*s1) {
        *res++ = *s1;
        s1++;
    }
    while (*s2) {
        *res++ = *s2;
        s2++;
    }
    return (res - total_size);
}