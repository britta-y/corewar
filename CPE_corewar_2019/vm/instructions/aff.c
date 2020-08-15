/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** aff
*/

#include <vm.h>

void my_aff(t_vm *vm, t_process *process)
{
	if (process->param[0] >= 1 && process->param[0] <= 16 && vm->aff)
		my_printf("Aff: %c", process->reg[process->param[0] - 1] % 256);
	else
	{
		my_adv_invalid(process, vm);
		return ;
	}
	if (!vm->verbose && vm->aff)
		my_putchar('\n');
	my_verbose2(process, vm);
}
