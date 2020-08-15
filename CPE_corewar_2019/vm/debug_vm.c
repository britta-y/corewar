/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** debug_vm
*/

#include <vm.h>

void		deb_print_process(t_list *processes)
{
    unsigned int	i;
    t_process		*process;

    while (processes)
    {
        process = processes->content;
        my_printf("magic : %#x\nprogname : %s\nprog_size : %#x\ncomment : %s\n",
            process->header.magic, process->header.prog_name,
            process->header.prog_size, process->header.comment);
        my_printf("nb : %d\nid : %d\n", process->reg[0], process->id);
        my_printf("prog :\n");
        i = 0;
        while (i < process->header.prog_size)
        {
            if (i % 16 == 0 && i != 0)
                my_printf("\n");
            else if (i % 8 == 0 && i != 0)
                my_printf(" ");
            my_printf("%.2x ", (unsigned char)(process->prog[i]));
            i++;
        }
        my_putchar('\n');
        processes = processes->next;
    }
}

void		deb_print_memory(t_vm *vm)
{
    int		i;
    int		offset;

    i = -1;
    offset = 0;
    while (++i < MEM_SIZE)
    {
        if (i % 64 == 0)
        {
            offset == 0 ? my_printf("0x%#.4x : ", offset) :
                my_printf("\n%#.4x : ", offset);
            offset += 64;
        }
        if (vm->color && vm->mem_color[i] == 0)
            my_printf("%[g,B]T%.2x %[0]T", (unsigned char)vm->memory[i]);
        else if (vm->color && vm->mem_color[i] == 1)
            my_printf("%[b,B]T%.2x %[0]T", (unsigned char)vm->memory[i]);
        else if (vm->color && vm->mem_color[i] == 2)
            my_printf("%[r,B]T%.2x %[0]T", (unsigned char)vm->memory[i]);
        else if (vm->color && vm->mem_color[i] == 3)
            my_printf("%[c,B]T%.2x %[0]T", (unsigned char)vm->memory[i]);
        else
            my_printf("%.2x ", (unsigned char)vm->memory[i]);
    }
    my_printf("\n");
}