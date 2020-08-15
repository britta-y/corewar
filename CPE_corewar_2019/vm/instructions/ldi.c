/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** ldi
*/

#include <vm.h>

static int	get_param_value(t_process *process, int param, int *val, t_vm *vm)
{
	if (process->param_type[param] == T_REG)
	{
		if (process->param[param] >= 1 && process->param[param] <= 16)
			*val = process->reg[process->param[param] - 1];
		else
			return (0);
	}
	else if (process->param_type[param] == T_DIR)
		*val = (short)process->param[param];
	else
		*val = my_load(vm, 4, process->pc + process->param[param] % IDX_MOD);
	return (1);
}

void		my_ldi(t_vm *vm, t_process *process)
{
	int		val1;
	int		val2;
	int		adress;

	if (process->param[2] >= 1 && process->param[2] <= 16)
	{
		if (!get_param_value(process, 0, &val1, vm) ||
			!get_param_value(process, 1, &val2, vm))
		{
			my_adv_invalid(process, vm);
			return ;
		}
		my_verbose(vm, process);
		adress = (process->pc + (val1 + val2) % IDX_MOD);
		if (vm->verbose)
			my_printf("\n%7s| -> load from %d + %d = %d (with pc and mod %d)",
			"", val1, val2, val1 + val2, adress);
		if (adress < 0)
			adress += MEM_SIZE;
		process->reg[process->param[2] - 1] = my_load(vm, 4, adress % MEM_SIZE);
		my_verbose2(process, vm);
	}
	else
		my_adv_invalid(process, vm);
}
