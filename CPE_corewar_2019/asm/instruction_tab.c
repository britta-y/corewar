/*
** EPITECH PROJECT, 2020
** instruction
** File description:
** tab
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "asm.h"
#include "../lib/my/my.h"
#include "../include/op.h"

op_t    op_tab[] =
{
    {"live", 1, {T_DIR}, 1, 10, "alive"},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load"},
    {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store"},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition"},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction"},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
"et (and  r1, r2, r3   r1&r2 -> r3"},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
"ou  (or   r1, r2, r3   r1 | r2 -> r3"},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
"ou (xor  r1, r2, r3   r1^r2 -> r3"},
    {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero"},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
"load index"},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
"store index"},
    {"fork", 1, {T_DIR}, 12, 800, "fork"},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load"},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
"long load index"},
    {"lfork", 1, {T_DIR}, 15, 1000, "long fork"},
    {"aff", 1, {T_REG}, 16, 2, "aff"},
    {0, 0, {0}, 0, 0, 0}
};

int search_instruction(char **tab)
{
    int i = my_strlen(tab[0]);

    if (tab[0][i - 1] == ':')
        return (2);
    return (1);
}

int search_tab(char *str)
{
    int i = 0;

    while (op_tab[i].mnemonique != 0) {
        if (my_strcmp(str, op_tab[i].mnemonique) == 0) {
            return (op_tab[i].code);
        }
        i++;
    }
    printf("error4");
    exit (84);
}

int check_instruction(char *str)
{
    int i = 0;
    char tab[4][6] = {"live", "zjmp", "fork", "lfork"};

    while (i != 4) {
        if (my_strcmp(str, tab[i]) == 0)
            return (1);
        i++;
    }
    return (0);
}
