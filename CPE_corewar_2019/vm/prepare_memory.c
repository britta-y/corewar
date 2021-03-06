/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** prepare_memory
*/

#include <vm.h>

static int		my_load_champ(t_vm *vm, t_process *process, int index,
    int current_champ)
{
    unsigned int		size;

    size = 0;
    process->pc = index;
    while (size < process->header.prog_size && size + index < MEM_SIZE)
    {
        vm->memory[(index + size) % MEM_SIZE] = process->prog[size];
        vm->mem_color[(index + size) % MEM_SIZE] =
            (unsigned char)current_champ + 1;
        size++;
    }
    return (process->header.prog_size);
}

static void		my_load_memory(t_vm *vm, int spacing, t_list *processes)
{
    int			current_champ;
    int			index;
    int			offset_next_champ;

    offset_next_champ = spacing;
    current_champ = 0;
    index = 0;
    my_memset(vm->mem_color, -1, MEM_SIZE);
    while (current_champ < vm->nb_champ)
    {
        index += my_load_champ(vm, processes->content, index, current_champ);
        while (index < offset_next_champ && index < MEM_SIZE)
            vm->memory[(index++) % MEM_SIZE] = 0;
        offset_next_champ += spacing;
        processes = processes->next;
        current_champ++;
    }
}

static t_list	*my_reverse_processes(t_list *processes)
{
    t_list	*revert;
    t_list	*last;
    t_list	*tmp;

    tmp = processes;
    last = NULL;
    while (tmp != NULL)
    {
        if ((revert = (t_list*)malloc(sizeof(t_list))) == NULL)
            my_exit_malloc_error();
        revert->content = tmp->content;
        revert->next = NULL;
        if (last != NULL)
            revert->next = last;
        last = revert;
        tmp = tmp->next;
    }
    return (revert);
}

void			my_prepare_memory(t_vm *vm)
{
    int			spacing;
    t_list		*processes;
    t_list		*prev;

    if (!vm->nb_champ)
        my_exit_msg("No champions");
    spacing = (MEM_SIZE) / vm->nb_champ;
    processes = my_reverse_processes(vm->processes);
    my_load_memory(vm, spacing, processes);
    while (processes)
    {
        prev = processes;
        processes = processes->next;
        free(prev);
    }
}