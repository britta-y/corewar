/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_strnstr
*/

#include "my.h"

char *my_strnstr(const char *s, const char *find, size_t slen)
{
    char	c;
    char	sc;
    size_t	len;

    if ((c = *find++) != '\0') {
        len = my_strlen(find);
        while (1) {
            while (1) {
                if (slen-- < 1 || (sc = *s++) == '\0')
                    return (NULL);
                if (sc == c)
                    break ;
            }
            if (len > slen)
                return (NULL);
            if (my_strncmp(s, find, len) == 0)
                break ;
        }
        s--;
    }
    return ((char *)s);
}