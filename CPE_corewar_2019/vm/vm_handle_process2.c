/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** vm_handle_process2
*/

#include <vm.h>

static void	my_getparamtype(t_vm *vm, t_process *process)
{
    process->param_type[0] =
        ((unsigned char)(vm->memory[process->pc2 % MEM_SIZE]) >> 6);
    process->param_type[1] =
        ((unsigned char)(vm->memory[process->pc2 % MEM_SIZE] & 0x30) >> 4);
    process->param_type[2] =
        ((unsigned char)(vm->memory[process->pc2 % MEM_SIZE] & 0xC) >> 2);
}

int			my_get_ocp(t_vm *vm, t_process *process)
{
    int		i;
    int		adv;
    int		ok;

    i = -1;
    adv = 2;
    ok = 1;
    process->ocp = *(vm->memory + process->pc2 % MEM_SIZE);
    my_getparamtype(vm, process);
    while (++i < OP_TAB.nbr_args)
    {
        if (!my_check_param(process, i))
            ok = 0;
        if (process->param_type[i] == T_IND ||
            process->param_type[i] == T_DIR)
            adv += IND_SIZE;
        else if (process->param_type[i] == T_DIR)
            adv += DIR_SIZE;
        else if (process->param_type[i] == T_REG)
            adv += 1;
    }
    return (ok ? 1 : adv);
}

void		my_get_instruction(t_vm *vm, t_process *process)
{
    if (vm->memory[process->pc % MEM_SIZE] >= 1 &&
            vm->memory[process->pc % MEM_SIZE] <= 16)
    {
        process->instruction = vm->memory[process->pc % MEM_SIZE] - 1;
        process->cycle_bf_exe = OP_TAB.nbr_cycles - 1;
    }
    else
    {
        process->pc2 = process->pc + 1;
        process->pc = process->pc2;
    }
}/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** vm_handle_process2
*/

#include <vm.h>

static void	my_getparamtype(t_vm *vm, t_process *process)
{
    process->param_type[0] =
        ((unsigned char)(vm->memory[process->pc2 % MEM_SIZE]) >> 6);
    process->param_type[1] =
        ((unsigned char)(vm->memory[process->pc2 % MEM_SIZE] & 0x30) >> 4);
    process->param_type[2] =
        ((unsigned char)(vm->memory[process->pc2 % MEM_SIZE] & 0xC) >> 2);
}

int			my_get_ocp(t_vm *vm, t_process *process)
{
    int		i;
    int		adv;
    int		ok;

    i = -1;
    adv = 2;
    ok = 1;
    process->ocp = *(vm->memory + process->pc2 % MEM_SIZE);
    my_getparamtype(vm, process);
    while (++i < OP_TAB.nbr_args)
    {
        if (!my_check_param(process, i))
            ok = 0;
        if (process->param_type[i] == T_IND ||
            process->param_type[i] == T_DIR)
            adv += IND_SIZE;
        else if (process->param_type[i] == T_DIR)
            adv += DIR_SIZE;
        else if (process->param_type[i] == T_REG)
            adv += 1;
    }
    return (ok ? 1 : adv);
}

void		my_get_instruction(t_vm *vm, t_process *process)
{
    if (vm->memory[process->pc % MEM_SIZE] >= 1 &&
            vm->memory[process->pc % MEM_SIZE] <= 16)
    {
        process->instruction = vm->memory[process->pc % MEM_SIZE] - 1;
        process->cycle_bf_exe = OP_TAB.nbr_cycles - 1;
    }
    else
    {
        process->pc2 = process->pc + 1;
        process->pc = process->pc2;
    }
}