/*
** EPITECH PROJECT, 2020
** printf fct
** File description:
** functions
*/
#ifndef PRINTF_FCT_H_
#define PRINTF_FCT_H_
#include <stdarg.h>
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
char *my_revstr(char *str);
int my_put_nbr(int nb);
int my_get_nbr(char *str);

void flags_idc_str(int i, char *s, va_list ap, ...);
void flags_binary(int i, char *s, va_list ap, ...);
void flags_hex_low(int i, char *s, va_list ap, ...);
void flags_hex_up(int i, char *s, va_list ap, ...);
int upper_case(int modulo);
int lower_case(int modulo);
void my_printf(char *s, ...);
void flags_octal(int i, char *s, va_list ap, ...);
int choose_flags(int i, char *s, va_list ap, ...);
int flags_bis(int i, char *s, va_list ap, ...);
int flags_format(int i, char *s, va_list ap, ...);
void flags_u(int i, char *s, va_list ap, ...);
#endif

