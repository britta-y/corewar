/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** live
*/

#include <vm.h>

static char	*my_check_champ_nb(t_vm *vm, int nb_champ, int do_count_live)
{
	t_list		*champions;
	t_process	*champ;

	champions = vm->champions;
	while (champions)
	{
		champ = champions->content;
		if (nb_champ == champ->id_champ)
		{
			if (do_count_live)
				champ->nb_live++;
			return (champ->header.prog_name);
		}
		champions = champions->next;
	}
	return (NULL);
}

void		my_live(t_vm *vm, t_process *process)
{
	char	*champ_name;

	my_verbose(vm, process);
	process->cycles_wo_live = 0;
	vm->live++;
	my_check_champ_nb(vm, process->param[0], 1);
	if ((champ_name = my_check_champ_nb(vm, process->param[0], 0)))
	{
		vm->last_live = process->param[0];
		if (vm->verbose)
			my_printf("\nPlayer %d (%s) is said to be alive",
				my_abs(process->param[0]), champ_name);
	}
	my_verbose2(process, vm);
}
