/*
** EPITECH PROJECT, 2020
** str to word
** File description:
** from a string to words
*/
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

char **malloc_stock(int *size, int nb, char *str, char cut)
{
    char **stock = NULL;
    int i = 0;
    int j = 0;
    int a = 0;

    if (str != NULL) {
        stock = malloc(sizeof(char *) * (nb + 1));
        for (i = 0; i < nb; i++)
            stock[i] = malloc(sizeof(char) * (size[i] + 2));
    } else
        return (NULL);
    for (i = 0; i < nb; i++, a++) {
        for (j = 0; str[a] != '\0' && str[a] != cut; a++, j++) {
            stock[i][j] = str[a];
        }
        stock[i][j] = '\0';
    }
    stock[i] = NULL;
    return (stock);
}

char **str_to_word(char *str, char cut)
{
    int i = 0;
    int j = 0;
    int nb = 0;
    int len = 0;
    int *size = NULL;
    char **sorted = NULL;

    for (i = 0; str[i] != '\0'; i++, j++)
        if (str[i] == cut)
            nb++;
    nb++;
    size = malloc(sizeof(int) * (nb + 2));
    for (i = 0, j = 0; str[i] != '\0'; i++, len++)
        if ((str[i] == cut) || str[i + 1] == '\0') {
            size[j] = len;
            len = 0;
            j++;
        }
    size[j] = -1;
    sorted = malloc_stock(size, (nb + 1), str, cut);
    return (sorted);
}
