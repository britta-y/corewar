/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** verbose2
*/

#include <vm.h>

void	my_print_ind(t_vm *vm, t_process *process, int i)
{
	if (process->instruction == OPCODE_LD - 1)
		my_printf("%d", my_load(vm, 4,
			process->pc + process->param[i] % IDX_MOD));
	else if (process->instruction == OPCODE_LLD - 1)
		my_printf("%d", my_load(vm, 4,
			process->pc + process->param[i] % IDX_MOD));
	else if (process->instruction == OPCODE_STI - 1 &&
			process->param_type[i] == 3)
		my_printf("%d", my_load(vm, 4,
			process->pc + process->param[i] % IDX_MOD));
	else if (process->instruction == OPCODE_AND - 1 &&
			process->param_type[i] == 3)
		my_printf("%d", my_load(vm, 4,
			process->pc + process->param[i] % IDX_MOD));
	else if (process->instruction == OPCODE_LLDI - 1 &&
			process->param_type[i] == 3)
		my_printf("%d", my_load(vm, 4,
			process->pc + process->param[i] % IDX_MOD));
	else
		my_printf("%d", (short)process->param[i]);
}

void	my_print_reg(t_process *process, int i)
{
	if ((process->instruction + 1 >= OPCODE_AND &&
		process->instruction + 1 <= OPCODE_XOR))
		i == 2 ?
		my_printf("r%d", (unsigned char)process->param[i]) :
		my_printf("%d", process->reg[(unsigned char)process->param[i] - 1]);
	else if (process->instruction + 1 == OPCODE_LD ||
			process->instruction + 1 == OPCODE_LLD)
		my_printf("r%d", (unsigned char)process->param[i]);
	else if (process->instruction + 1 == OPCODE_STI && i > 0)
		my_printf("%d", process->reg[(unsigned char)process->param[i] - 1]);
	else if ((process->instruction + 1 == OPCODE_LDI ||
			process->instruction + 1 == OPCODE_LLDI))
		i == 2 ?
		my_printf("r%d", (unsigned char)process->param[i]) :
		my_printf("%d", process->reg[(unsigned char)process->param[i] - 1]);
	else if (process->instruction + 1 == OPCODE_ST && i == 1)
		my_printf("%d", (unsigned char)process->param[i]);
	else
		my_printf("r%d", (unsigned char)process->param[i]);
}
