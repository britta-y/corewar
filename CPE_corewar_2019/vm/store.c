/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** store
*/

#include <vm.h>

void	my_store(t_vm *vm, t_process *process, int adress)
{
    int value;

    value = process->reg[process->param[0] - 1];
    if (adress < 0)
        adress = MEM_SIZE + adress;
    vm->memory[(adress + 3) % MEM_SIZE] = value;
    vm->memory[(adress + 2) % MEM_SIZE] = (value >> 8);
    vm->memory[(adress + 1) % MEM_SIZE] = (value >> 16);
    vm->memory[(adress + 0) % MEM_SIZE] = (value >> 24);
    vm->mem_color[adress % MEM_SIZE] = process->color + 1;
    vm->mem_color[(adress + 1) % MEM_SIZE] = process->color + 1;
    vm->mem_color[(adress + 2) % MEM_SIZE] = process->color + 1;
    vm->mem_color[(adress + 3) % MEM_SIZE] = process->color + 1;
}