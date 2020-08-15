/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** load
*/

#include <vm.h>

int		my_load(t_vm *vm, int size, int adress)
{
    int		param;

    param = 0;
    while (adress < 0)
        adress += MEM_SIZE;
    if (size == 1)
        param = vm->memory[(adress) % MEM_SIZE];
    else if (size == 2)
    {
        param = ((vm->memory[(adress + 1) % MEM_SIZE]));
        param |= ((vm->memory[(adress + 0) % MEM_SIZE]) << 8);
    }
    else
    {
        param = ((vm->memory[(adress + 3) % MEM_SIZE]));
        param |= ((vm->memory[(adress + 2) % MEM_SIZE]) << 8);
        param |= ((vm->memory[(adress + 1) % MEM_SIZE]) << 16);
        param |= ((vm->memory[(adress + 0) % MEM_SIZE]) << 24);
    }
    return (param);
}