/*
** EPITECH PROJECT, 2020
** str to
** File description:
** word array
*/
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

void cpy_word(char **arr, char *str, int nb_word)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i != nb_word) {
        j = 0;
        if (str[k] == ' ' || str[k] == '\t')
            k++;
        while (str[k] != '\t' && str[k] != ' ' && str[k] != '\0') {
            arr[i][j] = str[k];
            j++;
            k++;
        }
        arr[i][j] = '\0';
        i++;
    }
}

int count_char(char *str)
{
    static int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '\t') {
            i++;
            return (count);
        }
        i++;
        count++;
    }
    return (count);
}

int check_char(char c)
{
    if ( 64 < c && c < 123)
        return (1);
    return (0);
}

int count_word(char *str)
{
    int i = 1;
    int word = 1;

    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '\t')
            word++;
        i++;
    }
    return (word);
}

char **str_to_word_array(char *str)
{
    char **arr;
    int j = 0;
    int i = 0;

    arr = malloc(sizeof(char *) * (count_word(str) + 1));
    for (; i != count_word(str); i++) {
        j = count_char(str);
        arr[i] = malloc(sizeof(char) * j + 2);
    }
    arr[i] = NULL;
    cpy_word(arr, str, count_word(str));
    return (arr);
}
