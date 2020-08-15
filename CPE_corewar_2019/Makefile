##
## EPITECH PROJECT, 2020
## CPE_corewar_2019
## File description:
## Makefile
##

SRC 	= 	asm/asm.c			\
			asm/header.c 		\
			asm/instruction.c	\
			asm/label.c		\
			asm/check_label.c	\
			asm/instruction_tab.c	\
			asm/line_format.c	\
			asm/size.c		\
			asm/error.c 		\
			asm/header_error.c	\
			asm/space_format.c	\
			asm/parameters.c	\
			asm/label_error.c	\

CC		=	gcc -g
CFLAG	+=	-Wall -Wextra

NAME	=	asm/asm
VM		=	virtual_machine

LIB		=	lib/my

INC		=	-I./include

OBJ		=	$(SRC:.c=.o)

all :
	@printf "Welcome to corewar !\n"
	@sleep 0.5

ifeq ($(shell test -f $(LIB)libmy.a ; echo $$?), 1)
	@make -sC $(LIB)
else
	@sleep 0.5
endif

# ifeq ($(shell test -f $(VM)corewar ; echo $$?), 1)
# 	@make -sC $(VM)
# else
# 	@sleep 0.5
# endif

	@$(CC) -o $(NAME) $(SRC) -L$(LIB) -lmy $(INC)	

clean:
		rm -f $(OBJ)
		rm -f $(OBJ_VM)
		make clean -C lib/my

fclean:		clean
		rm -f $(NAME)
		rm -f $(NAME_VM)
		make fclean -C lib/my

re:		fclean all

.PHONY:		all clean fclean