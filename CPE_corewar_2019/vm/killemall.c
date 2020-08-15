/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** killemall
*/

#include <vm.h>

static void	my_kill_champions(t_list *champions)
{
    if (champions)
    {
        if (champions->next)
            my_kill_champions(champions->next);
        free(champions->content);
        free(champions);
    }
}

static void	my_kill_processes(t_list *processes)
{
    if (processes)
    {
        if (processes->next)
            my_kill_processes(processes->next);
        free(processes->content);
        free(processes);
    }
}

void		my_kill_vm(t_vm *vm)
{
    my_kill_processes(vm->processes);
    my_kill_champions(vm->champions);
    free(vm);
}