##
## EPITECH PROJECT, 2020
## CPE_corewar_2019
## File description:
## Makefile
##

SRC_PRINTF  =   my_printf/my_printf.c               \
                my_printf/my_put_other_nbr.c        \
                my_printf/conversions.c             \
                my_printf/conversions_two.c         \
                my_printf/s_upp_flag.c              \
                my_printf/s_low_flag.c              \
                my_printf/d_and_i_flags.c           \
                my_printf/u_flag.c                  \
                my_printf/ld_flag.c                 \
                my_printf/c_flag.c                  \
                my_printf/p_flag.c                  \
                my_printf/x_low_flag.c              \
                my_printf/x_upp_flag.c              \
                my_printf/b_flag.c                  \
                my_printf/o_flag.c                  \
                my_printf/s_upp_call_flag.c         \
                my_printf/mod_flag.c				\
				my_printf/nbsign_flag.c			    \
				my_printf/spaces_delete_printf.c	\
				my_printf/hd_flag.c

SRC		=       my_putchar.c                        \
                my_strncpy.c                        \
                my_strcat.c                         \
                my_strstr.c                         \
                my_putstr.c                         \
                my_strcmp.c                         \
                my_revstr.c                         \
                my_strcpy.c                         \
                my_strlen.c                         \
                my_getnbr.c                         \
                my_strdup.c                         \
                my_strncat.c                        \
                str_to_word_array.c            	  	\
                my_malloc.c                         \
				my_memset.c                         \
                my_realloc.c						\
				my_str_to_lower.c					\
				my_str_to_upper.c					\
				my_strequ.c							\
				my_strjoin.c						\
				my_strnstr.c						\
				my_strncmp.c						\
				my_strnew.c							\
				my_strnequ.c						\
				str_to_word.c						\
                $(SRC_PRINTF)

OBJ		=		$(SRC:.c=.o)

NAME	=		libmy.a

all:	$(NAME) clean

$(NAME):		$(OBJ)
	    ar rc $(NAME) *.o my_printf/*.o

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all clean

.PHONY: clean fclean all