/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** revstr description
*/

#include "../include/my.h"

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int i;
    int j;
    char tmp;
    int a;

    i = 0;
    j = my_strlen(str) - 1;
    a = j;
    while (i <= a/2) {
        tmp = str[j];
        str[j] = str[i];
        str[i] = tmp;
        i++;
        j--;
    }
    j = j + i + 1;
    str[j] = '\0';
    return (str);
}
