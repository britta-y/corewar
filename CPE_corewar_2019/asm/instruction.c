/*
** EPITECH PROJECT, 2020
** instruction
** File description:
** instruction
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "asm.h"
#include "../lib/my/my.h"
#include "../include/op.h"

int binary_to_hexa(char *byte)
{
    int result;
    int count = 0;
    int a = 1;

    for (count = my_strlen(byte) - 1; count >= 0; count--) {
        if (byte[count] == '1')
            result += a;
        a <<= 1;
    }
    return (result);
}

int param_type(char *str)
{
    if (str[0] == 'r')
        return (1);
    if (str[0] == '%')
        return (2);
    return (3);
}

int description_to_binary(char **str, int nb, int start)
{
    int i = 0;
    char  bin[9];

    for (int y = start; i != nb * 2; i += 2, y++) {
        if (param_type(str[y]) == 1) {
            bin[i] = '0';
            bin[i + 1] = '1';
        }
        else if (param_type(str[y]) == 2) {
            bin[i] = '1';
            bin[i + 1] = '0';
        }
        else if (param_type(str[y]) == 3) {
            bin[i] = '1';
            bin[i + 1] = '1';
        }
    }
    for (; bin[i] != '\0'; i++)
        bin[i] = '0';
    return (binary_to_hexa(bin));
}

void take_instruction(int fd, char **tab)
{
    int desc = 0;
    int i = 0;
    int start = 0;
    int size = 0;

    for (i = 0; tab[i] != NULL; i++);
    if (i == 1)
        return;
    start = search_instruction(tab);
    if (start == 1)
        size = search_tab(tab[0]);
    else
        size = search_tab(tab[1]);
    write(fd, &size, 1);
    if (start == 2)
        i--;
    if (check_instruction(tab[0]) == 0)
        desc = description_to_binary(tab, i-1, start);
    write(fd, &desc, 1);
    take_parameters(tab, i - 1, start, fd);
}

void instructions(int fd, char **tab)
{
    char **line = NULL;

    for (int i = 2; tab[i] != NULL; i++) {
        line = str_to_word_array(tab[i]);
        take_instruction(fd, line);
        for (int j = 0; line[j] != NULL; j++)
            free(line[j]);
    }
}
