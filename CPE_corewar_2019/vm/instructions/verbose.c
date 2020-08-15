/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** verbose
*/

#include <vm.h>

static void	my_verbose4(t_process *process, t_vm *vm)
{
    int		i;
    int		idx;

    i = -1;
    idx = 2;
    my_printf("%.2x ", vm->memory[(process->pc + 1) % MEM_SIZE]);
    while (++i < OP_TAB.nbr_args)
        if (process->param_type[i] == 1)
            my_printf("%.2x ", vm->memory[(process->pc + idx++) % MEM_SIZE]);
        else if ((process->param_type[i] == 2) || process->param_type[i] == 3)
        {
            my_printf("%.2x %.2x ", vm->memory[(process->pc + idx) % MEM_SIZE],
                      vm->memory[(process->pc + idx + 1) % MEM_SIZE]);
            idx += 2;
        }
        else
        {
            my_printf("%.2x %.2x %.2x %.2x ",
                      vm->memory[(process->pc + idx) % MEM_SIZE],
                      vm->memory[(process->pc + idx + 1) % MEM_SIZE],
                      vm->memory[(process->pc + idx + 2) % MEM_SIZE],
                      vm->memory[(process->pc + idx + 3) % MEM_SIZE]);
            idx += 4;
        }
}

void		my_verbose3(t_process *process, t_vm *vm)
{
    my_printf("%.2x ", vm->memory[process->pc % MEM_SIZE]);
    if (!OP_TAB.nbr_cycles)
    {
        if (OP_TAB.label_size)
        {
            my_printf("%.2x %.2x ", vm->memory[(process->pc + 1) % MEM_SIZE],
                      vm->memory[(process->pc + 2) % MEM_SIZE]);
        }
        else
        {
            my_printf("%.2x %.2x %.2x %.2x ",
                      vm->memory[(process->pc + 1) % MEM_SIZE],
                      vm->memory[(process->pc + 2) % MEM_SIZE],
                      vm->memory[(process->pc + 3) % MEM_SIZE],
                      vm->memory[(process->pc + 4) % MEM_SIZE]);
        }
    }
    else
        my_verbose4(process, vm);
    my_putchar('\n');
}

int			my_verbose5(t_process *process)
{
    int		adv;

    if (OP_TAB.label_size)
        adv = 3;
    else
        adv = 5;
    return (adv);
}

void		my_verbose2(t_process *process, t_vm *vm)
{
    int		adv;
    int		i;

    if (!vm->verbose)
        return ;
    adv = 1;
    i = -1;
    if (OP_TAB.)
    {
        while (++i < OP_TAB.nbr_args)
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
    my_printf("\nADV %d (%.4p -> %.4p) ", adv, process->pc,
              process->pc + adv);
    my_verbose3(process, vm);
}

void		my_verbose(t_vm *vm, t_process *process)
{
    int		i;

    i = -1;
    if (!vm->verbose)
        return ;
    my_printf("P %4d | %s", process->id + 1, OP_TAB.mnemonique);
    while (++i < OP_TAB.nbr_args)
    {
        my_putchar(' ');
        if (process->param_type[i] == 1)
            my_print_reg(process, i);
        else if ((process->param_type[i] == 3) &&
                 process->instruction != 0)
            my_print_ind(vm, process, i);
        else
            my_printf("%d", (int)process->param[i]);
    }
}
