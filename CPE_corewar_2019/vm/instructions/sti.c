/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** sti
*/

#include <vm.h>

static int	get_param_value(t_vm *vm, t_process *process, int param, int *val)
{
	if (process->param_type[param] == T_REG)
	{
		if (process->param[param] >= 1 && process->param[param] <= 16)
			*val = process->reg[process->param[param] - 1];
		else
			return (0);
	}
	else if (process->param_type[param] == T_DIR)
		*val = process->param[param];
	else
		*val = my_load(vm, 4, (process->pc + process->param[param]));
	return (1);
}

void		my_sti(t_vm *vm, t_process *process)
{
	int		val1;
	int		val2;
	int		adress;

	if (process->param[0] >= 1 && process->param[0] <= 16)
	{
		if (!get_param_value(vm, process, 1, &val1) ||
			!get_param_value(vm, process, 2, &val2))
		{
			my_adv_invalid(process, vm);
			return ;
		}
		my_verbose(vm, process);
		adress = (process->pc + ((val1 + val2) % IDX_MOD));
		if (vm->verbose)
			my_printf("\n%7s| -> store to %d + %d = %d (with pc and mod %d)",
			"", val1, val2, val1 + val2, adress);
		my_store(vm, process, adress);
		my_verbose2(process, vm);
	}
	else
		my_adv_invalid(process, vm);
}
