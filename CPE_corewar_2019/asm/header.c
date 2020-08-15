/*
** EPITECH PROJECT, 2020
** header
** File description:
** header
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "asm.h"
#include "../lib/my/my.h"
#include "../include/op.h"

char *comment(char *line, header_t *header)
{
    int i = 0;
    int j = 0;

    for (; i != COMMENT_LENGTH; i++)
        header->comment[i] = 0;
    for (; (line[j] == ' ' || line[j] == '\t'); j++);
    i = 0;
    j += 10;
    for (; line[j] != '"'; j++) {
        header->comment[i] = line[j];
        i++;
    }
    return (header->comment);
}

void prog_name(char *line, header_t *header)
{
    int i = 0;
    int j = 0;

    for (; i != PROG_NAME_LENGTH; i++)
        header->prog_name[i] = 0;
    for (; (line[j] == ' ' || line[j] == '\t'); j++);
    i = 0;
    j += 7;
    for (; line[j] != '"'; j++) {
        header->prog_name[i] = line[j];
        i++;
    }
}

void put_header(int fd, char **tab, header_t *header)
{
    int x = COREWAR_EXEC_MAGIC;

    header->magic = ((x >> 24) & 0x000000ff) |
        ((x >> 8) & 0x0000ff00) | ((x << 8) & 0x00ff0000)
        | ((x << 24) & 0xff000000);
    x = compute_prog_size(tab);
    header->prog_size = ((x >> 24) & 0x000000ff) |
        ((x >> 8) & 0x0000ff00) |
        ((x << 8) & 0x00ff0000) | ((x << 24) & 0xff000000);
    prog_name(tab[0], header);
    comment(tab[1], header);
    write(fd, header, sizeof(header_t));
    instructions(fd, tab);
}
