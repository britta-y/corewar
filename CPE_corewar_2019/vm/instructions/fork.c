/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** fork
*/

#include <vm.h>

static void	copy_reg(t_process *new_process, t_process *process)
{
	int	i;

	i = -1;
	while (++i < 16)
		new_process->reg[i] = process->reg[i];
	i = -1;
	while (++i < 3)
		new_process->param[i] = 0;
	i = -1;
	while (++i < 3)
		new_process->param_type[i] = 0;
}

static void	op_fork2(t_vm *vm, t_process *process, t_process *new_process,
	t_list *lst)
{
	new_process->carry = process->carry;
	new_process->cycle_bf_exe = 0;
	new_process->instruction = -1;
	new_process->cycles_wo_live = process->cycles_wo_live;
	new_process->color = process->color;
	copy_reg(new_process, process);
	lst->content = new_process;
	lst->next = NULL;
	lst->content_size = sizeof(t_list);
	my_lstadd(&vm->processes, lst);
	my_verbose2(process, vm);
}

void		my_fork(t_vm *vm, t_process *process)
{
	t_list		*lst;
	t_process	*new_process;

	lst = NULL;
	my_verbose(vm, process);
	if (vm->verbose)
		my_printf(" (%d)",
			(process->pc + ((short)(process->param[0]) % IDX_MOD)));
	if (((new_process = (t_process*)malloc(sizeof(t_process))) == NULL) ||
		((lst = (t_list *)malloc(sizeof(t_list))) == NULL))
		my_exit_malloc_error();
	new_process->header = process->header;
	new_process->id = vm->nb_process++;
	new_process->id_champ = process->id_champ;
	new_process->pc =
		(process->pc + ((short)process->param[0] % IDX_MOD)) % MEM_SIZE;
	if (new_process->pc < 0)
		new_process->pc += MEM_SIZE;
	my_fork2(vm, process, new_process, lst);
}
