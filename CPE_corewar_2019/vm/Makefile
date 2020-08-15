##
## EPITECH PROJECT, 2020
## CPE_corewar_2019
## File description:
## Makefile
##

SRC_VM	=	instructions/add.c				\
			instructions/aff.c				\
			instructions/and.c				\
			instructions/fork.c				\
			instructions/ld.c				\
			instructions/ldi.c				\
			instructions/lfork.c				\
			instructions/live.c				\
			instructions/lld.c				\
			instructions/lldi.c				\
			instructions/op.c					\
			instructions/or.c					\
			instructions/st.c					\
			instructions/sti.c				\
			instructions/sub.c				\
			instructions/xor.c				\
			instructions/zjmp.c				\
			op.c \
			vm.c \
			vm_parse_process.c \
			debug_vm.c \
			vm_treat_args.c \
			prepare_memory.c \
			vm_launch.c \
			vm_handle_process.c \
			vm_handle_process2.c \
			vm_virtual_foam_bat.c \
			vm_check_champ.c \
			killemall.c \
			load.c \
			store.c \
			init_vm.c

CC		=	gcc
CFLAG	+=	-Wall -Wextra

NAME 	=	corewar

LIB		=	../lib/my

INC		=	-I./include

OBJ_VM	=	$(SRC_VM:.c=.o)

all :
ifeq ($(shell test -f $(LIB)libmy.a ; echo $$?), 1)
	@make -sC $(LIB)
else
	@sleep 0.5
endif

	@echo $(GREEN) "Compiling $@" $(RED)
	@$(CC) -o $(NAME) $(SRC_VM) $(INC) $(CFLAG)
	@echo $(GREEN) "Done" $(EOC)	

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
