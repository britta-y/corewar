/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** vm_virtual_foam_bat
*/

#include <vm.h>

void	my_murder_with_foam_bat(t_list **prey)
{
    (void)prey;
    free((*prey)->content);
    (*prey)->content = NULL;
    free(*prey);
    *prey = NULL;
}

void	my_savage_slaughter(t_vm *vm, t_list *prev_process,
                            t_list *current_process)
{
    if (prev_process)
        prev_process->next = current_process->next;
    else
        vm->processes = current_process->next;
    my_murder_with_foam_bat(&current_process);
}