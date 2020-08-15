/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** st
*/

#include <vm.h>

void		my_st(t_vm *vm, t_process *process)
{
	int		adress;

	if (process->param[0] >= 1 && process->param[0] <= 16)
	{
		if (process->param_type[1] == 1)
		{
			if (process->param[1] >= 1 && process->param[1] <= 16)
			{
				my_verbose(vm, process);
				process->reg[process->param[1] - 1] =
					process->reg[process->param[0] - 1];
				my_verbose2(process, vm);
			}
			else
				my_adv_invalid(process, vm);
			return ;
		}
		my_verbose(vm, process);
		adress = (process->pc + (process->param[1] % IDX_MOD)) % MEM_SIZE;
		my_store(vm, process, adress);
		my_verbose2(process, vm);
	}
	else
		my_adv_invalid(process, vm);
}
