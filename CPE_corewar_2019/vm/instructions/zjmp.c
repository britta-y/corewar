/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** zjmp
*/

#include <vm.h>

void	my_zjmp(t_vm *vm, t_process *process)
{
    my_verbose(vm, process);
    if (process->carry == 1)
    {
        if (vm->verbose)
            my_printf(" OK\n");
        process->pc2 = process->pc + ((short)process->param[0] % IDX_MOD);
        process->pc2 %= MEM_SIZE;
    }
    else
    {
        process->pc2 = (process->pc + 3) % MEM_SIZE;
        if (vm->verbose)
            my_printf(" FAILED");
        my_verbose2(process, vm);
    }
}