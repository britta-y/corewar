/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdint.h>
#include "my_printf/my_printf.h"

/*
** output
*/
void    my_putchar(char);
int     my_putstr(char const *);
int	    my_put_nbr(int);

/*
** string_functions
*/
char    *my_revstr(char *);
int	    str_to_lower(int);
int     my_getnbr(char *);
int	    str_to_upper(int);
char    *my_strcat(char *, const char *);
char    *my_strcat_ch(char *, const char);
int	    my_strcmp(const char *, const char *);
char    *my_strcpy(char *, const char *);
char    *my_strdup(const char *);
int	    my_strequ(char const *, char const *);
char    *my_strjoin(char const *, char const *);
int	    my_strlen(const char *);
char    *my_strncat(char *, const char *, size_t);
int     my_strncmp(const char *, const char *, size_t);
char    *my_strncpy(char *, const char *, size_t);
int	    my_strnequ(char const *, char const *, size_t);
char    *my_strnew(size_t);
char    *my_strnstr(const char *, const char *, size_t);
char    *my_strstr(const char *, const char *);
char    **str_to_word(char *, char);
char    **str_to_word_array(char *);

/*
** memory
*/
void    *my_memset(void *, int, size_t);
void    *my_malloc(size_t);
void    *my_realloc(void *, size_t);

#endif /* !MY_H_ */