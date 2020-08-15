/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_strncpy
*/

#include <stddef.h>

char *my_strncpy(char *dest, const char *src, size_t n)
{
    unsigned int i = 0;

    while (*src != '\0' && (i < n)) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}