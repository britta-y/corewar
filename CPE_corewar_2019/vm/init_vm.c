/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** init_vm
*/

#include <vm.h>

void		my_init_vm(t_vm *vm)
{
    vm->dump = -1;
    vm->processes = NULL;
    vm->champions = NULL;
    vm->nb_champ = 0;
    vm->verbose = 0;
    vm->aff = 0;
    vm->cycle_to_die = CYCLE_TO_DIE;
    vm->total_cycles = 1;
    vm->cycles = 1;
    vm->live = 0;
    vm->last_live = 0;
    vm->ctd_decrem = 0;
    vm->aff = 0;
    vm->nb_checks = 0;
    vm->sleep = 10000;
}

void		my_init_process(t_process *process)
{
    process->id_champ = process->reg[0];
    process->nb_live = 0;
}

void		init_tab_instruction(t_vm *vm)
{
    vm->f[0] = my_live;
    vm->f[1] = my_ld;
    vm->f[2] = my_st;
    vm->f[3] = my_add;
    vm->f[4] = my_sub;
    vm->f[5] = my_and;
    vm->f[6] = my_or;
    vm->f[7] = my_xor;
    vm->f[8] = my_zjmp;
    vm->f[9] = my_ldi;
    vm->f[10] = my_sti;
    vm->f[11] = my_fork;
    vm->f[12] = my_lld;
    vm->f[13] = my_lldi;
    vm->f[14] = my_lfork;
    vm->f[15] = my_aff;
}