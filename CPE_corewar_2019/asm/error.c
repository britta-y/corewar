/*
** EPITECH PROJECT, 2020
** error
** File description:
** error
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "asm.h"
#include "../lib/my/my.h"
#include "../include/op.h"

char *read_file(int fd, int size)
{
    char *buffer = malloc((size + 1) * sizeof(char));

    read(fd, buffer, size);
    buffer[size - 1] = '\0';
    close(fd);
    if (size <= 0)
        return (NULL);
    return (buffer);
}

char *open_file(char const *filepath)
{
    int fd = 0;
    int size = 0;
    struct stat buf_size;
    char *buffer = NULL;

    fd = open(filepath, O_RDONLY);
    stat(filepath, &buf_size);
    size = buf_size.st_size;
    if (fd > 0) {
        buffer = read_file(fd, size);
        if (buffer == NULL)
            return (NULL);
    } else
        return (NULL);
    return (buffer);
}

char **make_table(char *buffer)
{
    char **table = str_to_word(buffer, '\n');

    table = remove_space_tab(table);
    table = remove_empty_line(table);
    check_header(table);
    return (table);
}

char **main_error(char *file)
{
    char *buffer = NULL;

    buffer = open_file(file);
    if (buffer == NULL)
        return (NULL);
    return (make_table(buffer));
}
