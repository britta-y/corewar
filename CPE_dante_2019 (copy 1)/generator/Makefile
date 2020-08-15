##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## compile
##


SRC	=	src/position.c \
		src/my_strlen.c \
		src/my_revstr.c \
		src/maze_mirror.c \
		src/algo.c \
		generator.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

NAME	=	generator

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
fclean: 	clean

re:		fclean all

.PHONY:		all clean fclean re
