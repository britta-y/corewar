/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** vm
*/

#include <vm.h>

void		my_print_winner(t_vm *vm)
{
    t_list		*champions;
    t_process	*champ;

    champions = vm->champions;
    if (vm->last_live == 0)
    {
        champ = champions->content;
        my_printf("Contestant %d, \"%s\", has won !\n",
            my_ABS(champ->id_champ), champ->header.prog_name);
        return ;
    }
    while (champions)
    {
        champ = champions->content;
        if (vm->last_live == champ->id_champ)
        {
            my_printf("Contestant %d, \"%s\", has won !\n",
                my_ABS(champ->id_champ), champ->header.prog_name);
            return ;
        }
        champions = champions->next;
    }
}

static void	my_introduce_contestants(t_list *champs)
{
    t_process	*act;

    act = champs->content;
    if (champs->next)
        my_introduce_contestants(champs->next);
    my_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
        my_ABS(act->id_champ), act->header.prog_size, act->header.prog_name,
        act->header.comment);
}

int			main(int ac, char **av)
{
    t_vm	*vm;

    if ((vm = (t_vm *)malloc(sizeof(t_vm))))
    {
        my_init_vm(vm);
        init_tab_instruction(vm);
        my_treat_args(ac, av, vm);
        my_prepare_memory(vm);
        vm->nb_process = vm->nb_champ;
        my_launch_vm(vm);
    }
    else
        my_exit_malloc_error();
    my_print_winner(vm);
    my_kill_vm(vm);
    return (1);
}