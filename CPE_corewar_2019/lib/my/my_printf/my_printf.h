/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_printf
*/

#ifndef MY_PRINTF_H_
#define MY_PRINTF_H_

#include <stdarg.h>

#define array                                                           \
int (*pointer_on_function[15])(char const *, int *, va_list) =          \
{nbsign_flag, spaces_delete_printf, s_low_flag, d_and_i_flags,          \
    u_flag, ld_flag, c_flag, p_flag, x_low_flag, x_upp_flag, b_flag,    \
    hd_flag, o_flag, s_upp_call_flag, mod_flag}

#define conv                                \
int char_size = 0;                          \
unsigned long testsize = nb;                \
char *str;                                  \
int r;                                      \
int count = 0;

int option_printf(char const *, int *, va_list, ...);
int my_printf(char const *, ...);
int s_low_flag(char const *, int *, va_list);
int d_and_i_flags(char const *, int *, va_list);
int u_flag(char const *, int *, va_list);
int ld_flag(char const *, int *, va_list);
int c_flag(char const *, int *, va_list);
int p_flag(char const *, int *, va_list);
int x_low_flag(char const *, int *, va_list);
int x_upp_flag(char const *, int *, va_list);
int b_flag(char const *, int *, va_list);
int o_flag(char const *, int *, va_list);
int s_upp_call_flag(char const *, int *, va_list);
int mod_flag(char const *, int *, va_list);
int b_flag(char const *, int *, va_list);
int s_upp_flag(char *);
int binary_conversion(unsigned long);
void binary_conversion_two(int, char *, int);
int hexa_conversion_upp(unsigned long);
void hexa_conversion_upp_two(int, char *, int);
int hexa_conversion_low(unsigned long);
void hexa_conversion_low_two(int, char *, int);
int octal_conversion(unsigned long);
void octal_conversion_two(int, char *, int);
int my_put_unsigned_nbr(unsigned int);
int my_put_long_nbr(long int);
int my_put_pointer(void *);
int nbsign_flag(char const *, int *, va_list);
int nbsign_flag_two(char const *, int *, va_list);
int spaces_delete_printf(char const *, int *, va_list);
int my_put_short_nbr(short int);
int hd_flag(char const *, int *, va_list);
int octal_conversion_s_upp(unsigned long);
void    my_putchar(char);
int     my_putstr(char const *);
int	    my_strlen(const char *);
char    *my_strcpy(char *, const char *);
int	    my_put_nbr(int);


#endif /* !MY_PRINTF_H_ */