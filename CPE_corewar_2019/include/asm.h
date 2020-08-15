/*
** EPITECH PROJECT, 2019
**  my.h
** File description:
**  my.h
*/

#ifndef ASM_H
#define ASM_H
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "op.h"

// HEADER //
void put_header(int fd, char **tab, header_t *header);

// body //
void instructions(int fd, char **tab);
int param_type(char *str);
void take_parameters(char **str, int nb, int start, int fd);
int search_tab(char *str);
int check_instruction(char *str);
int search_instruction(char **tab);
int is_label(char *str);
char *take_label(char *str, int param);
int compute_prog_size(char **tab);

// ERROR //
char **remove_empty_line(char **buffer);
char **remove_space_tab(char **buffer);
int *count_line_size(char **buffer);
char **main_error(char *file);
void optional_label(char **tab);
int check_header(char **tab);
int check_label(char **tab);
#endif
