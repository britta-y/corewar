/*
** EPITECH PROJECT, 2019
** my getnbr
** File description:
** my_getnbr
*/
#include "my.h"

int my_getnbr(char *str)
{
    int i = 0;
    int neg = 1;
    int n;
    int r = 0;

    while (str[i] != '\0' && (str[i] == '+' || str[i] == '-')) {
        if (str[i] == '-')
            neg = neg * -1;
        i++;
    }
    n = 0;
    while (str[i] >= 48 && str[i] <= 57) {
        n = (n * 10) + str[i] - 48;
        i++;
    }
    r = n * neg;
    return (r);
}
