/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** add
*/

#include <vm.h>

void	my_add(t_vm *vm, t_process *process)
{
    if (process->param[0] >= 1 && process->param[0] <= 16
        && process->param[1] >= 1 && process->param[1] <= 16
        && process->param[2] >= 1 && process->param[2] <= 16)
    {
        my_verbose(vm, process);
        process->reg[process->param[2] - 1] =
            process->reg[process->param[0] - 1] +
            process->reg[process->param[1] - 1];
        process->carry = !process->reg[process->param[2] - 1];
        my_verbose2(process, vm);
    }
    else
        my_adv_invalid(process, vm);
}
