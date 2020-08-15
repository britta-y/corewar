##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## compile
##


SRC	=	src/display_fct.c \
		src/algo/checking_functions.c \
		src/algo/writing_line.c \
		src/algo/handling_path.c \
		src/matrice/matrice_creation.c \
		src/matrice/matrice_drawing_conditions.c \
		src/matrice/preliminary_matrice.c \
		src/algo/algo_setup.c \
		src/algo/malloc_tracker.c \
		src/preliminary_map.c \
		src/resolver.c

UNIT	=	tests/test_bsq.c

NAME2 	=	unit_tests

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	

CC	=	gcc

NAME	=	solver

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(CFLAGS) $(OBJ) -I ./include/

clean:
		rm -f $(NAME)
		rm -f $(NAME2)
		rm -f $(OBJ)
		rm -f *.gc*
		rm -f vgcore.*
		rm -f *~
test_run:
		gcc -o $(NAME2) $(UNIT) $(OBJ) $(CFLAG) --coverage -lcriterion

fclean: 	clean

re:		fclean all

.PHONY:		all clean fclean re
