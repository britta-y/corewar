/*
** EPITECH PROJECT, 2020
** asm
** File description:
** asm
*/
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "../lib/my/my.h"
#include "asm.h"
#include "../include/op.h"

char *core_file(char *filename, int size)
{
    int i = 0;
    char *corename = malloc(size + 5);
    char *core = "cor";

    for (i = 0; filename[i] != '\0'; i++)
        corename[i] = filename[i];
    i--;
    for (int j = 0; core[j] != '\0'; j++) {
        corename[i] = core[j];
        i++;
    }
    corename[i] = '\0';
    return (corename);
}

int create_file(char *filename, char **tab)
{
    int i = my_strlen(filename);
    FILE *fp;
    char *corename = core_file(filename, i);
    header_t header;
    int fd = 0;

    if (filename[i - 1] != 's' && filename[i - 2] != '.')
        return (84);
    fp = fopen(corename, "w");
    fclose(fp);
    fd = open(corename, O_WRONLY);
    free(corename);
    put_header(fd, tab, &header);
    return (0);
}

void usage (void)
{
    my_putstr("USAGE\n");
    my_putstr("./asm file_name[.s]\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("file_namefile in assembly language ");
    my_putstr("to be converted intofile_name.cor, an\n");
    my_putstr("executable in the Virtual Machine.\n");
}

int main (int ac, char **av)
{
    FILE *fp;
    char **tab = NULL;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        usage();
        return (0);
    }
    if (ac < 2)
        return (84);
    if ((fp = fopen (av[1], "r")) == NULL)
      return (84);
    if ((tab = main_error(av[1])) == NULL)
        return (84);
    optional_label(tab);
<<<<<<< HEAD
    create_file(av[1], tab);
=======
    for (int i = 0; tab[i] != NULL; i++) {
        printf(tab[i]);
    printf("\n");
    }
>>>>>>> 1486ca5ca12ce8b0f23541a519bd2c621c0d5f34
    for (int i = 0; tab[i] != NULL; i++)
      free(tab[i]);
}
