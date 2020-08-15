/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** vm_launch
*/

#include <vm.h>

int		my_check_champs_live(t_vm *vm, t_list *prev, t_list *current_process)
{
    t_process		*process;

    process = current_process->content;
    if (process->cycles_wo_live >= vm->cycle_to_die)
    {
        if (vm->verbose)
            my_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
                process->id + 1, process->cycles_wo_live, vm->cycle_to_die);
        my_savage_slaughter(vm, prev, current_process);
        return (1);
    }
    return (0);
}

void	my_search_for_preys(t_vm *vm)
{
    t_list		*prev;
    t_list		*current_process;
    t_list		*next;

    prev = NULL;
    current_process = vm->processes;
    next = current_process->next;
    while (current_process)
        if (my_check_champs_live(vm, prev, current_process))
        {
            if (prev)
                prev->next = next;
            current_process = next;
            if (next)
                next = current_process->next;
        }
        else
        {
            prev = current_process;
            current_process = next;
            if (current_process)
                next = current_process->next;
        }
}

void	my_decrement_cycle_to_die(t_vm *vm)
{
    t_list		*champs;
    t_process	*champ;

    vm->cycle_to_die -= CYCLE_DELTA;
    if (vm->verbose)
        my_printf("Cycle to die is now %d\n", vm->cycle_to_die);
    vm->nb_checks = 0;
    champs = vm->champions;
    while (champs)
    {
        champ = champs->content;
        champ->nb_live = 0;
        champs = champs->next;
    }
}

int		my_handle_cycles(t_vm *vm)
{
    int		ch;

    vm->total_cycles++;
    vm->cycles++;
    if (vm->cycles > vm->cycle_to_die)
    {
        vm->cycles = 1;
        my_search_for_preys(vm);
        vm->nb_checks++;
        if (vm->live > (NBR_LIVE - 1) || vm->nb_checks == 10)
            my_decrement_cycle_to_die(vm);
        vm->live = 0;
    }
    return (1);
}

int		my_launch_vm(t_vm *vm)
{
    t_list		*current_process;
    t_process	*process;

    while (vm->total_cycles != vm->dump + 1 && vm->processes)
    {
        if (vm->verbose)
            my_printf("It is now cycle %d\n", vm->total_cycles);
        current_process = vm->processes;
        while (current_process)
        {
            process = current_process->content;
            if (process->pc >= MEM_SIZE)
                process->pc %= MEM_SIZE;
            while (process->pc < 0)
                process->pc += MEM_SIZE;
            process->cycles_wo_live++;
            my_handle_process(vm, process);
            current_process = current_process->next;
        }
        my_handle_cycles(vm);
    }
    if (vm->processes)
        deb_print_memory(vm);
    return (1);
}