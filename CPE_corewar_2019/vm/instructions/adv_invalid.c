/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** adv_invalid
*/

#include <vm.h>

void my_adv_invalid(t_process *process, t_vm *vm)
{
    int		adv;
    int		i;

    if (!vm->verbose)
        return ;
    adv = 1;
    i = -1;
    if (g_op_tab[(int)(process->instruction)].nbr_cycles)
    {
        while (++i < g_op_tab[(int)(process->instruction)].nbr_args)
            if (process->param_type[i] == 1)
                adv += 1;
            else if (process->param_type[i] == 3)
                adv += 2;
            else
                adv += 4;
        adv++;
    }
    else
        adv = my_verbose5(process);
    my_printf("ADV %d (%.4p -> %.4p) ", adv, process->pc,
        (process->pc + adv));
    my_verbose3(process, vm);
}