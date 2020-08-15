/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** vm_handle_process
*/

#include <vm.h>

void	my_get_all_param(t_vm *vm, t_process *process)
{
    int		i;

    i = 0;
    while (i < OP_TAB.nbr_args)
    {
        if (process->param_type[i] == 2)
        {
            process->param[i] = my_load(vm, 4, process->pc2);
            process->pc2 += 4;
        }
        else if (process->param_type[i] == 1)
        {
            process->param[i] = (unsigned char)my_load(vm, 1, process->pc2);
            process->pc2 += 1;
        }
        else
        {
            process->param[i] = (short)my_load(vm, 2, process->pc2);
            process->pc2 += 2;
        }
        i++;
    }
}

int		my_check_param(t_process *process, int i)
{
    if (process->param_type[i] == T_REG)
        return (OP_TAB.type[i] & T_REG ? 1 : 0);
    else if (process->param_type[i] == T_DIR)
        return (OP_TAB.type[i] & T_DIR ? 1 : 0);
    else if (process->param_type[i] == T_IND)
        return (OP_TAB.type[i] & T_IND ? 1 : 0);
    else if (process->param_type[i] == 0)
        return (0);
    return (1);
}

int		my_get_params(t_vm *vm, t_process *process)
{
    int		adv;

    process->pc2 = process->pc + 1;
    if (OP_TAB.nbr_cycles)
    {
        if ((adv = my_get_ocp(vm, process)) > 1)
            return (adv);
    }
    process->pc2++;
    my_get_all_param(vm, process);
    return (1);
}

void	my_print_invalid_ocp(t_vm *vm, t_process *process, int adv)
{
    int		idx;

    if (!vm->verbose)
        return ;
    idx = 2;
    my_printf("ADV %d (%.4p -> %.4p) %.2x %.2x ", adv, process->pc,
        process->pc + adv, vm->memory[(process->pc) % MEM_SIZE],
        vm->memory[(process->pc + 1) % MEM_SIZE]);
    while (idx < adv)
    {
        my_printf("%.2x ", vm->memory[(process->pc + idx) % MEM_SIZE]);
        idx++;
    }
    my_putchar('\n');
}

void	my_handle_process(t_vm *vm, t_process *process)
{
    int		adv;

    if (--process->cycle_bf_exe == 0)
    {
        if ((adv = my_get_params(vm, process)) > 1)
        {
            my_print_invalid_ocp(vm, process, adv);
            process->pc += adv;
        }
        else
        {
            vm->f[(int)process->instruction](vm, process);
            process->pc = process->pc2;
        }
        process->instruction = -1;
    }
    else if (process->instruction == -1)
        my_get_instruction(vm, process);
}