/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** lld
*/

#include <vm.h>

void	my_lld(t_vm *vm, t_process *process)
{
	int		adress;

	if (process->param[1] >= 1 && process->param[1] <= 16)
	{
		my_verbose(vm, process);
		if (process->param_type[0] == T_DIR)
			process->reg[process->param[1] - 1] = process->param[0];
		else
		{
			adress = (process->pc + process->param[0]) % MEM_SIZE;
			if (adress < 0)
				adress += MEM_SIZE;
			process->reg[process->param[1] - 1] =
				my_load(vm, 4, adress);
		}
		process->carry = !process->reg[process->param[1] - 1];
		my_verbose2(process, vm);
	}
	else
		my_adv_invalid(process, vm);
}
