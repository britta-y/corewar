/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_strstr
*/

#include "my.h"

static int is_query(char *query, const char *str, int index)
{
    int i = 0;
    int ok = 1;

    while (query[i]) {
        if (query[i] != str[i + index]) {
            ok = 0;
            break;
        }
        i++;
    }
    if (ok)
        return (1);
    return (0);
}

char *my_strstr(const char *str, const char *query)
{
    int i = 0;

    if (my_strlen(query) == 0)
        return (char *)str;
    while (str[i]) {
        if (str[i] == query[0]) {
            if (is_query(query, str, i))
                return (char *)(str + i);
        }
        i++;
    }
    return (0);
}